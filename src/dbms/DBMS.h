#ifndef __DBMS_H__
#define __DBMS_H__

#include "backend/Database.h"
#include "sql_parser/type_def.h"
#include "sql_parser/Expression.h"
#include <functional>

class DBMS {
    Database *current;

public:
    DBMS();

    static DBMS *getInstance();

    void exit();

    void switchToDB(const char *name);

    void createTable(const table_def *table);

    void dropDB(const char *db_name);

    void dropTable(const char *table);

    void listTables();

    void selectRow(const linked_list *tables, const linked_list *column_expr, expr_node *condition);

    void updateRow(const char *table, expr_node *condition, column_ref *column, expr_node *eval);

    void deleteRow(const char *table, expr_node *condition);

    void insertRow(const char *table, const linked_list *columns, const linked_list *values);

    void descTable(const char *name);

    bool requireDbOpen();

    // 非功能性函数
    
    // 将表达式类型转化为布尔类型
    bool convertToBool(const Expression &val);
    // 将数据库类型转化为表达式类型
    Expression dbTypeToExprType(char *data, ColumnType type);
    // 将表达式类型转化为数据库类型
    char *ExprTypeToDbType(Expression &val, term_type desiredType);
    //  将列-属性类型转化为表达式
    term_type ColumnTypeToExprType(const ColumnType& type);
    // 检查表达式的值是否相符
    bool checkColumnType(ColumnType type, const Expression &val);
    
    // void cacheColumns(Table *tb, int rid);
    // void freeCachedColumns();
    // expr_node* findJoinCondition(expr_node *condition);
    using CallbackFunc = std::function<void(Table *, RID_t)>;
    // bool iterateTwoTableRecords(Table *a, Table *b, expr_node *condition, CallbackFunc callback);
    // void iterateRecords(linked_list *tables, expr_node *condition, CallbackFunc callback);
    // void iterateRecords(Table *tb, expr_node *condition, CallbackFunc callback);
    // int isAggregate(const linked_list *column_expr);
    
    // 根据表达式打印值
    void printExprVal(const Expression &val);
    // 链表释放
    void freeLinkedList(linked_list *t){
    linked_list *next;
    for (; t; t = next) {
        next = t->next;
        free(t);
    }
}
};

#endif