#ifndef __DBMS__
#define __DBMS__

#include "../backend/database.h"
#include "../backend/table.h"
#include <cstdio>

class dbms
{
	FILE *output_file;
	database *cur_db;
private:
	// dbms();

public:
	dbms();
	~dbms();

	void close_database();
	void show_database(const char *db_name);
	void switch_database(const char *db_name);
	void drop_database(const char *db_name);
	void create_database(const char *db_name);

	void create_table(const table_header_t *header);
	void show_table(const char *table_name);
	void drop_table(const char *table_name);

	// void insert_rows(const insert_info_t *info);
	// void delete_rows(const delete_info_t *info);
	// void select_rows(const select_info_t *info);
	// void update_rows(const update_info_t *info);

	bool assert_db_open();

public:
	static dbms* get_instance()
	{
		static dbms ms;
		return &ms;
	}
};

#endif