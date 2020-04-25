#include "dbms.h"
#include "../backend/database.h"
#include <vector>
#include <limits>
#include <algorithm>

dbms::dbms()
	: output_file(stdout), cur_db(nullptr)
{
	printf("DBMS初始化成功！\n");
}

dbms::~dbms()
{
	close_database();
}

void dbms::close_database()
{
	if(cur_db) 
	{
		cur_db->close();
		delete cur_db;
		cur_db = nullptr;
	}
}

void dbms::show_database(const char *db_name)
{
	database db;
	db.open(db_name);
	// db.show_info();
}

void dbms::switch_database(const char *db_name)
{
	if(cur_db)
	{
		if(cur_db->is_opened()) cur_db->close();
		delete cur_db;
		cur_db = nullptr;
	}

	cur_db = new database();
	cur_db->open(db_name);
	// cur_db->show_info();
}

void dbms::create_database(const char *db_name)
{
	database db;
	db.create(db_name);
	db.close();
}

void dbms::drop_database(const char *db_name)
{
	if(cur_db && std::strcmp(cur_db->get_name(), db_name) == 0)
	{
		cur_db->close();
		delete cur_db;
		cur_db = nullptr;
	}
	// 之所以先打开再关闭再删除，是因为需要把可能存在的剩余信息写入数据库再删除，崩溃后有用
	database db;
	db.open(db_name);
	db.drop();
}

void dbms::create_table(const table_header_t *header)
{
	if(assert_db_open())
		cur_db->create_table(header);
}

void dbms::show_table(const char* table_name)
{
	if(assert_db_open())
	{
		table_manager *tm = cur_db->get_table(table_name);
		if(tm == nullptr)
		{
			std::fprintf(stderr, "[Error] Table `%s` not found.\n", table_name);
		} else {
			// tm->dump_table_info();
		}
	}
}

void dbms::drop_table(const char *table_name)
{
	if(assert_db_open())
		cur_db->drop_table(table_name);
}

bool dbms::assert_db_open()
{
	if(cur_db && cur_db->is_opened())
		return true;
	std::fprintf(stderr, "[Error] database is not opened.\n");
	return false;
}