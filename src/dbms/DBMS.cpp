//
// Created by Harry Chen on 2017/11/26.
//

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <sql_parser/Expression.h>

#include "DBMS.h"

DBMS::DBMS() {
    current = new Database();
}

bool DBMS::requireDbOpen() {
    if (!current->isOpen()) {
        printf("%s\n", "Please USE database first!");
        return false;
    }
    return true;
}

DBMS *DBMS::getInstance() {
    static DBMS *instance;
    if (!instance)
        instance = new DBMS;
    return instance;
}

void DBMS::exit() {
    if (current->isOpen())
        current->close();
}

void DBMS::switchToDB(const char *name) {
    if (current->isOpen())
        current->close();

    current->open(name);
}

void DBMS::createTable(const table_def *table) {
    if (!requireDbOpen())
        return;
    assert(table->name != NULL);
    if (current->getTableByName(table->name)) {
        printf("Table `%s` already exists\n", table->name);
        return;
    }
    Table *tab = current->createTable(table->name);
    std::vector<column_defs *> column_rev;
    column_defs *column = table->columns;
    bool succeed = true;
    for (; column; column = column->next) {
        column_rev.push_back(column);
    }
    for (auto i = column_rev.rbegin(); i != column_rev.rend(); ++i) {
        auto type = (ColumnType) 0;
        column = *i;
        switch (column->type) {
            case COLUMN_TYPE_INT:
                type = CT_INT;
                break;
            case COLUMN_TYPE_VARCHAR:
                type = CT_VARCHAR;
                break;
            case COLUMN_TYPE_FLOAT:
                type = CT_FLOAT;
                break;
            case COLUMN_TYPE_DATE:
                type = CT_DATE;
                break;
            default:
                assert(false);
                break;
        }
        int ret = tab->addColumn(column->name, type, column->size,
                                 (bool) column->flags & COLUMN_FLAG_NOTNULL,
                                 (bool) column->flags & COLUMN_FLAG_DEFAULT,
                                 nullptr);
        if (ret == -1) {
            printf("Column %s duplicated\n", column->name);
            succeed = false;
            break;
        }
    }
    if (!succeed)
        current->dropTableByName(table->name);
    else {
        printf("Table %s created\n", table->name);
    }
}

void DBMS::dropDB(const char *db_name) {
    Database db;
    if (current->isOpen() && current->getDBName() == db_name)
        current->close();
    db.open(db_name);
    if (db.isOpen()) {
        db.drop();
        printf("Database %s dropped!\n", db_name);
    } else {
        printf("Failed to open database %s\n", db_name);
    }
}

void DBMS::dropTable(const char *table) {
    if (!requireDbOpen())
        return;
    current->dropTableByName(table);
    printf("Table %s dropped!\n", table);
}

void DBMS::listTables() {
    if (!requireDbOpen())
        return;
    const std::vector<std::string> &tables =
            current->getTableNames();
    printf("List of tables:\n");
    for (const auto &table : tables) {
        printf("%s\n", table.c_str());
    }
    printf("==========\n");
}

void DBMS::descTable(const char *name) {
    Table *tb;
    if (!requireDbOpen())
        return;
    if (!(tb = current->getTableByName(name))) {
        printf("Table %s not found\n", name);
        return;
    }
    // tb->printSchema();
}