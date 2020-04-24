#include <stdio.h>
#include <stdlib.h>
#include "Execute.h"
#include "../dbms/dbms.h"
#include "../backend/table.h"
#include "Expression.h"

// template<typename T, typename DataDeleter>
// void free_linked_list(linked_list_t *linked_list, DataDeleter data_deleter)
// {
// 	for(linked_list_t *l_ptr = linked_list; l_ptr; )
// 	{
// 		T* data = (T*)l_ptr->data;
// 		data_deleter(data);
// 		linked_list_t *tmp = l_ptr;
// 		l_ptr = l_ptr->next;
// 		free(tmp);
// 	}
// }

// void expression::free_exprnode(expr_node_t *expr)
// {
// 	if(!expr) return;
// 	if(expr->op == OPERATOR_NONE)
// 	{
// 		switch(expr->term_type)
// 		{
// 			case TERM_STRING:
// 				free(expr->val_s);
// 				break;
// 			case TERM_COLUMN_REF:
// 				free(expr->column_ref->table);
// 				free(expr->column_ref->column);
// 				free(expr->column_ref);
// 				break;
// 			case TERM_LITERAL_LIST:
// 				free_linked_list<expr_node_t>(
// 					expr->literal_list,
// 					expression::free_exprnode
// 				);
// 				break;
// 			default:
// 				break;
// 		}
// 	} else {
// 		free_exprnode(expr->left);
// 		free_exprnode(expr->right);
// 	}

// 	free(expr);
// }

// void free_column_ref(column_ref_t *cref)
// {
// 	if(!cref) return;
// 	free(cref->column);
// 	free(cref->table);
// 	free(cref);
// }

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

void execute_show_database(const char *db_name)
{
	dbms::get_instance()->show_database(db_name);
	free((void*)db_name);
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

void execute_quit()
{
	dbms::get_instance()->close_database();
	printf("[exit] good bye!\n");
}

void execute_desc_tables(const char *table_name){}
void execute_show_tables(){}
void execute_insert_row(struct insert_argu *stmt){}
void execute_sql_eof(void){}
void execute_select(struct select_argu *stmt){}
void execute_delete(struct delete_argu *stmt){}
void execute_update(struct update_argu *stmt){}
void execute_drop_idx(struct column_ref *tb_col){}
void execute_create_idx(struct column_ref *tb_col){}
