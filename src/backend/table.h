#ifndef __TABLE_H__
#define __TABLE_H__
#include "../constants.h"
#include <string>

struct table_header_t
{   
    char table_name[MAX_NAME_LEN];

	uint8_t col_num;
	char col_name[MAX_COLUMN_SIZE][MAX_NAME_LEN];	
	uint8_t col_type[MAX_COLUMN_SIZE];
	int col_length[MAX_COLUMN_SIZE];
	int col_offset[MAX_COLUMN_SIZE];

	void dump();
};

class table_manager
{
	bool is_open, is_mirror;
	table_header_t header;
	std::string tname;
	const char *error_msg;

public:
	table_manager() : is_open(false) { }
	~table_manager() { if(is_open) close(); }
	bool create(const char *table_name, const table_header_t *header);
	bool open(const char *table_name);
	void drop();
	void close();

	void dump_table_info() { header.dump(); }

private:

};

#endif