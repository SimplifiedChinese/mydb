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

 void DBMS::selectRow(const linked_list *tables, const linked_list *column_expr, expr_node *condition){

 }

void DBMS::updateRow(const char *table, expr_node *condition, column_ref *column, expr_node *eval) {
    // Table *tb;
    // if (!requireDbOpen())
    //     return;
    // if (!(tb = current->getTableByName(table))) {
    //     printf("Table %s not found\n", table);
    //     return;
    // }

    // int col_to_update;
    // col_to_update = tb->getColumnID(column->column);
    // if (col_to_update == -1) {
    //     printf("Column %s not found\n", column->column);
    //     return;
    // }
    // int count = 0;
    // try {
    //     iterateRecords(tb, condition, [&col_to_update, &eval, &count, this](Table *tb, int rid) -> void {
    //         Expression new_val;
    //         new_val = calcExpression(eval);
    //         //printf("t=%d\n", tb->getColumnType(col_to_update));
    //         auto colType = tb->getColumnType(col_to_update);
    //         if (!checkColumnType(colType, new_val)) {
    //             printf("Wrong data type\n");
    //             throw (int) EXCEPTION_WRONG_DATA_TYPE;
    //         }
    //         std::string ret = tb->modifyRecord(rid, col_to_update,
    //                                            ExprTypeToDbType(new_val, ColumnTypeToExprType(colType)));
    //         if (!ret.empty()) {
    //             std::cout << ret << std::endl;
    //             throw (int) EXCEPTION_WRONG_DATA_TYPE;
    //         }
    //         ++count;
    //     });
    // } catch (int err) {
    //     //printReadableException(err);
    // } catch (...) {
    //     printf("Exception occur %d\n", __LINE__);
    // }
    // printf("%d rows updated.\n", count);
    // freeCachedColumns();
}

void DBMS::deleteRow(const char *table, expr_node *condition) {
    // std::vector<RID_t> toBeDeleted;
    // Table *tb;
    // if (!requireDbOpen())
    //     return;
    // if (!(tb = current->getTableByName(table))) {
    //     printf("Table %s not found\n", table);
    //     return;
    // }
    // iterateRecords(tb, condition, [&toBeDeleted, this](Table *tb, int rid) -> void {
    //     UNUSED(tb);
    //     toBeDeleted.push_back(rid);
    // });
    // for (const auto &i : toBeDeleted) {
    //     tb->dropRecord(i);
    // }
    // printf("%d rows deleted.\n", (int) toBeDeleted.size());
    // freeCachedColumns();
}

void DBMS::insertRow(const char *table, const linked_list *columns, const linked_list *values) {
    Table *tb;
    if (!requireDbOpen())
        return;
    if (!(tb = current->getTableByName(table))) {
        printf("Table %s not found\n", table);
        return;
    }
    std::vector<int> colId;
    if (!columns) { //column list is not specified
        for (int i = tb->getColumnCount() - 1; i > 0; --i) //exclude RID
        {
            colId.push_back(i);
        }
    } else
        for (const linked_list *i = columns; i; i = i->next) {
            const column_ref *col = (column_ref *) i->data;
            if (col->table && strcasecmp(col->table, table) != 0) {
                printf("Illegal column reference: %s.%s\n", col->table, col->column);
                return;
            }
            int id = tb->getColumnID(col->column);
            printf("Column %s id=%d\n", col->column, id);
            if (id < 0) {
                printf("Column %s not found\n", col->column);
                return;
            }
            colId.push_back(id);
        }
    printf("Inserting into %lu columns\n", colId.size());
    tb->clearTempRecord();
    int count = 0;
    for (const linked_list *i = values; i; i = i->next) {
        const linked_list *expr_list = (linked_list *) i->data;
        unsigned int cnt = 0;
        for (const linked_list *j = expr_list; j; j = j->next) {
            cnt++;
        }
        if (cnt != colId.size()) {
            printf("Column size mismatch, will not execute (value size=%d)\n", cnt);
            continue;
        }
        //printf("Insert one row...\n");
        auto it = colId.begin();
        std::string result;
        for (const linked_list *j = expr_list; j; j = j->next) {
            auto node = (expr_node *) j->data;
            Expression val;
            try {
                val = calcExpression(node);
            } catch (int err) {
                // printReadableException(err);
                printf("ERROR");
                return;
            } catch (...) {
                printf("Exception occur %d\n", __LINE__);
                return;
            }
            //printf("Column [%d] value ", *it);
            //printExprVal(val);
            //putchar('\n');
            auto colType = tb->getColumnType(*it);
            if (!checkColumnType(colType, val)) {
                printf("Wrong data type\n");
                return;
            }
            auto exprType = ColumnTypeToExprType(colType);
            result = tb->setTempRecord(*it, ExprTypeToDbType(val, exprType));
            if (!result.empty()) {
                std::cout << result << std::endl;
                goto next_rec;
            }
            ++it;
        }
        result = tb->insertTempRecord();
        if (!result.empty()) {
            std::cout << result << std::endl;
        } else {
            ++count;
        }
        next_rec:;
    }
    printf("%d rows inserted.\n", count);
}

void DBMS::descTable(const char *name) {
    Table *tb;
    if (!requireDbOpen())
        return;
    if (!(tb = current->getTableByName(name))) {
        printf("Table %s not found\n", name);
        return;
    }
    tb->printSchema();
}

// 非功能函数在这里面
bool DBMS::checkColumnType(ColumnType type, const Expression &val) {
    if (val.type == TERM_NULL)
        return true;
    switch (val.type) {
        case TERM_INT:
            return type == CT_INT || type == CT_FLOAT;
        case TERM_FLOAT:
            return type == CT_FLOAT;
        case TERM_STRING:
            return type == CT_VARCHAR;
        case TERM_DATE:
            return type == CT_DATE;
        default:
            return false;
    }
}

term_type DBMS::ColumnTypeToExprType(const ColumnType &type) {
    switch (type) {
        case CT_INT:
            return TERM_INT;
        case CT_FLOAT:
            return TERM_FLOAT;
        case CT_VARCHAR:
            return TERM_STRING;
        case CT_DATE:
            return TERM_DATE;
        default:
            throw (int) EXCEPTION_WRONG_DATA_TYPE;
    }
}

char *DBMS::ExprTypeToDbType(Expression &val, term_type desiredType) {
    char *ret = nullptr;
    //TODO: data type convert here, e.g. double->int
    switch (val.type) {
        case TERM_INT:
            if (desiredType == TERM_FLOAT) {
                val.value.value_f = val.value.value_i;
                ret = (char *) &val.value.value_f;
            } else {
                ret = (char *) &val.value.value_i;
            }
            break;
        case TERM_BOOL:
            ret = (char *) &val.value.value_b;
            break;
        case TERM_FLOAT:
            if (desiredType == TERM_INT) {
                val.value.value_i = (int) val.value.value_f;
                ret = (char *) &val.value.value_i;
            } else {
                ret = (char *) &val.value.value_f;
            }
            break;
        case TERM_STRING:
            ret = val.value.value_s;
            break;
        case TERM_DATE:
            ret = (char *) &val.value.value_i;
            break;
        case TERM_NULL:
            ret = nullptr;
            break;
        default:
            printf("Error: Unhandled type\n");
            assert(false);
    }
    return ret;
}

bool DBMS::convertToBool(const Expression &val) {
    bool t = false;
    switch (val.type) {
        case TERM_INT:
            t = val.value.value_i != 0;
            break;
        case TERM_BOOL:
            t = val.value.value_b;
            break;
        case TERM_FLOAT:
            t = val.value.value_f != 0;
            break;
        case TERM_STRING:
            t = strlen(val.value.value_s) != 0;
            break;
        case TERM_NULL:
            t = false;
            break;
        default:
            break;
    }
    return t;
}

Expression DBMS::dbTypeToExprType(char *data, ColumnType type) {
    Expression v;

    if (data == nullptr) {
        return Expression(TERM_NULL);
    }
    switch (type) {
        case CT_INT:
            v.type = TERM_INT;
            v.value.value_i = *(int *) data;
            break;
        case CT_VARCHAR:
            v.type = TERM_STRING;
            v.value.value_s = data;
            break;
        case CT_FLOAT:
            v.type = TERM_FLOAT;
            v.value.value_f = *(float *) data;
            break;
        case CT_DATE:
            v.type = TERM_DATE;
            v.value.value_i = *(int *) data;
            break;
        default:
            printf("Error: Unhandled type\n");
            assert(0);
    }
    return v;
}