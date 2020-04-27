#include "table.h"
#include "../dbms/dbms.h"
#include "../sql_parser/Execute.h"
#include "Compare.h"
#include <cstdio>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>

bool fill_table_header(table_header_t *header, const table_def *table){
	std::memset(header, 0, sizeof(table_header_t));
	std::strncpy(header->table_name, table->name, MAX_NAME_LEN);
	int offset = 8;  // 4 bytes for __rowid__, and 4 bytes for not null
	for(column_defs *c = table->columns; c; c = c->next)
	{
		int index = header->col_num++;
		std::strncpy(header->col_name[index], c->name, MAX_NAME_LEN);
		switch (c->type) {
            case COLUMN_TYPE_INT:
                header->col_type[index] = CT_INT;
				header->col_length[index] = 4;
				break;
            case COLUMN_TYPE_VARCHAR:
                header->col_type[index]   = CT_VARCHAR;
				header->col_length[index] = c->size + 1;
				break;
            case COLUMN_TYPE_FLOAT:
                header->col_type[index]   = CT_FLOAT;
				header->col_length[index] = 4;
				break;
            case COLUMN_TYPE_DATE:
                header->col_type[index]   = CT_DATE;
				header->col_length[index] = 4;
				break;
            default:
                assert(false);
                break;
        }
		
		header->col_offset[index] = offset;
		offset += header->col_length[index];
		if(c->flags & FIELD_FLAG_NOTNULL)
			header->flag_notnull |= 1 << index;
		if(c->flags & FIELD_FLAG_PRIMARY)
			header->flag_primary |= 1 << index;
		if(c->flags & FIELD_FLAG_UNIQUE)
			header->flag_unique |= 1 << index;
		// if(field->default_value != nullptr)
		// {
		// 	if(header->col_length[index] > MAX_DEFAULT_LEN)
		// 	{
		// 		std::fprintf(stderr, "[Error] Field too long to have default value.\n");
		// 		return false;
		// 	}

		// 	header->flag_default |= 1 << index;
		// 	expression expr = expression::eval(field->default_value);
		// 	auto desired_type = typecast::column_to_term(header->col_type[index]);
		// 	char *data = typecast::expr_to_db(expr, desired_type);
		// 	if(desired_type == TERM_STRING)
		// 	{
		// 		std::strcpy(header->default_values[index], data);
		// 	} else {
		// 		std::memcpy(header->default_values[index], data, header->col_length[index]);
		// 	}
		// }
	}

	auto lookup_column = [&](const char *name) -> int {
		for(int i = 0; i != header->col_num; ++i)
		{
			if(std::strcmp(name, header->col_name[i]) == 0)
				return i;
		}

		std::fprintf(stderr, "[Error] Column `%s` not found.\n", name);
		return -1;
	};
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

void table_header_t::dump()
{
	std::printf("======== Table Info Begin ========\n");
	std::printf("Table name  = %s\n", table_name);
	/*std::printf("Column size = %d\n", col_num);
	std::printf("Record size = %d\n", records_num);
	for(int i = 0; i != col_num; ++i)
	{
		std::printf("  [column] name = %s, type = ", col_name[i]);
		switch(col_type[i])
		{
			case COL_TYPE_INT:
				std::printf("INT");
				break;
			case COL_TYPE_FLOAT:
				std::printf("FLOAT");
				break;
			case COL_TYPE_DATE:
				std::printf("DATE");
				break;
			case COL_TYPE_VARCHAR:
				std::printf("VARCHAR(%d)", col_length[i]);
				break;
			default:
				std::printf("UNKNOWN");
				break;
		}

		std::printf(", flags = ");
		if(flag_notnull & (1 << i))
			std::printf("NOT_NULL ");
		if(flag_primary & (1 << i))
			std::printf("PRIMARY ");
		if(flag_unique & (1 << i))
			std::printf("UNIQUE ");
		if(flag_indexed & (1 << i))
			std::printf("INDEXED ");
		std::puts("");
	}
	*/

	std::printf("======== Table Info End   ========\n");
}