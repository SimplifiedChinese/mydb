#ifndef __DBMS_H__
#define __DBMS_H__

#include "backend/Database.h"
#include "sql_parser/type_def.h"
#include "sql_parser/Expression.h"
#include <functional>

class DBMS {
    // IDX不是索引，是用来判断符号的
    enum IDX_TYPE {
    IDX_NONE, IDX_LOWWER, IDX_UPPER, IDX_EQUAL
};
    Database *current;

public:
    DBMS();

    static DBMS *getInstance();

    void exit();

    // 和DB有关，切换正在使用的DB，或者删除，新建DB也是切换，方便点
    void switchToDB(const char *name);
    void dropDB(const char *db_name);

    // 和表有关的操作
    void createTable(const table_def *table);
    void dropTable(const char *table);
    void listTables();
    void descTable(const char *name);
 
    // CRUD
    void selectRow(const linked_list *tables, const linked_list *column_expr, expr_node *condition);
    void updateRow(const char *table, expr_node *condition, column_ref *column, expr_node *eval);
    void deleteRow(const char *table, expr_node *condition);
    void insertRow(const char *table, const linked_list *columns, const linked_list *values);
   
    // 判断DB是否已被打开
    bool requireDbOpen();

    // 以下都是非功能性函数
    
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
    // 缓存的列，和查询有关
    void cacheColumns(Table *tb, int rid);
    // 回调函数，先using
    using CallbackFunc = std::function<void(Table *, RID_t)>;
    // 两种迭代遍历表的方法，还未支持多表查询，其实一模一样
    void iterateRecords(linked_list *tables, expr_node *condition, CallbackFunc callback);
    void iterateRecords(Table *tb, expr_node *condition, CallbackFunc callback);
    // 获取下一条记录
    RID_t nextWithIndex(Table *tb, IDX_TYPE type, int col, RID_t rid, RID_t rid_u);
    
    // 待实现的函数
    int isAggregate(const linked_list *column_expr);
    // void freeCachedColumns();
    // expr_node* findJoinCondition(expr_node *condition);
    // bool iterateTwoTableRecords(Table *a, Table *b, expr_node *condition, CallbackFunc callback);

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