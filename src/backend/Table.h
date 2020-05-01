#ifndef __TABLE_H__
#define __TABLE_H__

#include "../constants.h"
#include "Compare.h"
#include <cstring>

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
	int addColumn(const char *name, ColumnType type, int size,
                  bool notNull, bool hasDefault, const char *data);
    void printSchema();

    int getColumnCount(){return head.columnTot;}
    int getColumnID(const char *name){
        for (int i = 1; i < head.columnTot; i++)
            if (strcmp(head.columnName[i], name) == 0)
                return i;
        return -1;}
    void clearTempRecord(){
        if (buf == nullptr) {
            buf = new char[head.recordByte];
            initTempRecord();
        }}
    ColumnType getColumnType(int col) {return head.columnType[col];}

    void initTempRecord();
    std::string setTempRecord(int col, const char *data);
    void setTempRecordNull(int col);
    std::string insertTempRecord();
    // std::string modifyRecord(RID_t rid, int col, char *data);
    // void dropRecord(RID_t rid);
    void allocPage();
    std::string checkRecord();
    void inverseFooter(const char *page, int idx);
};

#endif
