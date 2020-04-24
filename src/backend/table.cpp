#include "table.h"
#include "../dbms/dbms.h"
#include "../sql_parser/Execute.h"
#include <cstdio>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>

bool fill_table_header(table_header_t *header, const table_def *table){
	std::memset(header, 0, sizeof(table_header_t));
	std::strncpy(header->table_name, table->name, MAX_NAME_LEN);
	return true;
}


bool table_manager::open(const char *table_name)
{
	if(is_open) return false;
	tname = table_name;
	std::string thead = tname + ".thead";
	std::string tdata = tname + ".tdata";

	std::ifstream ifs(thead, std::ios::binary);
	ifs.read((char*)&header, sizeof(header));

	is_mirror = false;
	return is_open = true;
}

bool table_manager::create(const char *table_name, const table_header_t *header)
{
	if(is_open) return false;
	tname = table_name;
	std::string tdata = tname + ".tdata";

	is_mirror = false;
	return is_open = true;
}

void table_manager::drop()
{
	if(!is_open) return;
	close();
	std::string thead = tname + ".thead";
	std::string tdata = tname + ".tdata";
	std::remove(thead.c_str());
	std::remove(tdata.c_str());
}

void table_manager::close()
{
	if(!is_open) return;

	if(!is_mirror)
	{
		std::string thead = tname + ".thead";
		std::string tdata = tname + ".tdata";
	}
	
	is_open = false;
	is_mirror = false;
}