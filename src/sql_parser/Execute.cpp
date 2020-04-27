#include <stdio.h>
#include <stdlib.h>
#include "Execute.h"
#include "../dbms/dbms.h"
#include "../backend/table.h"
#include "Expression.h"

void free_column_ref(column_ref *c) {
    if (c->table)
        free(c->table);
    free(c->column);
    free(c);
}

void free_column_list(linked_list *cols) {
    while (cols) {
        auto c = (column_ref *) cols->data;
        free_column_ref(c);
        linked_list *t = cols;
        cols = cols->next;
        free(t);
    }
}

void free_expr_list(linked_list *exprs) {
    while (exprs) {
        auto e = (expr_node *) exprs->data;
        free_expr(e);
        linked_list *t = exprs;
        exprs = exprs->next;
        free(t);
    }

}

void free_values(linked_list *values) {
    while (values) {
        auto exprs = (linked_list *) values->data;
        free_expr_list(exprs);
        linked_list *t = values;
        values = values->next;
        free(t);
    }
}

void free_tables(linked_list *tables) {
    while (tables) {
        auto table_name = (char *) tables->data;
        free(table_name);
        linked_list *t = tables;
        tables = tables->next;
        free(t);
    }
}


void report_sql_error(const char *error_name, const char *msg) {
    printf("SQL Error[%s]: %s\n", error_name, msg);
}

void execute_create_db(const char *db_name)
{
	dbms::get_instance()->create_database(db_name);
	free((char*)db_name);
}

void execute_use_db(const char *db_name)
{
	dbms::get_instance()->switch_database(db_name);
	free((char*)db_name);
}

void execute_drop_db(const char *db_name)
{
	dbms::get_instance()->drop_database(db_name);
	free((char*)db_name);
}

void execute_drop_table(const char *table_name)
{
	dbms::get_instance()->drop_table(table_name);
	free((void*)table_name);
}

void execute_show_table(const char *table_name)
{
	dbms::get_instance()->show_table(table_name);
	free((void*)table_name);
}

bool fill_table_header(table_header_t *header, const table_def *table);
void execute_create_tb(const table_def *table)
{
	table_header_t *header = new table_header_t;
	if(fill_table_header(header, table))
		dbms::get_instance()->create_table(header);
	else std::fprintf(stderr, "[Error] Fail to create table!\n");
	delete header;

	// free(table->name);
	// free_linked_list<table_constraint_t>(table->constraints, [](table_constraint_t *data) {
	// 	expression::free_exprnode(data->check_cond);
	// 	free_column_ref(data->column_ref);
	// 	free_column_ref(data->foreign_column_ref);
	// 	free(data);
	// } );

	// for(field_item_t *it = table->fields; it; )
	// {
	// 	field_item_t *tmp = it;
	// 	free(it->name);
	// 	expression::free_exprnode(it->default_value);
	// 	it = it->next;
	// 	free(tmp);
	// }

	// free((void*)table);
}

void execute_quit()
{
	dbms::get_instance()->close_database();
	printf("[exit] good bye!\n");
}

void execute_desc_tables(const char *table_name) {
    dbms::get_instance()->desc_table(table_name);
    free((void *) table_name);
}

void execute_show_tables() {
    dbms::get_instance()->list_tables();
}

// 准备写这些东西
void execute_insert_row(struct insert_argu *stmt){}
void execute_sql_eof(void){}
void execute_select(struct select_argu *stmt){}
void execute_delete(struct delete_argu *stmt){}
void execute_update(struct update_argu *stmt){}
void execute_drop_idx(struct column_ref *tb_col){}
void execute_create_idx(struct column_ref *tb_col){}