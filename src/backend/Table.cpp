#include <cstring>
#include <string>
#include <sstream>
#include <dbms/DBMS.h>

#include "../io/FileManager.h"
#include "../io/BufPageManager.h"
#include "RegisterManager.h"

void Table::create(const char *tableName) {
    assert(!ready);
    this->tableName = std::string(tableName);
    BufPageManager::getFileManager().createFile(tableName);
    fileID = BufPageManager::getFileManager().openFile(tableName);
    permID = BufPageManager::getFileManager().getFilePermID(fileID);
    BufPageManager::getInstance().allocPage(fileID, 0);
    RegisterManager::getInstance().checkIn(permID, this);
    ready = true;
    head.pageTot = 1;
    head.recordByte = 4; // reserve first 4 bytes for notnull info
    //head.rowTot = 0;
    head.columnTot = 0;
    head.dataArrUsed = 0;
    head.nextAvail = (unsigned int) -1;
    head.notNull = 0;
    head.checkTot = 0;
    head.foreignKeyTot = 0;
    head.primaryCount = 0;
    addColumn("RID", CT_INT, 10, true, false, nullptr);
    buf = nullptr;
}

void Table::open(const char *tableName) {
    assert(ready == 0);
    this->tableName = std::string(tableName);
    fileID = BufPageManager::getFileManager().openFile(tableName);
    permID = BufPageManager::getFileManager().getFilePermID(fileID);
    RegisterManager::getInstance().checkIn(permID, this);
    int index = BufPageManager::getInstance().getPage(fileID, 0);
    memcpy(&head, BufPageManager::getInstance().access(index), sizeof(TableHead));
    ready = true;
    buf = nullptr;
}

void Table::drop() {
    assert(ready == 1);
    RegisterManager::getInstance().checkOut(permID);
    BufPageManager::getInstance().closeFile(fileID, false);
    BufPageManager::getFileManager().closeFile(fileID);
    ready = false;
}

void Table::close() {
    assert(ready);
    int index = BufPageManager::getInstance().getPage(fileID, 0);
    memcpy(BufPageManager::getInstance().access(index), &head, sizeof(TableHead));
    BufPageManager::getInstance().markDirty(index);
    RegisterManager::getInstance().checkOut(permID);
    BufPageManager::getInstance().closeFile(fileID);
    BufPageManager::getFileManager().closeFile(fileID);
    ready = false;
    if (buf) {
        delete[] buf;
        buf = 0;
    }
}

int Table::addColumn(const char *name, ColumnType type, int size,
                     bool notNull, bool hasDefault, const char *data) {
    printf("adding %s %d %d\n", name, type, size);
    assert(head.pageTot == 1);
    assert(strlen(name) < MAX_NAME_LEN);
    for (int i = 0; i < head.columnTot; i++)
        if (strcmp(head.columnName[i], name) == 0)
            return -1;
    assert(head.columnTot < MAX_COLUMN_SIZE);
    int id = head.columnTot++;
    strcpy(head.columnName[id], name);
    head.columnType[id] = type;
    head.columnOffset[id] = head.recordByte;
    head.columnLen[id] = size;
    if (notNull) head.notNull |= (1 << id);
    head.defaultOffset[id] = -1;
    switch (type) {
        case CT_INT:
        case CT_FLOAT:
        case CT_DATE:
            head.recordByte += 4;
            if (hasDefault) {
                head.defaultOffset[id] = head.dataArrUsed;
                memcpy(head.dataArr + head.dataArrUsed, data, 4);
                head.dataArrUsed += 4;
            }
            break;
        case CT_VARCHAR:
            head.recordByte += size + 1;
            head.recordByte += 4 - head.recordByte % 4;
            if (hasDefault) {
                head.defaultOffset[id] = head.dataArrUsed;
                strcpy(head.dataArr + head.dataArrUsed, data);
                head.dataArrUsed += strlen(data) + 1;
            }
            break;
        default:
            assert(0);
    }
    assert(head.dataArrUsed <= MAX_DATA_SIZE);
    assert(head.recordByte <= PAGE_SIZE);
    return id;
}

void Table::printSchema() {
    for (int i = 1; i < head.columnTot; i++) {
        printf("%s", head.columnName[i]);
        switch (head.columnType[i]) {
            case CT_INT:
                printf(" INT(%d)", head.columnLen[i]);
                break;
            case CT_FLOAT:
                printf(" FLOAT");
                break;
            case CT_DATE:
                printf(" DATE");
                break;
            case CT_VARCHAR:
                printf(" VARCHAR(%d)", head.columnLen[i]);
                break;
            default:
                assert(0);
        }
        if (head.notNull & (1 << i)) printf(" NotNull");
        if (head.hasIndex & (1 << i)) printf(" Indexed");
        if (head.isPrimary & (1 << i)) printf(" Primary");
        printf("\n");
    }
}

void Table::initTempRecord() {
    unsigned int &notNull = *(unsigned int *) buf;
    notNull = 0;
    for (int i = 0; i < head.columnTot; i++) {
        if (head.defaultOffset[i] != -1) {
            switch (head.columnType[i]) {
                case CT_INT:
                case CT_FLOAT:
                case CT_DATE:
                    memcpy(buf + head.columnOffset[i], head.dataArr + head.defaultOffset[i], 4);
                    break;
                case CT_VARCHAR:
                    strcpy(buf + head.columnOffset[i], head.dataArr + head.defaultOffset[i]);
                    break;
                default:
                    assert(false);
            }
            notNull |= (1u << i);
        }
    }
}

std::string Table::setTempRecord(int col, const char *data) {
    if (data == nullptr) {
        setTempRecordNull(col);
        return "";
    }
    if (buf == nullptr) {
        buf = new char[head.recordByte];
        initTempRecord();
    }
    unsigned int &notNull = *(unsigned int *) buf;
    switch (head.columnType[col]) {
        case CT_INT:
        case CT_DATE:
        case CT_FLOAT:
            memcpy(buf + head.columnOffset[col], data, 4);
            break;
        case CT_VARCHAR:
            if ((unsigned int) head.columnLen[col] < strlen(data)) {
                printf("%d %s\n", head.columnLen[col], data);
            }
            if (strlen(data) > (unsigned int) head.columnLen[col]) {
                return "ERROR: varchar too long";
            }
            strcpy(buf + head.columnOffset[col], data);
            break;
        default:
            assert(0);
    }
    notNull |= (1u << col);
    return "";
}

void Table::setTempRecordNull(int col) {
    if (buf == nullptr) {
        buf = new char[head.recordByte];
        initTempRecord();
    }
    unsigned int &notNull = *(unsigned int *) buf;
    if (notNull & (1u << col)) notNull ^= (1u << col);
}

std::string Table::insertTempRecord() {
    assert(buf != nullptr);
    if (head.nextAvail == (RID_t) -1) {
        allocPage();
    }
    int rid = head.nextAvail;
    setTempRecord(0, (char *) &head.nextAvail);
    auto error = checkRecord();
    if (!error.empty()) {
        printf("Error occurred when inserting record, aborting...\n");
        return error;
    }
    int pageID = head.nextAvail / PAGE_SIZE;
    int offset = head.nextAvail % PAGE_SIZE;
    int index = BufPageManager::getInstance().getPage(fileID, pageID);
    char *page = BufPageManager::getInstance().access(index);
    head.nextAvail = *(unsigned int *) (page + offset);
    memcpy(page + offset, buf, head.recordByte);
    BufPageManager::getInstance().markDirty(index);
    inverseFooter(page, offset / head.recordByte);
    return "";
}

void Table::allocPage() {
    auto index = BufPageManager::getInstance().allocPage(fileID, head.pageTot);
    auto buf = BufPageManager::getInstance().access(index);
    auto n = (PAGE_SIZE - PAGE_FOOTER_SIZE) / head.recordByte;
    n = (n < MAX_REC_PER_PAGE) ? n : MAX_REC_PER_PAGE;
    for (int i = 0, p = 0; i < n; i++, p += head.recordByte) {
        unsigned int &ptr = *(unsigned int *) (buf + p);
        ptr = head.nextAvail;
        head.nextAvail = (unsigned int) head.pageTot * PAGE_SIZE + p;
    }
    memset(buf + PAGE_SIZE - PAGE_FOOTER_SIZE, 0, PAGE_FOOTER_SIZE);
    BufPageManager::getInstance().markDirty(index);
    head.pageTot++;
}

std::string Table::checkRecord() {
    // 检查就简化一点点

    // unsigned int &notNull = *(unsigned int *) buf;
    // if ((notNull & head.notNull) != head.notNull) {
    //     return "Insert Error: not null column is null.";
    // }

    // if (!initMode) {
    //     if (!checkPrimary()) {
    //         return "ERROR: Primary Key Conflict";
    //     }
    //     auto valueCheck = checkValueConstraint();
    //     if (!valueCheck.empty()) {
    //         return valueCheck;
    //     }

    //     auto foreignKeyCheck = checkForeignKeyConstraint();
    //     if (!foreignKeyCheck.empty()) {
    //         return foreignKeyCheck;
    //     }
    // }

    return std::string();
}

void Table::dropRecord(RID_t rid) {
    int pageID = rid / PAGE_SIZE;
    int offset = rid % PAGE_SIZE;
    for (int i = 0; i < head.columnTot; i++) {
        // if (head.hasIndex & (1 << i)) eraseColIndex(rid, i);
    }
    int index = BufPageManager::getInstance().getPage(fileID, pageID);
    char *page = BufPageManager::getInstance().access(index);
    char *record = page + offset;
    unsigned int &next = *(unsigned int *) record;
    next = head.nextAvail;
    head.nextAvail = rid;
    inverseFooter(page, offset / head.recordByte);
    BufPageManager::getInstance().markDirty(index);
}

void Table::inverseFooter(const char *page, int idx) {
    int u = idx / 32;
    int v = idx % 32;
    unsigned int &tmp = *(unsigned int *) (page + PAGE_SIZE - PAGE_FOOTER_SIZE + u * 4);
    tmp ^= (1u << v);
}

RID_t Table::getNext(RID_t rid) {
    int page_id, id, n;
    n = (PAGE_SIZE - PAGE_FOOTER_SIZE) / head.recordByte;
    n = (n < MAX_REC_PER_PAGE) ? n : MAX_REC_PER_PAGE;
    if (rid == (RID_t) -1) {
        page_id = 0;
        id = n - 1;
    } else {
        page_id = rid / PAGE_SIZE;
        id = (rid % PAGE_SIZE) / head.recordByte;
    }
    int index = BufPageManager::getInstance().getPage(fileID, page_id);
    char *page = BufPageManager::getInstance().access(index);

    while (true) {
        id++;
        if (id == n) {
            page_id++;
            if (page_id >= head.pageTot) return (RID_t) -1;
            index = BufPageManager::getInstance().getPage(fileID, page_id);
            page = BufPageManager::getInstance().access(index);
            id = 0;
        }
        if (getFooter(page, id)) return (RID_t) page_id * PAGE_SIZE + id * head.recordByte;
    }
}

char *Table::getRecordTempPtr(RID_t rid) {
    int pageID = rid / PAGE_SIZE;
    int offset = rid % PAGE_SIZE;
    assert(1 <= pageID && pageID < head.pageTot);
    auto index = BufPageManager::getInstance().getPage(fileID, pageID);
    auto page = BufPageManager::getInstance().access(index);
    assert(getFooter(page, offset / head.recordByte));
    return page + offset;
}

char *Table::select(RID_t rid, int col) {
    char *ptr;
    if (rid != (RID_t) -1) {
        ptr = getRecordTempPtr(rid);
    } else {
        ptr = buf;
    }
    unsigned int &notNull = *(unsigned int *) ptr;
    char *buf;
    if ((~notNull) & (1 << col)) {
        return nullptr;
    }
    switch (head.columnType[col]) {
        case CT_INT:
        case CT_DATE:
        case CT_FLOAT:
            buf = new char[4];
            memcpy(buf, ptr + getColumnOffset(col), 4);
            return buf;
        case CT_VARCHAR:
            buf = new char[head.columnLen[col] + 1];
            strcpy(buf, ptr + getColumnOffset(col));
            return buf;
        default:
            assert(0);
    }
}

std::string Table::modifyRecord(RID_t rid, int col, char *data) {
    if (data == nullptr) {
        return modifyRecordNull(rid, col);
    }
    int pageID = rid / PAGE_SIZE;
    int offset = rid % PAGE_SIZE;
    int index = BufPageManager::getInstance().getPage(fileID, pageID);
    char *page = BufPageManager::getInstance().access(index);
    char *record = page + offset;
    std::string err = loadRecordToTemp(rid, page, offset);
    if (!err.empty()) {
        return err;
    }
    assert(col != 0);
    err = setTempRecord(col, data);
    if (!err.empty()) {
        return err;
    }
    err = checkRecord();
    if (!err.empty()) {
        return err;
    }
    // eraseColIndex(rid, col);
    memcpy(record, buf, head.recordByte);
    BufPageManager::getInstance().markDirty(index);
    // insertColIndex(rid, col);
    return "";
}

std::string Table::modifyRecordNull(RID_t rid, int col) {
    int pageID = rid / PAGE_SIZE;
    int offset = rid % PAGE_SIZE;
    int index = BufPageManager::getInstance().getPage(fileID, pageID);
    char *page = BufPageManager::getInstance().access(index);
    char *record = page + offset;
    std::string err = loadRecordToTemp(rid, page, offset);
    if (!err.empty()) {
        return err;
    }
    assert(col != 0);
    setTempRecordNull(col);
    err = checkRecord();
    if (!err.empty()) {
        return err;
    }
    // eraseColIndex(rid, col);
    memcpy(record, buf, head.recordByte);
    BufPageManager::getInstance().markDirty(index);
    // insertColIndex(rid, col);
    return "";
}

std::string Table::loadRecordToTemp(RID_t rid, char *page, int offset) {
    UNUSED(rid);
    if (buf == nullptr) {
        buf = new char[head.recordByte];
    }
    char *record = page + offset;
    if (!getFooter(page, offset / head.recordByte)) {
        return "ERROR: RID invalid";
    }
    memcpy(buf, record, (size_t) head.recordByte);
    return "";
}

void Table::createIndex(int col) {
    //assert(head.pageTot == 1);
    assert((head.hasIndex & (1 << col)) == 0);
    head.hasIndex |= 1 << col;
}

void Table::dropIndex(int col) {
    assert((head.hasIndex & (1 << col)));
    head.hasIndex &= ~(1 << col);
    colIndex[col].drop(permID, col);
}

int Table::getFastCmp(RID_t rid, int col) {
    char *p = select(rid, col);
    if (p == nullptr) return 0;
    int res = 0;
    float tmp;
    switch (head.columnType[col]) {
        case CT_INT:
        case CT_DATE:
            res = *(int *) p;
            break;
        case CT_FLOAT:
            tmp = *(float *) p;
            if (tmp > 2e9)
                res = (int) 2e9;
            else if (tmp < -2e9)
                res = (int) -2e9;
            else
                res = (int) tmp;
            break;
        case CT_VARCHAR:
            res = 0;
            for (size_t i = 0; i < 4; i++) {
                res = res * 256;
                if (i < strlen(p)) res += i;
            }
            break;
        default:
            assert(false);
    }
    delete[] p;
    return res;
}

bool Table::getIsNull(RID_t rid, int col) {
    char *p = select(rid, col);
    delete[] p;
    return p == nullptr;
}

RID_t Table::selectIndexLowerBound(int col, const char *data) {
    if (data == nullptr) {
        return selectIndexLowerBoundNull(col);
    }
    assert(hasIndex(col));
    setTempRecord(col, data);
    return colIndex[col].lowerBound(IndexKey(permID, -1, col, getFastCmp(-1, col), getIsNull(-1, col)));
}

RID_t Table::selectIndexLowerBoundEqual(int col, const char *data) {
    if (data == nullptr) {
        return selectIndexLowerBoundNull(col);
    }
    assert(hasIndex(col));
    setTempRecord(col, data);
    return colIndex[col].lowerBoundEqual(IndexKey(permID, -1, col, getFastCmp(-1, col), getIsNull(-1, col)));
}

RID_t Table::selectIndexLowerBoundNull(int col) {
    assert(hasIndex(col));
    return colIndex[col].begin();
}

RID_t Table::selectIndexNext(int col) {
    assert(hasIndex(col));
    return colIndex[col].next();
}

RID_t Table::selectIndexNextEqual(int col) {
    assert(hasIndex(col));
    return colIndex[col].nextEqual(IndexKey(permID, -1, col, getFastCmp(-1, col), getIsNull(-1, col)));
}

RID_t Table::selectIndexUpperBound(int col, const char *data) {
    if (data == nullptr) {
        return selectIndexUpperBoundNull(col);
    }
    assert(hasIndex(col));
    setTempRecord(col, data);
    return colIndex[col].upperBound(IndexKey(permID, -1, col, getFastCmp(-1, col), getIsNull(-1, col)));
}

RID_t Table::selectIndexUpperBoundNull(int col) {
    assert(hasIndex(col));
    return colIndex[col].end();
}

RID_t Table::selectReveredIndexNext(int col) {
    assert(hasIndex(col));
    return colIndex[col].reversedNext();
}

