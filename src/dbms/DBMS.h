#ifndef __DBMS_H__
#define __DBMS_H__

#include "backend/Database.h"
#include "sql_parser/type_def.h"
#include "sql_parser/Expression.h"

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

    // void selectRow(const linked_list *tables, const linked_list *column_expr, expr_node *condition);

    // void updateRow(const char *table, expr_node *condition, column_ref *column, expr_node *eval);

    // void deleteRow(const char *table, expr_node *condition);

    // void insertRow(const char *table, const linked_list *columns, const linked_list *values);

    void descTable(const char *name);

    bool requireDbOpen();
};

#endif