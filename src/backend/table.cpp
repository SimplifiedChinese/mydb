#include "table.h"
#include "../dbms/dbms.h"
#include "../sql_parser/Execute.h"
#include "../io/FileManager.h"
#include "../io/BufPageManager.h"
#include "RegisterManager.h"
#include <assert.h>
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
		// if(c->flags & COLUMN_FLAG_NOTNULL)
		// 	header->flag_notnull |= 1 << index;

		// if(c->flags & COLUMN_FLAG_DEFAULT)
		// 	header->flag_primary |= 1 << index;
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
    this->tname = std::string(table_name);
    fileID = BufPageManager::getFileManager().openFile(table_name);
    permID = BufPageManager::getFileManager().getFilePermID(fileID);
    RegisterManager::get_instance().checkIn(permID, this);
    int index = BufPageManager::get_instance().getPage(fileID, 0);
    memcpy(&header, BufPageManager::get_instance().access(index), sizeof(table_header_t));;
    // for (auto &col: colIndex) {
    //     col.clear();
    // }
	return is_open = true;
}

bool table_manager::create(const char *table_name, const table_header_t *header)
{
	if(is_open) return false;
	tname = table_name;
    BufPageManager::getFileManager().createFile(table_name);
    fileID = BufPageManager::getFileManager().openFile(table_name);
    permID = BufPageManager::getFileManager().getFilePermID(fileID);
    BufPageManager::get_instance().allocPage(fileID, 0);
	RegisterManager::get_instance().checkIn(permID, this);
	this->header = *header;
	return is_open = true;
}

void table_manager::drop()
{
	if(!is_open) return;
	close();
	RegisterManager::get_instance().checkIn(permID, this);
    BufPageManager::get_instance().closeFile(fileID, false);
    BufPageManager::getFileManager().closeFile(fileID);
}

void table_manager::close()
{
	if(!is_open) return;
    RegisterManager::get_instance().checkIn(permID, this);
    BufPageManager::get_instance().closeFile(fileID);
    BufPageManager::getFileManager().closeFile(fileID);
	is_open = false;
}

int table_manager::addColumn(const char *name, ColumnType type, int size,
                  bool notNull, bool hasDefault, const char *data){
	printf("adding %s %d %d\n", name, type, size);
    for (int i = 0; i < header.col_num; i++)
        if (strcmp(header.col_name[i], name) == 0)
            return -1;	
	assert(header.col_num < MAX_COLUMN_SIZE);
    int id = header.col_num++;
	strcpy(header.col_name[id], name);
    header.col_type[id] = type;
    header.col_offset[id] = header.recordByte;
    header.col_length[id] = size;
	header.defaultOffset[id] = -1;
    switch (type) {
        case CT_INT:
        case CT_FLOAT:
        case CT_DATE:
            header.recordByte += 4;
            if (hasDefault) {
                header.defaultOffset[id] = header.dataArrUsed;
                memcpy(header.dataArr + header.dataArrUsed, data, 4);
                header.dataArrUsed += 4;
            }
            break;
        case CT_VARCHAR:
            header.recordByte += size + 1;
            header.recordByte += 4 - header.recordByte % 4;
            if (hasDefault) {
                header.defaultOffset[id] = header.dataArrUsed;
                strcpy(header.dataArr + header.dataArrUsed, data);
                header.dataArrUsed += strlen(data) + 1;
            }
            break;
        default:
            assert(0);
    }
    assert(header.dataArrUsed <= MAX_DATA_SIZE);
    assert(header.recordByte <= PAGE_SIZE);
    return id;
}

void table_header_t::dump()
{
	std::printf("======== Table Info Begin ========\n");
	std::printf("Table name  = %s\n", table_name);
	std::printf("Column size = %d\n", col_num);
	// std::printf("Record size = %d\n", records_num);
	for(int i = 0; i != col_num; ++i)
	{
		std::printf("  [column] name = %s, type = ", col_name[i]);
		switch(col_type[i])
		{
			case CT_INT:
				std::printf("INT");
				break;
			case CT_FLOAT:
				std::printf("FLOAT");
				break;
			case CT_DATE:
				std::printf("DATE");
				break;
			case CT_VARCHAR:
				std::printf("VARCHAR(%d)", col_length[i]);
				break;
			default:
				std::printf("UNKNOWN");
				break;
		}

		// std::printf(", flags = ");
		// if(flag_notnull & (1 << i))
		// 	std::printf("NOT_NULL ");
		// if(flag_primary & (1 << i))
		// 	std::printf("PRIMARY ");
		// if(flag_unique & (1 << i))
		// 	std::printf("UNIQUE ");
		// if(flag_indexed & (1 << i))
		// 	std::printf("INDEXED ");
		// std::puts("");
	}
	

	std::printf("======== Table Info End   ========\n");
}