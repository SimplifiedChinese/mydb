#ifndef __TABLE_H__
#define __TABLE_H__

#include "../constants.h"
#include "Compare.h"
#include <cstring>
#include <cassert>

struct TableHead {
    int8_t columnTot, primaryCount, checkTot, foreignKeyTot;
    int pageTot, recordByte, dataArrUsed;
    unsigned int nextAvail, notNull, hasIndex, isPrimary;

    char columnName[MAX_COLUMN_SIZE][MAX_NAME_LEN];
    int columnOffset[MAX_COLUMN_SIZE];
    ColumnType columnType[MAX_COLUMN_SIZE];
    int columnLen[MAX_COLUMN_SIZE];
    int defaultOffset[MAX_COLUMN_SIZE];
    char dataArr[MAX_DATA_SIZE];
};

class Table {
    friend class Database;

    TableHead head;
    bool ready;
    int fileID, permID;
    char *buf;
    std::string tableName;

public:
	Table() { ready = false; }
	~Table() { if (ready) close(); }
	void create(const char *table_name);
	void open(const char *table_name);
	void drop();
	void close();

    // 需要修改表的结构，这是增加列
	int addColumn(const char *name, ColumnType type, int size,
                  bool notNull, bool hasDefault, const char *data);
    
    // 打印表信息
    void printSchema();

    // 重要的get操作在这里，直接在头文件中声明和定义
    int getColumnCount(){return head.columnTot;}
    int getColumnID(const char *name){
        for (int i = 1; i < head.columnTot; i++)
            if (strcmp(head.columnName[i], name) == 0)
                return i;
        return -1;}
    ColumnType getColumnType(int col) {return head.columnType[col];}
    int getColumnOffset(int col) {return head.columnOffset[col];}
    int getFooter(const char *page, int idx) {
        int u = idx / 32;
        int v = idx % 32;
        unsigned int tmp = *(unsigned int *) (page + PAGE_SIZE - PAGE_FOOTER_SIZE + u * 4);
        return (tmp >> v) & 1;
    }
    char *getRecordTempPtr(RID_t rid);
    RID_t getNext(RID_t rid);
    std::string getTableName() {
        assert(ready);
        return tableName;
    }
    char *getColumnName(int col) {
        assert(0 <= col && col < head.columnTot);
        return head.columnName[col];
    }

    // 和temprecord有关的操作，和缓存有关
    void initTempRecord();
    std::string setTempRecord(int col, const char *data);
    void setTempRecordNull(int col);
    std::string insertTempRecord();
    void clearTempRecord(){
        if (buf == nullptr) {
            buf = new char[head.recordByte];
            initTempRecord();
        }
    }
    std::string checkRecord();
    void dropRecord(RID_t rid);
    std::string modifyRecord(RID_t rid, int col, char *data);
    std::string modifyRecordNull(RID_t rid, int col);
    std::string loadRecordToTemp(RID_t rid, char *page, int offset);

    void allocPage();    
    void inverseFooter(const char *page, int idx);
    char *select(RID_t rid, int col);
};

#endif
