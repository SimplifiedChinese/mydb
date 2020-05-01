/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 9 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:339  */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Execute.h"
#include "type_def.h"

int yyerror(const char *str);

#include "sql.yy.c"


#line 80 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sql.tab.h".  */
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
#line 22 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:355  */

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

#line 206 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_LIZHE_CODES_DB_MYDB_BUILD_SRC_SQL_PARSER_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      71,    72,    73,    78,    75,    79,    81,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
      77,    74,    76,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    82,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    78,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    97,   105,
     108,   111,   114,   117,   120,   121,   124,   132,   135,   143,
     144,   147,   150,   157,   166,   167,   170,   172,   173,   176,
     186,   187,   188,   189,   190,   191,   194,   195,   198,   199,
     202,   205,   206,   209,   210,   213,   218,   224,   234,   235,
     238,   239,   242,   243,   246,   247,   250,   251,   254,   255,
     256,   257,   260,   261,   262,   263,   264,   265,   268,   276,
     277,   280,   281,   284,   285,   293,   294,   297,   303,   304,
     309,   310,   315,   320,   327,   328,   329,   330,   331,   332,
     333,   336,   342,   348,   351,   357,   363,   366,   371,   376,
     381,   386,   391,   395,   400,   403,   404,   407,   408,   411
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TRUE", "FALSE", "AND", "OR", "NEQ",
  "GEQ", "LEQ", "NOT", "IS", "INDEX", "DATABASE", "DROP", "USE", "UPDATE",
  "SET", "TOKEN_NULL", "INT", "DOUBLE", "CHAR", "VARCHAR", "USING", "ASC",
  "DESC", "JOIN", "INNER", "OUTER", "LEFT", "RIGHT", "UNIQUE", "IN", "ON",
  "FULL", "NATURAL", "VALUES", "COUNT", "SUM", "AVG", "MIN", "MAX",
  "DISTINCT", "TABLE", "CREATE", "SELECT", "WHERE", "INSERT", "INTO",
  "FROM", "DEFAULT", "CHECK", "PRIMARY", "FOREIGN", "KEY", "REFERENCES",
  "GROUP", "ORDER", "BY", "DELETE", "LIKE", "SHOW", "IDENTIFIER", "FLOAT",
  "DATE", "EXIT", "DATE_LITERAL", "STRING_LITERAL", "FLOAT_LITERAL",
  "INT_LITERAL", "';'", "'('", "')'", "'*'", "'='", "','", "'>'", "'<'",
  "'+'", "'-'", "'/'", "'.'", "'`'", "$accept", "sql_stmts", "sql_stmt",
  "show_stmt", "desc_stmt", "create_idx_stmt", "drop_idx_stmt",
  "create_db_stmt", "drop_db_stmt", "use_db_stmt", "create_tb_stmt",
  "drop_tb_stmt", "select_stmt", "expr_list_or_star", "insert_stmt",
  "delete_stmt", "update_stmt", "where_clause", "select_opt",
  "column_decs", "column_dec", "column_type", "type_width",
  "column_constraints", "column_constraint", "tb_opt_exist", "tb_opt_decs",
  "tb_opt_dec", "table_refs", "table_join", "join_cond", "value_list",
  "expr_list", "select_expr_list", "aggregate", "aggregate_term",
  "table_columns", "column_list", "condition_expr", "logic_op",
  "condition_term", "compare_op", "expr", "factor", "term", "column_ref",
  "table_name", "db_name", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      59,    40,    41,    42,    61,    44,    62,    60,    43,    45,
      47,    46,    96
};
# endif

#define YYPACT_NINF -170

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-170)))

#define YYTABLE_NINF -118

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     169,    17,     6,   -39,   -39,    37,    93,   -22,   -14,    33,
      30,    92,  -170,    45,    54,    80,    82,    84,    86,    88,
      95,   104,   106,   116,   117,   119,   101,   129,   -39,   129,
    -170,  -170,  -170,   133,    31,  -170,   138,   129,   -39,  -170,
     110,   135,   139,   140,   153,   123,  -170,  -170,  -170,  -170,
     111,  -170,   111,   176,   151,  -170,   -12,   -49,  -170,  -170,
     146,   -39,   -39,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
     158,  -170,  -170,  -170,   149,   -35,   161,  -170,   164,    43,
     -35,   -35,   -35,   -35,    48,  -170,   -39,   130,   111,   111,
     111,   111,   174,   201,   167,   193,   179,  -170,   166,   180,
     181,   172,   173,  -170,   175,   177,   182,   183,  -170,   -24,
     220,  -170,  -170,   -12,   -49,   -49,  -170,  -170,  -170,   185,
     -35,     7,  -170,   186,   111,   187,    34,   188,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,   -39,  -170,   -39,   111,   189,
      18,  -170,  -170,  -170,     7,     7,    36,  -170,    25,  -170,
      -7,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   190,    61,
     194,   220,  -170,   215,    46,   -12,   191,  -170,   -35,  -170,
      15,     5,  -170,  -170,     7,  -170,  -170,  -170,   232,   196,
    -170,  -170,  -170,  -170,   111,  -170,   184,  -170,   197,   198,
     203,  -170,   195,  -170,  -170,     7,  -170,  -170,   111,   111,
    -170,  -170,  -170,  -170,   111,   -12,   199,   241,   207,   202,
     204,   170,    36,   -12,    47,    63,  -170,   242,  -170,   233,
     -35,   210,  -170,  -170,  -170,  -170,   205,    68,   206,   111,
    -170,   219,    69,   217,   208,   211,  -170,   221,   209,  -170
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,    25,   117,     0,     0,    19,     0,     0,     0,   112,
       0,     0,     0,     0,     0,   115,   110,   111,   109,   108,
       0,    30,     0,     0,    29,    69,    68,   103,   106,   107,
       0,     0,     0,    18,    17,     1,     3,    15,    16,     6,
       7,     4,    12,    14,     5,    13,     8,     9,    11,    10,
       0,    23,    27,    24,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    35,     0,   118,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,   114,    35,
      58,    60,    70,    71,   101,   102,   104,   105,   116,     0,
       0,     0,    32,     0,     0,     0,     0,    52,    38,    77,
      76,    72,    73,    74,    75,     0,    36,     0,     0,    31,
       0,    81,    92,    93,     0,     0,    34,    83,     0,    21,
      35,    20,    40,    44,    41,    42,    43,    45,    47,     0,
       0,    59,    28,    63,     0,    66,     0,    80,     0,    91,
       0,     0,    85,    86,     0,    99,    97,    98,     0,     0,
     100,    94,    95,    96,     0,    33,     0,    49,     0,     0,
       0,    37,    51,    53,    26,     0,    61,    64,     0,     0,
      82,    90,    84,    89,     0,    87,     0,    39,     0,     0,
       0,     0,    62,    67,     0,     0,    46,     0,    48,     0,
       0,     0,    54,    65,    88,    50,     0,     0,     0,     0,
      55,     0,     0,     0,     0,     0,    56,     0,     0,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,   266,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -101,  -170,  -170,
     115,  -170,  -170,  -170,  -170,  -170,  -170,    64,  -170,   141,
    -170,  -170,  -169,  -170,   192,   127,  -170,    57,  -153,  -170,
     -96,  -170,    -6,    11,   -37,   -84,     0,   178
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    53,    23,    24,    25,   132,   172,   137,
     138,   168,   197,   217,   228,   170,   202,   203,   119,   120,
     206,   149,   174,    54,    55,   112,   103,   150,   156,   184,
     157,   194,   158,    57,    58,    59,    60,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   108,   180,    34,    35,   113,   113,   113,   113,   113,
     152,   153,   185,   186,   187,    95,   188,   154,   146,    29,
     182,   183,   131,    32,   100,    39,    61,    45,    82,    26,
      27,   101,   185,   186,   187,    62,   188,   189,    88,   131,
     224,   182,   183,    33,    94,   225,   151,    33,    85,    36,
      37,   145,   222,   162,   163,   164,   165,   189,   179,   195,
      28,   104,   105,   126,   127,   190,    98,    99,    30,    45,
     242,    98,    99,    46,    47,    48,    49,   118,   155,   191,
      38,   192,   193,    98,    99,   190,    52,   211,   212,    33,
     177,   123,    65,   178,   210,    63,   121,   166,   167,   191,
      64,   192,   193,    98,    99,    45,     1,     2,     3,   124,
     125,    39,   198,   199,   200,    67,   111,     4,   207,   233,
     118,   208,   208,   136,    68,    33,    98,    99,   160,    39,
      40,    41,    42,    43,    44,   234,     5,     6,   208,     7,
     240,   244,   175,   178,   208,   121,   151,   173,    39,   181,
      69,     8,    70,     9,    71,    45,    72,    10,    73,    46,
      47,    48,    49,    80,    50,    74,    51,    40,    41,    42,
      43,    44,    52,    45,    75,    33,    76,    46,    47,    48,
      49,    89,    50,     1,     2,     3,    77,    78,   215,    79,
      52,    30,    45,    33,     4,    84,    46,    47,    48,    49,
      86,    50,   223,   175,  -117,    81,    90,    83,   175,    52,
      91,    92,    33,     5,     6,    87,     7,   114,   115,   116,
     117,   198,   199,   200,    93,    96,    97,   102,     8,   106,
       9,   107,   109,   175,    10,   110,   128,   129,   130,   131,
     134,   133,   135,   136,   139,   140,   147,   141,   205,   142,
     213,   227,   219,   216,   143,   144,   148,   220,   159,   161,
     235,   196,   209,   169,   176,   236,   204,   214,   218,   229,
     221,   226,   238,   230,   243,   231,   239,    66,   241,   245,
     246,   249,   247,   248,   201,   232,   171,   237,     0,   122
};

static const yytype_int16 yycheck[] =
{
       6,    85,   155,     3,     4,    89,    90,    91,    92,    93,
       3,     4,     7,     8,     9,    52,    11,    10,   119,    13,
       5,     6,    46,    62,    73,    18,    48,    62,    28,    12,
      13,    80,     7,     8,     9,    49,    11,    32,    38,    46,
     209,     5,     6,    82,    50,   214,   130,    82,    17,    12,
      13,    75,   205,    19,    20,    21,    22,    32,   154,   160,
      43,    61,    62,   100,   101,    60,    78,    79,    62,    62,
     239,    78,    79,    66,    67,    68,    69,    72,    71,    74,
      43,    76,    77,    78,    79,    60,    79,    72,   184,    82,
      72,    97,     0,    75,   178,    62,    96,    63,    64,    74,
      70,    76,    77,    78,    79,    62,    14,    15,    16,    98,
      99,    18,    51,    52,    53,    70,    73,    25,    72,    72,
      72,    75,    75,    62,    70,    82,    78,    79,   134,    18,
      37,    38,    39,    40,    41,    72,    44,    45,    75,    47,
      72,    72,   148,    75,    75,   145,   230,   147,    18,   155,
      70,    59,    70,    61,    70,    62,    70,    65,    70,    66,
      67,    68,    69,    62,    71,    70,    73,    37,    38,    39,
      40,    41,    79,    62,    70,    82,    70,    66,    67,    68,
      69,    71,    71,    14,    15,    16,    70,    70,   194,    70,
      79,    62,    62,    82,    25,    62,    66,    67,    68,    69,
      62,    71,   208,   209,    81,    27,    71,    29,   214,    79,
      71,    71,    82,    44,    45,    37,    47,    90,    91,    92,
      93,    51,    52,    53,    71,    49,    75,    81,    59,    71,
      61,    82,    71,   239,    65,    71,    62,    36,    71,    46,
      74,    62,    62,    62,    72,    72,    26,    72,    33,    72,
      18,    10,    54,    69,    72,    72,    71,    54,    72,    72,
      18,    71,    71,    75,    75,    32,    72,    71,    71,    62,
      75,    72,    62,    71,    55,    71,    71,    11,    72,    62,
      72,    72,    71,    62,   169,   221,   145,   230,    -1,    97
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    16,    25,    44,    45,    47,    59,    61,
      65,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    97,    98,    99,    12,    13,    43,    13,
      62,   130,    62,    82,   129,   129,    12,    13,    43,    18,
      37,    38,    39,    40,    41,    62,    66,    67,    68,    69,
      71,    73,    79,    96,   116,   117,   125,   126,   127,   128,
     129,    48,    49,    62,    70,     0,    85,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      62,   130,   129,   130,    62,    17,    62,   130,   129,    71,
      71,    71,    71,    71,   125,   127,    49,    75,    78,    79,
      73,    80,    81,   119,   129,   129,    71,    82,   128,    71,
      71,    73,   118,   128,   118,   118,   118,   118,    72,   111,
     112,   129,   117,   125,   126,   126,   127,   127,    62,    36,
      71,    46,   100,    62,    74,    62,    62,   102,   103,    72,
      72,    72,    72,    72,    72,    75,   100,    26,    71,   114,
     120,   128,     3,     4,    10,    71,   121,   123,   125,    72,
     125,    72,    19,    20,    21,    22,    63,    64,   104,    75,
     108,   112,   101,   129,   115,   125,    75,    72,    75,   123,
     121,   125,     5,     6,   122,     7,     8,     9,    11,    32,
      60,    74,    76,    77,   124,   100,    71,   105,    51,    52,
      53,   103,   109,   110,    72,    33,   113,    72,    75,    71,
     128,    72,   123,    18,    71,   125,    69,   106,    71,    54,
      54,    75,   121,   125,   115,   115,    72,    10,   107,    62,
      71,    71,   110,    72,    72,    18,    32,   120,    62,    71,
      72,    72,   115,    55,    72,    62,    72,    71,    62,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    87,
      88,    89,    90,    91,    92,    92,    93,    94,    95,    96,
      96,    97,    98,    99,   100,   100,   101,   102,   102,   103,
     104,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     107,   108,   108,   109,   109,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     116,   116,   117,   117,   117,   117,   117,   117,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   125,   125,   125,   126,   126,   126,   127,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   130
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       6,     6,     3,     3,     3,     2,     7,     3,     6,     1,
       1,     5,     4,     7,     2,     0,     0,     3,     1,     4,
       1,     1,     1,     1,     1,     1,     3,     0,     2,     0,
       2,     2,     0,     1,     3,     5,     8,    10,     1,     3,
       1,     4,     2,     0,     3,     5,     1,     3,     1,     1,
       3,     3,     4,     4,     4,     4,     4,     4,     1,     1,
       4,     1,     3,     1,     3,     1,     1,     3,     5,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     3,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 81 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_create_db((yyvsp[-1].val_s));}
#line 1492 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_create_tb((yyvsp[-1].def_table));}
#line 1498 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 83 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_create_idx((yyvsp[-1].ref_column));}
#line 1504 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 84 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_drop_idx((yyvsp[-1].ref_column));}
#line 1510 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 85 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_select((yyvsp[-1].select_argu));}
#line 1516 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 86 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_insert_row((yyvsp[-1].insert_argu));}
#line 1522 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 87 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_update((yyvsp[-1].update_argu));}
#line 1528 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 88 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_delete((yyvsp[-1].delete_argu));}
#line 1534 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_drop_db((yyvsp[-1].val_s));}
#line 1540 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 90 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_drop_table((yyvsp[-1].val_s));}
#line 1546 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 91 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_use_db((yyvsp[-1].val_s));}
#line 1552 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 92 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {if((yyvsp[-1].val_i)==1) execute_show_tables();}
#line 1558 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 93 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_desc_tables((yyvsp[-1].val_s));}
#line 1564 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 94 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {execute_sql_eof(); exit(0);}
#line 1570 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                if(strcasecmp("TABLES", (yyvsp[0].val_s))==0)
                    (yyval.val_i) = 1;
                else
                    report_sql_error("Unknown SHOW", (yyvsp[0].val_s));
            }
#line 1581 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 105 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    { (yyval.val_s)=(yyvsp[0].val_s); }
#line 1587 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 108 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.ref_column)=(column_ref*)malloc(sizeof(column_ref));(yyval.ref_column)->table=(yyvsp[-3].val_s);(yyval.ref_column)->column=(yyvsp[-1].val_s);}
#line 1593 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.ref_column)=(column_ref*)malloc(sizeof(column_ref));(yyval.ref_column)->table=(yyvsp[-3].val_s);(yyval.ref_column)->column=(yyvsp[-1].val_s);}
#line 1599 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s)=(yyvsp[0].val_s);}
#line 1605 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 117 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s)=(yyvsp[0].val_s);}
#line 1611 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s)=(yyvsp[0].val_s);}
#line 1617 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s)=(yyvsp[0].val_s);}
#line 1623 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 124 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                    (yyval.def_table) = (table_def*)malloc(sizeof(table_def));
                    (yyval.def_table)->name = (yyvsp[-4].val_s);
                    (yyval.def_table)->columns = (yyvsp[-2].def_column);
                    (yyval.def_table)->constraints = (yyvsp[-1].list);
                }
#line 1634 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 132 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s)=(yyvsp[0].val_s);}
#line 1640 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 135 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.select_argu) = (select_argu*)malloc(sizeof(select_argu));
                (yyval.select_argu)->column_expr = (yyvsp[-4].list);
                (yyval.select_argu)->tables = (yyvsp[-2].list);
                (yyval.select_argu)->where = (yyvsp[-1].expr_node);
            }
#line 1651 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 143 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(yyvsp[0].list);}
#line 1657 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 144 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=0;}
#line 1663 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 147 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.insert_argu)=(yyvsp[-2].insert_argu);(yyval.insert_argu)->values=(yyvsp[0].list);}
#line 1669 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 150 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.delete_argu) = (delete_argu*) malloc(sizeof(delete_argu));
                (yyval.delete_argu)->table = (yyvsp[-1].val_s);
                (yyval.delete_argu)->where = (yyvsp[0].expr_node);
            }
#line 1679 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 157 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.update_argu) = (update_argu*) malloc(sizeof(update_argu));
                (yyval.update_argu)->table = (yyvsp[-5].val_s);
                (yyval.update_argu)->column = (yyvsp[-3].ref_column);
                (yyval.update_argu)->val_expr = (yyvsp[-1].expr_node);
                (yyval.update_argu)->where = (yyvsp[0].expr_node);
            }
#line 1691 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 166 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(yyvsp[0].expr_node);}
#line 1697 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 167 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=NULL;}
#line 1703 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 172 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyvsp[0].def_column)->next = (yyvsp[-2].def_column); (yyval.def_column)=(yyvsp[0].def_column);}
#line 1709 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 173 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.def_column) = (yyvsp[0].def_column);}
#line 1715 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 176 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.def_column) = (column_defs*)malloc(sizeof(column_defs));
                (yyval.def_column)->name = (yyvsp[-3].val_s);
                (yyval.def_column)->type = (yyvsp[-2].val_i);
                (yyval.def_column)->size = (yyvsp[-1].val_i);
                (yyval.def_column)->flags = (yyvsp[0].val_i);
                (yyval.def_column)->next = NULL;
            }
#line 1728 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 186 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=COLUMN_TYPE_INT;}
#line 1734 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 187 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=COLUMN_TYPE_VARCHAR;}
#line 1740 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 188 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=COLUMN_TYPE_VARCHAR;}
#line 1746 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 189 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=COLUMN_TYPE_FLOAT;}
#line 1752 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 190 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=COLUMN_TYPE_FLOAT;fprintf(stderr, "Warning: type double is decayed to float.\n");}
#line 1758 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 191 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=COLUMN_TYPE_DATE;}
#line 1764 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 194 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i) = (yyvsp[-1].val_i);}
#line 1770 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 195 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=0;}
#line 1776 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 198 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i) = (yyvsp[-1].val_i) | (yyvsp[0].val_i);}
#line 1782 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 199 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=0;}
#line 1788 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 202 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i) = COLUMN_FLAG_NOTNULL;}
#line 1794 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 205 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list) = (yyvsp[0].list);}
#line 1800 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 206 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list) = NULL;}
#line 1806 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 209 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].t_constraint);}
#line 1812 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 210 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].t_constraint);(yyval.list)->next=(yyvsp[-2].list);}
#line 1818 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 213 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.t_constraint)=(table_constraint*)calloc(1,sizeof(table_constraint));
                (yyval.t_constraint)->type = CONSTRAINT_PRIMARY_KEY;
                (yyval.t_constraint)->values = (yyvsp[-1].list);
            }
#line 1828 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 218 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.t_constraint)=(table_constraint*)calloc(1,sizeof(table_constraint));
                (yyval.t_constraint)->type = CONSTRAINT_CHECK;
                (yyval.t_constraint)->column_name = (yyvsp[-5].val_s);
                (yyval.t_constraint)->values = (yyvsp[-2].list);
            }
#line 1839 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 224 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.t_constraint)=(table_constraint*)calloc(1,sizeof(table_constraint));
                (yyval.t_constraint)->type = CONSTRAINT_FOREIGN_KEY;
                (yyval.t_constraint)->column_name = (yyvsp[-6].val_s);
                (yyval.t_constraint)->foreign_table_name = (yyvsp[-3].val_s);
                (yyval.t_constraint)->foreign_column_name = (yyvsp[-1].val_s);
            }
#line 1851 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 234 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].val_s);}
#line 1857 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 235 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].val_s);(yyval.list)->next=(yyvsp[-2].list);}
#line 1863 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 238 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s) = (yyvsp[0].val_s); /*TODO*/}
#line 1869 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 239 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s) = (yyvsp[-3].val_s);/*TODO*/}
#line 1875 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 246 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[-1].list);}
#line 1881 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 247 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[-1].list);(yyval.list)->next=(yyvsp[-4].list);}
#line 1887 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 250 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].expr_node);}
#line 1893 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 251 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].expr_node);(yyval.list)->next=(yyvsp[-2].list);}
#line 1899 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 254 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].expr_node);}
#line 1905 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 255 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].expr_node);}
#line 1911 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 256 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].expr_node);(yyval.list)->next=(yyvsp[-2].list);}
#line 1917 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 257 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].expr_node);(yyval.list)->next=(yyvsp[-2].list);}
#line 1923 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 260 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));(yyval.expr_node)->left=(yyvsp[-1].expr_node);(yyval.expr_node)->op=OPER_SUM;}
#line 1929 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 261 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));(yyval.expr_node)->left=(yyvsp[-1].expr_node);(yyval.expr_node)->op=OPER_AVG;}
#line 1935 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 262 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));(yyval.expr_node)->left=(yyvsp[-1].expr_node);(yyval.expr_node)->op=OPER_MIN;}
#line 1941 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 263 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));(yyval.expr_node)->left=(yyvsp[-1].expr_node);(yyval.expr_node)->op=OPER_MAX;}
#line 1947 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 264 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));(yyval.expr_node)->left=(yyvsp[-1].expr_node);(yyval.expr_node)->op=OPER_COUNT;}
#line 1953 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 265 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));(yyval.expr_node)->left=NULL;(yyval.expr_node)->op=OPER_COUNT;}
#line 1959 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 268 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                        (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
                        (yyval.expr_node)->op=OPER_NONE;
                        (yyval.expr_node)->node_type=TERM_COLUMN;
                        (yyval.expr_node)->column=(yyvsp[0].ref_column);
                    }
#line 1970 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 276 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.insert_argu)=(insert_argu*)calloc(1,sizeof(insert_argu));(yyval.insert_argu)->table=(yyvsp[0].val_s);}
#line 1976 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 277 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.insert_argu)=(insert_argu*)calloc(1,sizeof(insert_argu));(yyval.insert_argu)->table=(yyvsp[-3].val_s);(yyval.insert_argu)->columns=(yyvsp[-1].list);}
#line 1982 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 280 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].ref_column);}
#line 1988 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 281 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.list)=(linked_list*)calloc(1,sizeof(linked_list));(yyval.list)->data=(yyvsp[0].ref_column);(yyval.list)->next=(yyvsp[-2].list);}
#line 1994 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 284 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(yyvsp[0].expr_node);}
#line 2000 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 285 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
                (yyval.expr_node)->left=(yyvsp[-2].expr_node);
                (yyval.expr_node)->right=(yyvsp[0].expr_node);
                (yyval.expr_node)->op=(yyvsp[-1].val_i);
            }
#line 2011 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 293 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    { (yyval.val_i) = OPER_AND; }
#line 2017 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 294 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    { (yyval.val_i) = OPER_OR; }
#line 2023 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 297 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
                (yyval.expr_node)->left=(yyvsp[-2].expr_node);
                (yyval.expr_node)->right=(yyvsp[0].expr_node);
                (yyval.expr_node)->op=(yyvsp[-1].val_i);
            }
#line 2034 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 304 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
                (yyval.expr_node)->left=(yyvsp[-2].expr_node);
                (yyval.expr_node)->op=OPER_ISNULL;
            }
#line 2044 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 309 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(yyvsp[-1].expr_node);}
#line 2050 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 310 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
                (yyval.expr_node)->left=(yyvsp[0].expr_node);
                (yyval.expr_node)->op=OPER_NOT;
            }
#line 2060 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 315 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
                (yyval.expr_node)->literal_b=1;
                (yyval.expr_node)->node_type=TERM_BOOL;
            }
#line 2070 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 320 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
                (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
                (yyval.expr_node)->literal_b=0;
                (yyval.expr_node)->node_type=TERM_BOOL;
            }
#line 2080 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 327 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i) = OPER_EQU;}
#line 2086 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 328 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=OPER_GT;}
#line 2092 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 329 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=OPER_LT;}
#line 2098 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 330 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=OPER_GE;}
#line 2104 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 331 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=OPER_LE;}
#line 2110 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 332 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=OPER_NEQ;}
#line 2116 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 333 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_i)=OPER_LIKE;}
#line 2122 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 336 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->left=(yyvsp[-2].expr_node);
            (yyval.expr_node)->right=(yyvsp[0].expr_node);
            (yyval.expr_node)->op=OPER_ADD;
        }
#line 2133 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 342 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->left=(yyvsp[-2].expr_node);
            (yyval.expr_node)->right=(yyvsp[0].expr_node);
            (yyval.expr_node)->op=OPER_DEC;
        }
#line 2144 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 348 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(yyvsp[0].expr_node);}
#line 2150 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 351 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->left=(yyvsp[-2].expr_node);
            (yyval.expr_node)->right=(yyvsp[0].expr_node);
            (yyval.expr_node)->op=OPER_MUL;
        }
#line 2161 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 357 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->left=(yyvsp[-2].expr_node);
            (yyval.expr_node)->right=(yyvsp[0].expr_node);
            (yyval.expr_node)->op=OPER_DIV;
        }
#line 2172 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 363 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node)=(yyvsp[0].expr_node);}
#line 2178 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 366 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->column=(yyvsp[0].ref_column);
            (yyval.expr_node)->node_type=TERM_COLUMN;
        }
#line 2188 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 371 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->literal_i=(yyvsp[0].val_i);
            (yyval.expr_node)->node_type=TERM_INT;
        }
#line 2198 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 376 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->literal_f=(yyvsp[0].val_f);
            (yyval.expr_node)->node_type=TERM_FLOAT;
        }
#line 2208 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 381 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->literal_s=(yyvsp[0].val_s);
            (yyval.expr_node)->node_type=TERM_DATE;
        }
#line 2218 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 386 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->literal_s=(yyvsp[0].val_s);
            (yyval.expr_node)->node_type=TERM_STRING;
        }
#line 2228 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 391 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->node_type=TERM_NULL;
        }
#line 2237 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 395 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {
            (yyval.expr_node)=(expr_node*)calloc(1,sizeof(expr_node));
            (yyval.expr_node)->left=(yyvsp[0].expr_node);
            (yyval.expr_node)->op=OPER_NEG;
        }
#line 2247 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 400 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.expr_node) = (yyvsp[-1].expr_node);}
#line 2253 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 403 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.ref_column)=(column_ref*)calloc(1,sizeof(column_ref));(yyval.ref_column)->table = NULL; (yyval.ref_column)->column = (yyvsp[0].val_s);}
#line 2259 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 404 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.ref_column)=(column_ref*)calloc(1,sizeof(column_ref));(yyval.ref_column)->table = (yyvsp[-2].val_s); (yyval.ref_column)->column = (yyvsp[0].val_s); }
#line 2265 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 407 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s) = (yyvsp[0].val_s);}
#line 2271 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 408 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    {(yyval.val_s) = (yyvsp[-1].val_s);}
#line 2277 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 411 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1646  */
    { (yyval.val_s)=(yyvsp[0].val_s); }
#line 2283 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
    break;


#line 2287 "/home/lizhe/codes/DB/mydb/build/src/sql_parser/sql.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 414 "/home/lizhe/codes/DB/mydb/src/sql_parser/sql.y" /* yacc.c:1906  */


int yyerror(const char *str)
{
    fprintf(stderr, "Error: %s\n", str);
    return 1;
}
int yywrap()
{
    return 1;
}
char start_parse(const char *expr_input)
{
    char ret;
    if(expr_input){
        YY_BUFFER_STATE my_string_buffer = yy_scan_string(expr_input);
        yy_switch_to_buffer( my_string_buffer ); // switch flex to the buffer we just created
        ret = yyparse();
        yy_delete_buffer(my_string_buffer );
    }else{
        ret = yyparse();
    }
    execute_sql_eof();
    return ret;
}
