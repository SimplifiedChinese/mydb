/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_HOME_LIZHE_CODES_DB_MYDB_BUILD_SRC_SQL_PARSER_SQL_TAB_H_INCLUDED
# define YY_YY_HOME_LIZHE_CODES_DB_MYDB_BUILD_SRC_SQL_PARSER_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TRUE = 258,
    FALSE = 259,
    AND = 260,
    OR = 261,
    NEQ = 262,
    GEQ = 263,
    LEQ = 264,
    NOT = 265,
    IS = 266,
    INDEX = 267,
    DATABASE = 268,
    DROP = 269,
    USE = 270,
    UPDATE = 271,
    SET = 272,
    TOKEN_NULL = 273,
    INT = 274,
    DOUBLE = 275,
    CHAR = 276,
    VARCHAR = 277,
    USING = 278,
    ASC = 279,
    DESC = 280,
    JOIN = 281,
    INNER = 282,
    OUTER = 283,
    LEFT = 284,
    RIGHT = 285,
    UNIQUE = 286,
    IN = 287,
    ON = 288,
    FULL = 289,
    NATURAL = 290,
    VALUES = 291,
    COUNT = 292,
    SUM = 293,
    AVG = 294,
    MIN = 295,
    MAX = 296,
    DISTINCT = 297,
    TABLE = 298,
    CREATE = 299,
    SELECT = 300,
    WHERE = 301,
    INSERT = 302,
    INTO = 303,
    FROM = 304,
    DEFAULT = 305,
    CHECK = 306,
    PRIMARY = 307,
    FOREIGN = 308,
    KEY = 309,
    REFERENCES = 310,
    GROUP = 311,
    ORDER = 312,
    BY = 313,
    DELETE = 314,
    LIKE = 315,
    SHOW = 316,
    IDENTIFIER = 317,
    FLOAT = 318,
    DATE = 319,
    EXIT = 320,
    DATE_LITERAL = 321,
    STRING_LITERAL = 322,
    FLOAT_LITERAL = 323,
    INT_LITERAL = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1909  */

  int val_i;
  float val_f;
  char *val_s;
  column_ref* ref_column;
  column_defs* def_column;
  table_def* def_table;
  linked_list* list;
  insert_argu* insert_argu;
  expr_node* expr_node;
  select_argu* select_argu;
  delete_argu* delete_argu;
  update_argu* update_argu;
  table_constraint* t_constraint;

#line 140 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_LIZHE_CODES_DB_MYDB_BUILD_SRC_SQL_PARSER_SQL_TAB_H_INCLUDED  */
