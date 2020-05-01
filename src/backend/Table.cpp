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