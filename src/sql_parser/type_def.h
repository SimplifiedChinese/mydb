#ifndef __TYPE_DEF_H__
#define __TYPE_DEF_H__

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum column_flag {
    COLUMN_FLAG_NOTNULL = 1,
    COLUMN_FLAG_DEFAULT = 2
} column_flag;

typedef enum column_type {
    COLUMN_TYPE_INT,
    COLUMN_TYPE_CHAR,
    COLUMN_TYPE_VARCHAR,
    COLUMN_TYPE_FLOAT,
    COLUMN_TYPE_DATE
} column_type;

#define OPER_UNARY 0x80

typedef enum operator_type {
    OPER_NONE,
    OPER_ADD,
    OPER_DEC,
    OPER_MUL,
    OPER_DIV,
    OPER_AND,
    OPER_OR,
    OPER_EQU,
    OPER_GT,
    OPER_GE,
    OPER_LT,
    OPER_LE,
    OPER_NEQ,
    OPER_LIKE,
    OPER_NEG = OPER_UNARY,
    OPER_NOT,
    OPER_MIN,
    OPER_MAX,
    OPER_COUNT,
    OPER_AVG,
    OPER_SUM,
    OPER_ISNULL
} operator_type;

typedef enum term_type {
    TERM_NONE,
    TERM_INT,
    TERM_STRING,
    TERM_FLOAT,
    TERM_BOOL,
    TERM_NULL,
    TERM_COLUMN,
    TERM_DATE
} term_type;

typedef enum constraint_type {
    CONSTRAINT_PRIMARY_KEY,
    CONSTRAINT_FOREIGN_KEY,
    CONSTRAINT_CHECK
} constraint_type;

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list;

typedef struct column_ref {
    char *table;
    char *column;
} column_ref;

typedef struct column_defs {
    char *name;
    int type;
    int size;
    unsigned int flags;
    struct column_defs *next;
} column_defs;

typedef struct table_def {
    char *name;
    column_defs *columns;
    linked_list *constraints;
} table_def;

typedef struct table_constraint {
    int type;
    char *column_name;
    char *foreign_table_name;
    char *foreign_column_name;
    linked_list *values;
} table_constraint;

typedef struct insert_argu {
    char *table;
    linked_list *columns;
    linked_list *values;
} insert_argu;

typedef struct expr_node {
    union {
        struct expr_node *left;
        char *literal_s;
        int literal_i;
        float literal_f;
        uint8_t literal_b;
        column_ref *column;
    };
    struct expr_node *right;
    operator_type op;
    term_type node_type;
} expr_node;

typedef struct select_argu {
    linked_list *column_expr;
    linked_list *tables;
    expr_node *where;
} select_argu;

typedef struct delete_argu {
    char *table;
    expr_node *where;
} delete_argu;

typedef struct update_argu {
    char *table;
    column_ref *column;
    expr_node *val_expr;
    expr_node *where;
} update_argu;

#ifdef __cplusplus
}
#endif

#endif // __TYPE_DEF_H__
