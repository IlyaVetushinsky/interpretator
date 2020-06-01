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
#line 1 "BisonOb.y" /* yacc.c:339  */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdarg.h>
#include "LangOb.h"
extern FILE * yyin;
std::ifstream fin("Land.txt");
/* prototypes */
void create_land();
std::map<C, int> done_Land;
Node *opr(std::string n, int oper, int nops, ...);
Node *id(int i, int t);
Node *con(int value, int t);
void setlabel (int i ,Node *p);
void freeNode(Node *p);
int exec(Node *p);
Node* ex_find_er(Node *p1);
int exec_find_er(Node *p);
Node* building_var_left (Node* p, int level);
int building_var_right (Node* p, int level);
void print_Tree(Node *p, int level);
void init_VL();
void go_proc(VarNode* varn);
void go_proc_er(VarNode* varn);
int find_rec_right(VarNode* varn1,VarNode* varn2);
int find_rec_left(VarNode* varn1,VarNode* varn2);
int find_rec(VarNode* &varn1,VarNode* &varn2);
void push_Varlist(Node* p);
int find_var(Node* p);
void clear_id_store(std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >>& IdStore);
extern Node *np();
void l_ballance(Node* n);
int lb_ballance(Node* p);
void wrong_lbls();
int yylex();
void yyerror(char *s);
Node* fun(int t);
Node* moving(Node* p);
int dir;
C R_cord; 
std::map<C,int> Land;
std::vector<std::string> err_arr;
std::map<std::vector<int>,std::map<std::vector<int>,int>> VarStore;    
std::map<std::vector<int>,std::map<std::vector<int>,Node*>> ProcStore;   
std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >> IdStore;      
std::vector<std::vector<int>> Varlist;
std::map<int, Node*> addr;
char lbll = 0;


#line 122 "BisonOb.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "BisonOb.tab.h".  */
#ifndef YY_YY_BISONOB_TAB_H_INCLUDED
# define YY_YY_BISONOB_TAB_H_INCLUDED
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
    END = 258,
    INTEGER = 259,
    LOGIC = 260,
    LOGVAR = 261,
    INTVAR = 262,
    LABEL = 263,
    PROC = 264,
    WHILE = 265,
    PRINT = 266,
    GOTO = 267,
    PLS = 268,
    NP = 269,
    MF = 270,
    MB = 271,
    MR = 272,
    ML = 273,
    TP = 274,
    AS = 275,
    SN = 276,
    EQ = 277,
    INC = 278,
    DEC = 279,
    PARR = 280,
    UMINUS = 281
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 57 "BisonOb.y" /* yacc.c:355  */

	int iValue;                 /* integer value */
	int sIndex;                /* name *//////////////////////
	Node *nPtr;             /* node pointer */

#line 195 "BisonOb.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISONOB_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 212 "BisonOb.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  77

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    31,     2,     2,
      32,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,    22,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    24,    25,    26,
      27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,   110,   111,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     133,   134,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   154,   155,   156,   157,   158
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "END", "INTEGER", "LOGIC", "LOGVAR",
  "INTVAR", "LABEL", "PROC", "WHILE", "PRINT", "GOTO", "PLS", "NP", "MF",
  "MB", "MR", "ML", "TP", "AS", "SN", "';'", "':'", "EQ", "INC", "DEC",
  "PARR", "UMINUS", "'\\n'", "'@'", "'%'", "'('", "')'", "'{'", "'}'",
  "'['", "']'", "$accept", "program", "function", "stmt", "stmt_list",
  "expr", "fexpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    59,    58,   277,   278,   279,   280,   281,    10,
      64,    37,    40,    41,   123,   125,    91,    93
};
# endif

#define YYPACT_NINF -22

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-22)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,    10,    73,   -22,   -22,   -22,   -22,   -22,    73,   -22,
     154,   -22,   -22,   -22,   -22,   -22,   -22,   154,   154,   154,
     -22,   106,    73,   106,   -22,   147,     4,   -22,   154,    39,
     -22,   -22,   130,   -15,     7,   -22,    40,   -21,     0,    73,
     154,   154,   154,   -22,   154,   154,   -22,    -3,   -22,   -22,
      73,    73,   -22,   -22,    16,    19,   -22,   -18,   -18,   -22,
      72,   118,   -22,   -22,   -22,    12,    42,    23,    45,   -22,
     -22,   -22,    31,   -22,    35,   -22,   -22
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    22,    30,    31,    23,     0,    33,
       0,    34,    35,    36,    37,    38,    39,     0,     0,     0,
       5,     0,     0,     0,     3,     0,     0,    13,     0,     0,
      25,    26,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,    19,     0,     7,    32,
      29,     0,    12,    21,     0,     0,     8,    28,    27,    24,
       0,     0,    29,    11,    16,     0,     0,     0,     0,     9,
      10,    14,     0,    17,     0,    15,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,   -22,    -8,   -22,    -6,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    24,    36,    25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    40,    41,    42,    29,    41,    42,    40,    41,    42,
       3,    30,    31,    32,    35,    33,    54,    37,    50,    40,
      41,    42,    47,    34,    65,    38,    49,    67,    53,    66,
      62,    56,    68,    46,    57,    58,    59,    55,    60,    61,
      51,    71,    63,    64,     4,     5,     6,     7,     8,     9,
      72,    10,    73,    74,    11,    12,    13,    14,    15,    16,
      75,    40,    41,    42,    76,    17,    18,    19,    48,    20,
       0,     0,    21,     0,    22,    52,    23,     4,     5,     6,
       7,     8,     9,     0,    10,     0,     0,    11,    12,    13,
      14,    15,    16,     0,    40,    41,    42,     0,    17,    18,
      19,    69,    20,     0,     0,    21,     0,    22,     0,    23,
       4,     5,     6,     7,     0,     9,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
       0,    17,    18,    19,     4,     5,     6,     7,    28,     9,
      40,    41,    42,     0,    11,     0,     0,    70,     0,     0,
       0,     0,    40,    41,    42,    17,    18,    19,     4,     5,
       6,     7,    28,     9,     0,     0,     0,    39,    11,    40,
      41,    42,     0,     0,     0,     0,    43,    44,    45,    17,
      18,    19,     0,     0,     0,     0,    28
};

static const yytype_int8 yycheck[] =
{
       8,    22,    23,    24,    10,    23,    24,    22,    23,    24,
       0,    17,    18,    19,    22,    21,    37,    23,    33,    22,
      23,    24,    28,    21,     8,    23,    32,     8,    36,    13,
      33,    39,    13,    29,    40,    41,    42,    37,    44,    45,
      33,    29,    50,    51,     4,     5,     6,     7,     8,     9,
       8,    11,    29,     8,    14,    15,    16,    17,    18,    19,
      29,    22,    23,    24,    29,    25,    26,    27,    29,    29,
      -1,    -1,    32,    -1,    34,    35,    36,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    -1,    22,    23,    24,    -1,    25,    26,
      27,    29,    29,    -1,    -1,    32,    -1,    34,    -1,    36,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,     4,     5,     6,     7,    32,     9,
      22,    23,    24,    -1,    14,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,     4,     5,
       6,     7,    32,     9,    -1,    -1,    -1,    20,    14,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    25,
      26,    27,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    40,     0,     4,     5,     6,     7,     8,     9,
      11,    14,    15,    16,    17,    18,    19,    25,    26,    27,
      29,    32,    34,    36,    41,    43,    44,    41,    32,    43,
      43,    43,    43,    43,    44,    41,    42,    43,    44,    20,
      22,    23,    24,    29,    30,    31,    29,    43,    29,    43,
      33,    33,    35,    41,    37,    37,    41,    43,    43,    43,
      43,    43,    33,    41,    41,     8,    13,     8,    13,    29,
      29,    29,     8,    29,     8,    29,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      42,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    44,    44,    44,    44,    44
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     3,     3,     4,
       4,     4,     3,     2,     5,     6,     4,     5,     6,     2,
       1,     2,     1,     1,     3,     2,     2,     3,     3,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1
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
        case 2:
#line 76 "BisonOb.y" /* yacc.c:1646  */
    { 
				print_Tree((yyvsp[0].nPtr), 0);
				lb_ballance((yyvsp[0].nPtr));
				if (err_arr.size() != 0) {
					for (int i = 0; i < err_arr.size(); ++i) {
						std::cout << err_arr[i] << std::endl;
					}
					exit(0);
				}
				exec_find_er((yyvsp[0].nPtr));
				wrong_lbls();
				if (err_arr.size() != 0) {
					for (int i = 0; i < err_arr.size(); ++i) {
						std::cout << err_arr[i] << std::endl;
					}
					exit(0);
				}
				VarStore.clear();
				ProcStore.clear();
				clear_id_store(IdStore);
				exec((yyvsp[0].nPtr)); freeNode((yyvsp[0].nPtr));
				std::ofstream fout("done_Land.txt", std::ofstream::app);
				std::map<C, int>::iterator it;
				for (auto it = done_Land.begin(); it != done_Land.end(); ++it) {
					fout << it->first.X;
					fout << " ";
					fout << it->first.Y;
					fout << " ";
					std::cout << it->first.X << " " << it->first.Y << std::endl;
				}
				exit(0);}
#line 1383 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "BisonOb.y" /* yacc.c:1646  */
    {(yyval.nPtr) =  opr("\\n", '\n', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));/*ex($2); freeNode($2);*/ }
#line 1389 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 111 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = 0;}
#line 1395 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 115 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("\\n", '\n', 2, NULL, NULL); }
#line 1401 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("call", 'c', 1, (yyvsp[-1].nPtr)); }
#line 1407 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 117 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("print", PRINT, 1, (yyvsp[-1].nPtr)); }
#line 1413 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("<-", '=', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1419 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("@", '@', 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1425 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("%", '%', 2, (yyvsp[-3].nPtr), (yyvsp[-1].nPtr)); }
#line 1431 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 121 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("while", WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1437 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 122 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr)= (yyvsp[-1].nPtr); }
#line 1443 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "BisonOb.y" /* yacc.c:1646  */
    { setlabel((yyvsp[-1].sIndex),(yyvsp[0].nPtr)); (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1449 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("go to", GOTO, 2, (yyvsp[-3].nPtr), id((yyvsp[-1].sIndex),3));}
#line 1455 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("go to", GOTO, 2, (yyvsp[-4].nPtr), id((yyvsp[-1].sIndex),3));}
#line 1461 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("while", WHILE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1467 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("go to", GOTO, 2, (yyvsp[-3].nPtr), id((yyvsp[-1].sIndex),3));}
#line 1473 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("go to", GOTO, 2, (yyvsp[-4].nPtr), id((yyvsp[-1].sIndex),3));}
#line 1479 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 129 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr)= (yyvsp[-1].nPtr); }
#line 1485 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 133 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1491 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 134 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("\\n", '\n', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 1497 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 138 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = con((yyvsp[0].iValue), 1); }
#line 1503 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 139 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = id((yyvsp[0].sIndex),1); }
#line 1509 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 140 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("eq", EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1515 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 141 "BisonOb.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr("inc", INC, 1, (yyvsp[0].nPtr)); }
#line 1521 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 142 "BisonOb.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr("dec", DEC, 1, (yyvsp[0].nPtr)); }
#line 1527 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 143 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(":", ':', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1533 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 144 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(";", ';', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1539 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1545 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 146 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = con((yyvsp[0].iValue), 0); }
#line 1551 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 147 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = id((yyvsp[0].sIndex),0); }
#line 1557 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 148 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr("parr", PARR, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1563 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 149 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = id((yyvsp[0].sIndex),2); }
#line 1569 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 150 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = np(); }
#line 1575 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 154 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = fun(1); }
#line 1581 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 155 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = fun(2); }
#line 1587 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 156 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = fun(3); }
#line 1593 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 157 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = fun(4); }
#line 1599 "BisonOb.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 158 "BisonOb.y" /* yacc.c:1646  */
    { (yyval.nPtr) = fun(5); }
#line 1605 "BisonOb.tab.c" /* yacc.c:1646  */
    break;


#line 1609 "BisonOb.tab.c" /* yacc.c:1646  */
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
#line 163 "BisonOb.y" /* yacc.c:1906  */


Node* fun(int t){
	Node *p = new FunNode(t);
	return p;
}

Node *con(int value, int t) {
	Node *p = new ConNode(value, t, typeCon);
	return p;
}

Node *id(int i, int t) {
	Node *p = new VarNode(i, t, typeId);
	return p;
}

Node *opr(std::string n, int oper, int nops, ...) {
	va_list ap;
	Node *p = new OprNode(n, oper, nops, typeOpr);
	va_start(ap, nops);
	for (int i = 0; i < nops; i++)
		p->children.push_back(va_arg(ap, Node*));
	va_end(ap);
	return p;
}

Node* np() {
	Node* p = new Null();
	return p;
}


struct lp {
	int L_is;
	int G_is;
};

std::map<int, lp> t_lstore;

struct LQA {
	std::vector<int> Q;
	std::vector<int> A;
};

LQA L_qa;



void l_ballance(Node* p) {
	if (p) {
		if (p->label) {
			lp l = { 0,0 };
			t_lstore.emplace(p->label, l);
			std::map<int, lp>::iterator it;
			it = t_lstore.find(p->label);
			it->second.L_is = 1;
			
		}
		if (p->type == typeOpr) {
			OprNode* oprn = dynamic_cast<OprNode*>(p);
			if (oprn->oper == GOTO) {
				Node* n = oprn->children[1];
				VarNode* varn = dynamic_cast<VarNode*>(n);
				lp l = { 0,0 };
				t_lstore.emplace(varn->name, l);
				std::map<int, lp>::iterator it;
				it = t_lstore.find(varn->name);
				it->second.G_is = 1;
			}
			if (oprn->oper == '=') {
				l_ballance(oprn->children[0]);
				return;
			}
			for (int i = 0; i < oprn->nops; ++i) {
				l_ballance(oprn->children[i]);
			}
		}
	}
}

int lb_ballance(Node* p) {
	l_ballance(p);
	int k = 0;
	std::map<int, lp>::iterator it;
	for (auto it = t_lstore.begin(); it != t_lstore.end(); ++it) {
		if (it->second.L_is == 1) {
			//err_arr.push_back("Entering the procedure by the label from the outside");
			L_qa.Q.push_back(it->first);
		}
		if (it->second.G_is == 1 && it->second.L_is == 0) {
			err_arr.push_back("Label leads beyond procedure or Label with this name not declared");
			L_qa.A.push_back(it->first);
			++k;
		}
	}
	for (auto it = t_lstore.begin(); it != t_lstore.end(); ++it) {
		it->second = {0,0};
	}
	return k;
}

void wrong_lbls() {
	for (int i = 0; i< L_qa.Q.size(); ++i) {
		for (int j = 0;j< L_qa.A.size(); ++j)
			if (L_qa.Q[i] == L_qa.A[j]) {
				err_arr.push_back("Entering the procedure by the label from the outside");
				//err_arr.push_back(std::to_string(L_qa.A[j]));
			}
	}
}

void clear_id_store(std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >>& IdStore) {
	std::map < std::vector<int>, std::map < std::vector<int>, VarNode* >> ::iterator it;
	for (auto it = IdStore.begin(); it != IdStore.end(); ++it) {
		std::map < std::vector<int>, VarNode* >::iterator it1;
		for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
			it1->second->id_1.clear();
			it1->second->id_2.clear();
		}
	}
}

int find_var(Node* p) {
	VarNode* varn = dynamic_cast<VarNode*>(p);
	int t = 0;
	int a = 0;
	a = varn->ind.size();
	if (varn->vtype == 0) {
		t = 0;
		if (a)
			t = 3;
	}
	if (varn->vtype == 1) {
		t = 1;
		if (a) {
			t = 4;
		}
	}
	if (varn->vtype == 2) {
		t = 2;
		if (a)
			t = 5;
	}
	for (int i = 0; i < Varlist.size(); ++i) {
		for (int j = 0; j < Varlist[i].size(); ++j) {
			if (varn->name == Varlist[i][j] && i != t)
				return 1;
		}
	}
	return 0;
}

void push_Varlist(Node* p) {
	VarNode* varn = dynamic_cast<VarNode*>(p);
	int t = 0;
	if (varn->vtype == 0) {
		t = 0;
		if (varn->ind.size())
			t = 3;
	}
	if (varn->vtype == 1) {
		t = 1;
		if (varn->ind.size())
			t = 4;
	}
	if (varn->vtype == 2) {
		t = 2;
		if (varn->ind.size())
			t = 5;
	}
	Varlist[t].push_back(varn->name);
}

int find_rec_left(VarNode* varn1, VarNode* varn2) {
	int k = 0;
	for (int i = 0; i < varn1->id_2.size(); ++i) {
		if ((varn1->id_2[i])->id_2.size()) {
			k = find_rec_left(varn1->id_2[i], varn2);
		}
		else {
			VarNode* varn = varn1->id_2[i];
			if (ProcStore[{varn->vtype, varn->name}][varn->ind] == ProcStore[{varn2->vtype, varn2->name}][varn2->ind]) {
				k = 1;
			}
		}
	}
	return k;
}

int find_rec_right(VarNode* varn1, VarNode* varn2) {
	int k = 0;
	for (int i = 0; i < varn2->id_1.size(); ++i) {
		if ((varn2->id_1[i])->id_1.size()) {
			k = find_rec_right(varn1, varn2->id_1[i]);
		}
		else {
			VarNode* varn = varn2->id_1[i];
			if (ProcStore[{varn->vtype, varn->name}][varn->ind] == ProcStore[{varn1->vtype, varn1->name}][varn1->ind]) {
				k = 1;
			}
		}
	}
	return k;
}

int find_rec(VarNode* &varn1, VarNode* &varn2) {
	int k = 0;
	if (IdStore.find({ varn1->vtype, varn1->name }) != IdStore.end() && IdStore[{varn1->vtype, varn1->name}].find(varn1->ind) != IdStore[{varn1->vtype, varn1->name}].end()) {
		varn1 = IdStore[{varn1->vtype, varn1->name}][varn1->ind];
	}
	if (IdStore.find({ varn2->vtype, varn2->name }) != IdStore.end() && IdStore[{varn2->vtype, varn2->name}].find(varn2->ind) != IdStore[{varn2->vtype, varn2->name}].end()) {
		varn2 = IdStore[{varn2->vtype, varn2->name}][varn2->ind];
	}
	if (varn1 == varn2) {
		return 1;
	}
	k = find_rec_left(varn1, varn2);
	k = find_rec_right(varn1, varn2);
	return k;
}

void go_proc_er(VarNode* varn1) {
	if (IdStore.find({ varn1->vtype, varn1->name }) != IdStore.end() && IdStore[{varn1->vtype, varn1->name}].find(varn1->ind) != IdStore[{varn1->vtype, varn1->name}].end()) {
		varn1 = IdStore[{varn1->vtype, varn1->name}][varn1->ind];
	}
	for (int i = 0; i < varn1->id_1.size(); ++i) {
		if (varn1 == varn1->id_1[i]) {
			return ;
		}
		if ((varn1->id_1[i])->id_1.size()) {
			go_proc_er(varn1->id_1[i]);
		}
		VarNode* varn2 = varn1->id_1[i];
		Node* n = ProcStore[{varn2->vtype, varn2->name}][varn2->ind];
		if (!lb_ballance(n))
			ex_find_er(ProcStore[{varn2->vtype, varn2->name}][varn2->ind]);
	}
}


Node* moving(Node* p) {
	FunNode* f = dynamic_cast<FunNode*>(p);
	if (f->ftype == 1) {
		if (dir == 1) {
			C c = { R_cord.X + 1, R_cord.Y };
			if (Land.find(c) == Land.end()) {
				++R_cord.X;
				done_Land.emplace(R_cord, 0);
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}else if (dir == 2) {
			C c = { R_cord.X - 1, R_cord.Y };
			if (Land.find(c) == Land.end()) {
				--R_cord.X;
				done_Land.emplace(R_cord, 0);
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 3) {
			C c = { R_cord.X, R_cord.Y + 1 };
			if (Land.find(c) == Land.end()) {
				++R_cord.Y;
				done_Land.emplace(R_cord, 0);
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 4) {
			C c = { R_cord.X, R_cord.Y - 1 };
			if (Land.find(c) == Land.end()) {
				--R_cord.Y;
				done_Land.emplace(R_cord, 0);
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
	}else if (f->ftype == 2) {
		if (dir == 1) {
			C c = { R_cord.X - 1, R_cord.Y };
			if (Land.find(c) == Land.end()) {
				--R_cord.X;
				done_Land.emplace(R_cord, 0);
				dir = 2;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 2) {
			C c = { R_cord.X + 1, R_cord.Y };
			if (Land.find(c) == Land.end()) {
				++R_cord.X;
				dir = 1;
				done_Land.emplace(R_cord, 0);
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 3) {
			C c = { R_cord.X, R_cord.Y - 1 };
			if (Land.find(c) == Land.end()) {
				--R_cord.Y;
				done_Land.emplace(R_cord, 0);
				dir = 4;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 4) {
			C c = { R_cord.X, R_cord.Y + 1 };
			if (Land.find(c) == Land.end()) {
				++R_cord.Y;
				done_Land.emplace(R_cord, 0);
				dir = 3;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
	}
	else if (f->ftype == 3) {
		if (dir == 1) {
			C c = { R_cord.X, R_cord.Y - 1 };
			if (Land.find(c) == Land.end()) {
				--R_cord.Y;
				done_Land.emplace(R_cord, 0);
				dir = 4;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 2) {
			C c = { R_cord.X, R_cord.Y + 1 };
			if (Land.find(c) == Land.end()) {
				++R_cord.Y;
				done_Land.emplace(R_cord, 0);
				dir = 3;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 3) {
			C c = { R_cord.X + 1, R_cord.Y };
			if (Land.find(c) == Land.end()) {
				++R_cord.X;
				done_Land.emplace(R_cord, 0);
				dir = 1;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 4) {
			C c = { R_cord.X - 1, R_cord.Y };
			if (Land.find(c) == Land.end()) {
				--R_cord.X;
				done_Land.emplace(R_cord, 0);
				dir = 2;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
	}
	else 	if (f->ftype == 4) {
		if (dir == 1) {
			C c = { R_cord.X, R_cord.Y + 1};
			if (Land.find(c) == Land.end()) {
				++R_cord.Y;
				done_Land.emplace(R_cord, 0);
				dir = 3;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 2) {
			C c = { R_cord.X, R_cord.Y - 1 };
			if (Land.find(c) == Land.end()) {
				--R_cord.Y;
				done_Land.emplace(R_cord, 0);
				dir = 4;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 3) {
			C c = { R_cord.X -1 , R_cord.Y};
			if (Land.find(c) == Land.end()) {
				--R_cord.X;
				done_Land.emplace(R_cord, 0);
				dir = 2;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}
		else if (dir == 4) {
			C c = { R_cord.X + 1, R_cord.Y };
			if (Land.find(c) == Land.end()) {
				++R_cord.X;
				done_Land.emplace(R_cord, 0);
				dir = 1;
				return con(1, 0);
			}
			else {
				return con(0, 0);
			}
		}else 	if (f->ftype == 5) {
			//C c = { R_cord.X + 1, R_cord.Y };
			//if (Land.find(c) == Land.end())
			return con(0, 0);
		}
	}




}


Node* ex_find_er(Node* p1) {
	if (!p1) return nullptr;
	if (lbll == p1->label)
		lbll = 0;
	if (!lbll) {
		switch (p1->type) {
		case typeFun:  { return con(1, 0); }
		case typeN: { Null* n = dynamic_cast<Null*>(p1); return n; }
		case typeCon: {ConNode* conn = dynamic_cast<ConNode*>(p1); return conn; }
		case typeId: {VarNode* varn = dynamic_cast<VarNode*>(p1); return varn; }
		case typeOpr: {
			OprNode* p = dynamic_cast<OprNode*>(p1);
			switch (p->oper) {
			case WHILE: {Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1->type == typeN) {
					err_arr.push_back("No action operator cannot be a condition");
				}
				if (n2->type == typeN) {
					err_arr.push_back("No action operator cannot be a condition");
				}
				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*>(n1);
					if (!(VarStore.find({ varn1->vtype, varn1->name }) != VarStore.end() && VarStore[{varn1->vtype, varn1->name}].find(varn1->ind) != VarStore[{varn1->vtype, varn1->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					go_proc_er(varn1);
				}
				if (n2->type == typeId) {
					VarNode* varn2 = dynamic_cast<VarNode*>(n2);
					if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
						Node* n11 = con(0, 0);
						return n11;
					}
				}
				return nullptr; }
			case PRINT: {Node* n1 = ex_find_er(p->children[0]);
				if (n1->type == typeN) {
					err_arr.push_back("No action operator cannot be displayed");
				}
				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*>(n1);
					if (!(VarStore.find({ varn1->vtype, varn1->name }) != VarStore.end() && VarStore[{varn1->vtype, varn1->name}].find(varn1->ind) != VarStore[{varn1->vtype, varn1->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					if (varn1->vtype == 2) {
						err_arr.push_back("The procedure variable cannot be displayed");
					}
					go_proc_er(varn1);
				}
				Node* n11 = con(1, 0);
				return n11; 
			}
			case '\n': { ex_find_er(p->children[0]); return ex_find_er(p->children[1]); }
			case ':': {Node* n = building_var_left(p, 0);
				VarNode* varn = dynamic_cast<VarNode*>(n);
				return varn;
			}
			case ';': {Node* n0 = p;
				while (n0->children.size()!= 0 && n0->children[0]->type == typeOpr) {
					n0 = n0->children[0];
				}
				OprNode* oprn = dynamic_cast<OprNode*>(n0);
				if (oprn->oper == ';') {
					err_arr.push_back("Incorrect indexing mode, expected ':' after array name");
				}
				Node* n = building_var_left(p, 0);
				VarNode* varn = dynamic_cast<VarNode*>(n);
				return varn;
			}
			case '@': {
				Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1 == nullptr) {
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeN) {
					err_arr.push_back("np cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeCon) {
					err_arr.push_back("Constant cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeOpr) {
					err_arr.push_back("Operation cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				VarNode* varn1 = dynamic_cast<VarNode*>(n1);
				if (find_var(varn1)) {
					err_arr.push_back("A variable with this name already exists");
				}
				if (n2 == nullptr) {
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n2->type != typeId) {
					err_arr.push_back("The right value for identification can only be a procedure variabler");
				}
				else {
					VarNode* varn2 = dynamic_cast<VarNode*>(n2);
					if (!(ProcStore.find({ varn2->vtype, varn2->name }) != ProcStore.end() && ProcStore[{varn2->vtype, varn2->name}].find(varn2->ind) != ProcStore[{varn2->vtype, varn2->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					if (varn2->vtype != 2) {
						err_arr.push_back("The right value for identification can only be a procedure variabler");
						Node* n11 = con(1, 0);
						return n11;
					}
					int k = find_rec(varn1, varn2);
					Node* n11 = con(1, 0);
					if (!k) {
						varn1->id_1.push_back(varn2);
						varn2->id_2.push_back(varn1);
						IdStore[{varn1->vtype, varn1->name}][varn1->ind] = varn1;
						IdStore[{varn2->vtype, varn2->name}][varn2->ind] = varn2;
					}
					else {
						n11 = con(0, 0);
					}
					if (varn2->id_2.size() > 20) {
						int f = 0;
						for (int i = 0; i < varn2->id_2.size(); ++i) {
							if (varn2->id_2[i] == varn2->id_2[5])
								++f;
						}
						if (f > 10) {
							err_arr.push_back("Procedure identifier recursion");
							clear_id_store(IdStore);
						}
					}
					return n11;
				}
			}
			case '%': {
				Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1 == nullptr) {
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeN) {
					err_arr.push_back("np cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeCon) {
					err_arr.push_back("Constant cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n1->type == typeOpr) {
					err_arr.push_back("Operation cannot be an identifier");
					Node* n11 = con(0, 0);
					return n11;
				}
				VarNode* varn1 = dynamic_cast<VarNode*>(n1);
				if (n2 == nullptr) {
					Node* n11 = con(0, 0);
					return n11;
				}
				if (n2->type != typeId) {
					err_arr.push_back("The right value for identification can only be a procedure variabler");
				}
				else {
					VarNode* varn2 = dynamic_cast<VarNode*>(n2);
					if (!(ProcStore.find({ varn2->vtype, varn2->name }) != ProcStore.end() && ProcStore[{varn2->vtype, varn2->name}].find(varn2->ind) != ProcStore[{varn2->vtype, varn2->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					if (varn2->vtype != 2) {
						err_arr.push_back("The right value for identification can only be a procedure variabler");
						Node* n11 = con(1, 0);
						return n11;
					}
					int k = 0;
					if (IdStore.find({ varn1->vtype, varn1->name }) != IdStore.end() && IdStore[{varn1->vtype, varn1->name}].find(varn1->ind) != IdStore[{varn1->vtype, varn1->name}].end()) {
						varn1 = IdStore[{varn1->vtype, varn1->name}][varn1->ind];
					}
					if (IdStore.find({ varn2->vtype, varn2->name }) != IdStore.end() && IdStore[{varn2->vtype, varn2->name}].find(varn2->ind) != IdStore[{varn2->vtype, varn2->name}].end()) {
						varn2 = IdStore[{varn2->vtype, varn2->name}][varn2->ind];
					}
					for (int i = 0; i < varn1->id_1.size(); ++i) {
						if (ProcStore[{(varn1->id_1[i])->vtype, (varn1->id_1[i])->name}][varn1->id_1[i]->ind] == ProcStore[{varn2->vtype, varn2->name}][varn2->ind]) {
							varn1->id_1.erase(varn1->id_1.begin() + i);
							++k;
						}
					}
					for (int i = 0; i < varn2->id_2.size(); ++i) {
						if (ProcStore[{(varn2->id_2[i])->vtype, (varn2->id_2[i])->name}][varn2->id_2[i]->ind] == ProcStore[{varn1->vtype, varn1->name}][varn1->ind]) {
							varn2->id_2.erase(varn2->id_2.begin() + i);
							++k;
						}
					}
					Node* n11 = con(1, 0);
					if (!k) {
						n11 = con(0, 0);
					}
					return n11;
				}
			}
			case '=': { Node* n = ex_find_er(p->children[0]);
				Node* n2 = p->children[1];
				if (n == nullptr) {
					Node* n1 = con(0, 0);
					return n1;
				}
				if (n->type == typeN) {
					err_arr.push_back("Assigning a value to a np");
					Node* n1 = con(0, 0);
					return n1;
				}
				if (n->type == typeCon) {
					err_arr.push_back("Assigning a value to a constant");
					Node* n1 = con(0, 0);
					return n1;
				}
				if (n->type == typeOpr) {
					err_arr.push_back("Operation cannot be an lvalue");
					Node* n11 = con(0, 0);
					return n11;
				}
				VarNode* varn1 = dynamic_cast<VarNode*>(n);
				if (find_var(varn1)) {
					err_arr.push_back("A variable with this name already exists");
				}
				if (n2 == nullptr) {
					Node* n1 = con(0, 0);
					return n1;
				}
				if (n2->type == typeN) {
					err_arr.push_back("Assigning a np");
					Node* n1 = con(0, 0);
					return n1;
				}
				if (varn1->vtype == 2) {
					ProcStore[{varn1->vtype, varn1->name}][varn1->ind] = n2;
					push_Varlist(varn1);
					if (n2->type == typeOpr) {
						OprNode* oprn = dynamic_cast<OprNode*>(n2);
						if (oprn->oper == ':' || oprn->oper == ';') {
							n2 = building_var_left(p->children[1], 0);
							VarNode* varn2 = dynamic_cast<VarNode*>(n2);
							if ( varn2->vtype != 2) {
								err_arr.push_back("Non procedural variable cannot be assigned a procedural variable");
							}
							if (varn2->vtype == 2) {
								ProcStore[{varn1->vtype, varn1->name}][varn1->ind] = ProcStore[{varn2->vtype, varn2->name}][varn2->ind];
								go_proc_er(varn2);
							}
						} 
					}
				}
				else {
					if (n2->type == typeOpr) {
						OprNode* oprn = dynamic_cast<OprNode*>(n2);
						if (oprn->oper == '\n') {
							err_arr.push_back("A statement cannot be assigned to a non-procedural variable");
							Node* n1 = con(0, 0);
							return n1;
						}
					}
					n2 = ex_find_er(p->children[1]);
					if (n2->type == typeCon) {
						ConNode* conn = dynamic_cast<ConNode*>(n2);
						VarStore[{varn1->vtype, varn1->name}][varn1->ind] = conn->value;
						push_Varlist(varn1);
					}
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*>(n2);
						if (varn2->vtype == 2) {
							err_arr.push_back("Non procedural variable cannot be assigned a procedural variable");
						}
						VarStore[{varn1->vtype, varn1->name}][varn1->ind] = VarStore[{varn2->vtype, varn2->name}][varn2->ind];
						push_Varlist(varn1);
						go_proc_er(varn2);
					}
				}
				Node* n1 = con(1, 0);
				return n1;
			}

			case INC: { Node* n = ex_find_er(p->children[0]);
				if (n->type != typeId) {
					err_arr.push_back("Incrementing a constant");
					return n;
				}
				VarNode* varn = dynamic_cast<VarNode*> (n);
				if (varn->vtype != 1) {
					err_arr.push_back("Incrementing a non-integer variable");
				}
				if (!(VarStore.find({ varn->vtype, varn->name }) != VarStore.end() && VarStore[{varn->vtype, varn->name}].find(varn->ind) != VarStore[{varn->vtype, varn->name}].end())) {
					err_arr.push_back("Uninitialized memory access");
				}
				go_proc_er(varn);
				//inc
				return varn;
			}
			case DEC: { Node* n = ex_find_er(p->children[0]);
				if (n->type != typeId) {
					err_arr.push_back("Decrementing a constant");
					return n;
				}
				VarNode* varn = dynamic_cast<VarNode*> (n);
				if (varn->vtype != 1) {
					err_arr.push_back("Decrementing a non-integer variable");
				}
				if (!(VarStore.find({ varn->vtype, varn->name }) != VarStore.end() && VarStore[{varn->vtype, varn->name}].find(varn->ind) != VarStore[{varn->vtype, varn->name}].end())) {
					err_arr.push_back("Uninitialized memory access");
				}
				go_proc_er(varn);
				return varn;
			}
			case EQ: {Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*> (n1);
					if (!(VarStore.find({ varn1->vtype, varn1->name }) != VarStore.end() && VarStore[{varn1->vtype, varn1->name}].find(varn1->ind) != VarStore[{varn1->vtype, varn1->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					if (varn1->vtype == 2 && n2->type != typeN) {
						err_arr.push_back("A procedure can only be compared with a null operator (np)");
					}
					go_proc_er(varn1);
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*> (n2);
						if (varn1->vtype != varn2->vtype) {
							err_arr.push_back("Comparison of variables of different types");
						}
						if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
							err_arr.push_back("Uninitialized memory access");
						}
						go_proc_er(varn2);
						if (varn1->vtype != 2 && varn2->vtype != 2) {
							Node* n12 = con((VarStore[{varn1->vtype, varn1->name}][varn1->ind] == VarStore[{varn2->vtype, varn2->name}][varn2->ind]), 0);
							return n12;
						}
					}
					if (n2->type == typeCon) {
						ConNode* conn2 = dynamic_cast<ConNode*> (n2);
						if (varn1->vtype != conn2->ctype) {
							err_arr.push_back("Comparison of variables of different types");
						}
						if (varn1->vtype != 2 ) {
							Node* n12 = con((VarStore[{varn1->vtype, varn1->name}][varn1->ind] == conn2->value), 0);
							return n12;
						}
					}
				}
				if (n1->type == typeCon) {
					ConNode* conn1 = dynamic_cast<ConNode*> (n1);
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*> (n2);
						if (conn1->ctype != varn2->vtype) {
							err_arr.push_back("Comparison of variables of different types");
						}
						if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
							err_arr.push_back("Uninitialized memory access");
						}
						go_proc_er(varn2);
						if (varn2->vtype != 2) {
							Node* n12 = con((conn1->value == VarStore[{varn2->vtype, varn2->name}][varn2->ind]), 0);
							return n12;
						}
					}
					if (n2->type == typeCon) {
						ConNode* conn2 = dynamic_cast<ConNode*> (n2);
						if (conn1->ctype != conn2->ctype) {
							err_arr.push_back("Comparison of variables of different types");
						}
						int f = 0;
						if (conn1->value == conn2->value) {
							f = 1;
						}
						Node* n12 = con(f, 0);
						return n12;
					}
				}
				Node* n12 = con(0, 0);
				return n12;
			}
			case PARR: {Node* n1 = ex_find_er(p->children[0]);
				Node* n2 = ex_find_er(p->children[1]);
				if (n1->type == typeId) {
					VarNode* varn1 = dynamic_cast<VarNode*> (n1);
					if (!(VarStore.find({ varn1->vtype, varn1->name }) != VarStore.end() && VarStore[{varn1->vtype, varn1->name}].find(varn1->ind) != VarStore[{varn1->vtype, varn1->name}].end())) {
						err_arr.push_back("Uninitialized memory access");
					}
					go_proc_er(varn1);
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*> (n2);
						if (varn1->vtype || varn2->vtype) {
							err_arr.push_back("Applying a logical operation to a variable of a non-logical type");
						}
						if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
							err_arr.push_back("Uninitialized memory access");
						}
						go_proc_er(varn2);
						
					}
					if (n2->type == typeCon) {
						ConNode* conn2 = dynamic_cast<ConNode*> (n2);
						if (varn1->vtype || conn2->ctype) {
							err_arr.push_back("Applying a logical operation to a variable of a non-logical type");
						}
					}
				}
				if (n1->type == typeCon) {
					ConNode* conn1 = dynamic_cast<ConNode*> (n1);
					if (n2->type == typeId) {
						VarNode* varn2 = dynamic_cast<VarNode*> (n2);
						if (conn1->ctype || varn2->vtype) {
							err_arr.push_back("Applying a logical operation to a variable of a non-logical type");
						}
						if (!(VarStore.find({ varn2->vtype, varn2->name }) != VarStore.end() && VarStore[{varn2->vtype, varn2->name}].find(varn2->ind) != VarStore[{varn2->vtype, varn2->name}].end())) {
							err_arr.push_back("Uninitialized memory access");
						}
						go_proc_er(varn2);
					}
					if (n2->type == typeCon) {
						ConNode* conn2 = dynamic_cast<ConNode*> (n2);
						if (conn1->ctype || conn2->ctype) {
							err_arr.push_back("Applying a logical operation to a variable of a non-logical type");
						}
					}
				}
				Node* n11 = con(0, 0);
				return n11;

				}
				case 'c': { Node* n = ex_find_er(p->children[0]);
					if (n == nullptr) {
						Node* n1 = con(0, 0);
						return n1;
					}
					if (n->type == typeN) {
						err_arr.push_back("np cannot be an identifier");
						Node* n1 = con(0, 0);
						return n1;
					}
					if (n->type == typeOpr) {
						err_arr.push_back("Operation cannot be an rvalue and identifier");
						Node* n11 = con(0, 0);
						return n11;
					}
					if (n->type == typeCon) {
						ConNode* conn1 = dynamic_cast<ConNode*> (n);
						return conn1;
					}
					VarNode* varn = dynamic_cast<VarNode*>(n);
					go_proc_er(varn);
					return varn;
				}
				case GOTO: {  Node* n = ex_find_er(p->children[0]);
					if (n == nullptr) {
						Node* n1 = con(1, 0);
						return n1;
					}
					if (n->type == typeN) {
						err_arr.push_back("np cannot be a condition");
						Node* n1 = con(1, 0);
						return n1;
					}
					if (n->type == typeCon) {
						ConNode* conn1 = dynamic_cast<ConNode*> (n);
						VarNode* varn = dynamic_cast<VarNode*>(p->children[1]);
						if (addr.find(varn->name) == addr.end())
							err_arr.push_back("Label with this name not declared");
						if (conn1->value) {
							if (addr.find(varn->name) != addr.end())
								lbll = varn->name;
						}
					}
					if (n->type == typeId) {
						VarNode* varn = dynamic_cast<VarNode*>(n);
						if (varn->vtype == 2) {
							err_arr.push_back("A procedure variable cannot be a condition");
						}
						else if (VarStore[{varn->vtype, varn->name}][varn->ind]) {
							VarNode* varn = dynamic_cast<VarNode*>(p->children[1]);
							if (addr.find(varn->name) == addr.end())
								err_arr.push_back("Label with this name not declared");
							else
								lbll= varn->name;
						}
					}
					Node* n1 = con(1, 0);
					return n1;
				}
			}
		}
		}
	}
	else
	{
	switch (p1->type) {
		case typeN: {Node* n11 = con(0, 0);
			return n11;
		}
		case typeCon: {Node* n11 = con(0, 0);
			return n11;
		}
		case typeId: {Node* n11 = con(0, 0);
			return n11;
		}
		case typeOpr: {
			OprNode* p = dynamic_cast<OprNode*>(p1);
			switch (p->oper) {
			case WHILE: {
				int r = 0;
				Node* n;
				ex_find_er(p->children[1]);
				do {
					n = ex_find_er(p->children[0]);
					if (n->type == typeCon) {
						ConNode* conn = dynamic_cast<ConNode*> (n);
						r = conn->value;
					}
					else if (n->type == typeId) {
						VarNode* varn = dynamic_cast<VarNode*> (n);
						go_proc(varn);
						r = VarStore[{varn->vtype, varn->name}][varn->ind];
					}
				} while (r);
				Node* n11 = con(0, 0);
				return n11;
			}
			case '\n': {ex_find_er(p->children[0]); return ex_find_er(p->children[1]); }
			default: {Node* n11 = con(0, 0);
				return n11; }
			}
		}
	}
	Node* n11 = con(0, 0);
	return n11;
	}
}
int exec_find_er(Node* p)
{
	do
	{
		ex_find_er(p);
	} while (lbll);
	return 0;
}





Node* building_var_left(Node* p, int level) {
	int res;
	if (p->type == typeOpr) {
		if (p->children[0]->type == typeId) {
			VarNode* varn = dynamic_cast<VarNode*>(p->children[0]);
			int index = building_var_right(p->children[1], level + 1);
			varn->ind.push_back(index);
			return p->children[0];
		}
		else if (p->children[0]->type == typeOpr) {
			Node* p1 = building_var_left(p->children[0], level + 1);
			int index = building_var_right(p->children[1], level + 1);
			VarNode* varn = dynamic_cast<VarNode*>(p1);
			varn->ind.push_back(index);
			return p1;
		}
		else if (p->children[0]->type == typeCon) {
			err_arr.push_back("The array name must be a variable");
		}
		else {
			err_arr.push_back("The array name must be a variable");
		}
	}
	else if (p->type == typeId) {
		VarNode* varn = dynamic_cast<VarNode*>(p);
		return varn;
	}
	else if (p->type == typeCon) {
		ConNode* conn = dynamic_cast<ConNode*>(p);
		return conn;
	}
	else if (p->type == typeN) {
		Null* nn = dynamic_cast<Null*>(p);
		return nn;
	}
	Null* nn = dynamic_cast<Null*>(p);
	return nn;
}

int building_var_right(Node* p, int level) { //return conn
	if (p->type == typeOpr) {
		if (p->children[0]->type == typeId) {
			VarNode* varn = dynamic_cast<VarNode*>(p->children[0]);
			int p1 = building_var_right(p->children[1], level + 1);
			varn->ind.push_back(p1);
			return VarStore[{varn->vtype, varn->name}][varn->ind];
		}
		else if (p->children[0]->type == typeOpr) {
			Node* p1 = building_var_left(p->children[0], 0); //typeId
			int index = building_var_right(p->children[1], level + 1);
			VarNode* varn = dynamic_cast<VarNode*>(p1);
			varn->ind.push_back(index);
			return VarStore[{varn->vtype, varn->name}][varn->ind];
		}
		else if (p->children[0]->type == typeCon) {
			err_arr.push_back("The array name must be a variable");
		}
		else {
			err_arr.push_back("The array name must be a variable");
		}

	}
	else if (p->type == typeId) {
		VarNode* varn = dynamic_cast<VarNode*>(p);
		if (varn->vtype != 1 && level) {
			err_arr.push_back("Indexing with a non-integer variable");
		}
		return VarStore[{varn->vtype, varn->name}][varn->ind];
	}
	else if (p->type == typeCon) {
		ConNode* conn = dynamic_cast<ConNode*>(p);
		if (conn->ctype != 1 && level) {
			err_arr.push_back("Indexing with a non-integer variable");
		}
		return conn->value;
	}
	else {
		Null* nn = dynamic_cast<Null*>(p);
		err_arr.push_back("Indexing with a non-integer variable");
		return 0;
	}
	return 0;
}



void freeNode(Node *p) {
	int i;
	if (!p) return;
	if (p->type == typeOpr) {
		OprNode* oprn = dynamic_cast<OprNode*>(p);
		for (i = 0; i < oprn->nops; i++)
			freeNode(oprn->children[i]);
	}
	delete (p);
}

void setlabel (int i,Node *p)
{
	if (addr.find(i) != addr.end())
		err_arr.push_back("Label with this name is already declared");
	p->label = i;
	addr.insert({ i,p });
}

void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

void init_VL(){
	for (int i = 0; i<6; ++i){
		std::vector<int> a;
		a.push_back(-1);
		Varlist.push_back(a);
	}
}

void create_land() {
	int number1, number2;
	fin >> number1;
	fin >> number2;
	R_cord = { number1, number2 };
	while (fin >> number1 && fin >> number2) {
		C c = { number1, number2 };
		Land.emplace(c, 1);
	}
	dir = 1;
}

int main(void) {
	yyin = fopen ("./test.txt", "r");
	init_VL();
	std::ifstream fin("Land.txt");
	create_land();
	yyparse();
	fclose (yyin);
	return 0;
}

	






















