
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.ypp"

	#include "attributes.h"
	#include "output.hpp"
	#include <iostream>
	#include <ostream>
	#include <stdlib.h>
	#include <string>
	#include <string>
	#include <stack>
	
	
	using namespace std;

	extern int yylex();
	extern int yylineno;
	extern string saveyy;
	
	int yyerror(string message);
	void assertType(type_t t1, type_t t2);
	void assertNotType(type_t t1, type_t t2);
	void assertNumber(type_t t);
	void assertOneOfTypes(type_t t, type_t* ts, int len);
	
	void assertDef(string name);
	void assertNotDef(string name);
	bool isDef(string name);
	Row* findDef(string name);
	void insert(list<Row*>* rs, Row* r);
	void printList(list<Row*>* rs);
	Row* findFunction(string name);
	bool isFunction(string name);
	std::vector<const char*> castToStringVector(list<type_t>* l);
	bool compare(list<type_t>* l1, list<type_t>* l2);
	bool isVar(Row* r);
	
	int whileCounter = 0;
	type_t functionType = TYPE_NON;
	string functionName = "";
	bool is_main = false;
	int main_counter = 0;
	
	stack<Table*>* tables = new stack<Table*>();
	stack<int>* offsets = new stack<int>();
	Table* bottomTable = NULL;
	
	list<type_t>* formalTypes = new list<type_t>();
	list<string>* formalNames = new list<string>();
	
	stack<list<type_t>* > callsStack;
	list<type_t>* callParams;
	
	const char* typeNames[6] = {"NON", "BOOL", "INT", "BYTE", "STRING", "VOID"};


/* Line 189 of yacc.c  */
#line 128 "parser.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     INT = 259,
     BYTE = 260,
     B = 261,
     BOOL = 262,
     AND = 263,
     OR = 264,
     NOT = 265,
     TRUE = 266,
     FALSE = 267,
     RETURN = 268,
     IF = 269,
     ELSE = 270,
     WHILE = 271,
     SWITCH = 272,
     CASE = 273,
     BREAK = 274,
     COLON = 275,
     SC = 276,
     COMMA = 277,
     LPAREN = 278,
     RPAREN = 279,
     LBRACE = 280,
     RBRACE = 281,
     ASSIGN = 282,
     RELOP = 283,
     BINOP = 284,
     ID = 285,
     NUM = 286,
     STRING = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 202 "parser.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    11,    24,    25,    26,
      28,    30,    31,    32,    34,    36,    38,    39,    41,    45,
      48,    50,    53,    55,    57,    63,    67,    73,    77,    79,
      81,    83,    85,    87,    89,    94,    97,   100,   104,   108,
     114,   120,   123,   130,   134,   138,   142,   143,   144,   147,
     149,   156,   164,   170,   175,   176,   178,   182,   184,   186,
     188,   192,   196,   198,   200,   202,   204,   206,   208,   210,
     213,   217,   221,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    36,    -1,    -1,    37,    36,    -1,
      -1,    44,    41,    23,    45,    24,    25,    39,    42,    38,
      48,    43,    26,    -1,    -1,    -1,    30,    -1,    40,    -1,
      -1,    -1,    67,    -1,     3,    -1,    46,    -1,    -1,    47,
      -1,    47,    22,    46,    -1,    67,    40,    -1,    49,    -1,
      48,    49,    -1,    55,    -1,    50,    -1,    25,    42,    48,
      43,    26,    -1,    67,    40,    21,    -1,    67,    40,    27,
      68,    21,    -1,    42,    51,    43,    -1,    52,    -1,    56,
      -1,    53,    -1,    50,    -1,    51,    -1,    56,    -1,    40,
      27,    68,    21,    -1,    64,    21,    -1,    13,    21,    -1,
      13,    68,    21,    -1,    58,    24,    54,    -1,    58,    24,
      54,    15,    54,    -1,    59,    24,    60,    54,    61,    -1,
      19,    21,    -1,    57,    24,    25,    62,    26,    21,    -1,
      17,    23,    68,    -1,    14,    23,    68,    -1,    16,    23,
      68,    -1,    -1,    -1,    63,    62,    -1,    63,    -1,    18,
      31,    20,    54,    19,    21,    -1,    18,    31,     6,    20,
      54,    19,    21,    -1,    40,    23,    65,    66,    24,    -1,
      40,    23,    65,    24,    -1,    -1,    68,    -1,    68,    22,
      66,    -1,     4,    -1,     5,    -1,     7,    -1,    23,    68,
      24,    -1,    68,    29,    68,    -1,    40,    -1,    64,    -1,
      31,    -1,    69,    -1,    32,    -1,    11,    -1,    12,    -1,
      10,    68,    -1,    68,     8,    68,    -1,    68,     9,    68,
      -1,    68,    28,    68,    -1,    31,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    79,    96,    97,    98,   112,   123,   129,
     130,   135,   141,   162,   163,   164,   165,   166,   167,   168,
     174,   175,   177,   177,   179,   181,   189,   205,   207,   207,
     209,   209,   211,   211,   213,   227,   228,   229,   237,   238,
     239,   240,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   276,   294,   298,   301,   304,   305,   306,
     307,   308,   313,   318,   319,   320,   321,   322,   323,   324,
     328,   333,   338,   343
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL",
  "AND", "OR", "NOT", "TRUE", "FALSE", "RETURN", "IF", "ELSE", "WHILE",
  "SWITCH", "CASE", "BREAK", "COLON", "SC", "COMMA", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "ASSIGN", "RELOP", "BINOP", "ID", "NUM", "STRING",
  "$accept", "Program", "Init", "Funcs", "FuncDecl", "InsertLocals",
  "DoneSignature", "IdBuilt", "FuncName", "Slbrace", "Srbrace", "RetType",
  "Formals", "FormalsList", "FormalDecl", "Stmts", "Stmt", "BlockStmt",
  "VarDefStmt", "SingleVarDefStmtOfControlFlow", "SingleStmtOfControlFlow",
  "StmtOfControlFlow", "SingleStmt", "ControlFlowStmt", "SwitchStmt",
  "IfStmt", "WhileStmt", "Wlparen", "Wrparen", "CaseList", "CaseStat",
  "Call", "NewCall", "ExpList", "Type", "Exp", "NumByte", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    36,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      48,    48,    49,    49,    50,    51,    51,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    58,    59,    60,    61,    62,    62,
      63,    63,    64,    64,    65,    66,    66,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,    12,     0,     0,     1,
       1,     0,     0,     1,     1,     1,     0,     1,     3,     2,
       1,     2,     1,     1,     5,     3,     5,     3,     1,     1,
       1,     1,     1,     1,     4,     2,     2,     3,     3,     5,
       5,     2,     6,     3,     3,     3,     0,     0,     2,     1,
       6,     7,     5,     4,     0,     1,     3,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     5,     1,    14,    57,    58,    59,     2,     5,
       0,    13,     4,     9,    10,     0,    16,     0,    15,    17,
       0,     0,     0,    19,     8,    18,    11,     7,     0,     0,
       0,     0,     0,     0,    11,     0,    12,    20,    23,    32,
      22,    33,     0,     0,     0,     0,     0,     0,    67,    68,
      36,     0,    64,    66,    62,    63,     0,    65,     0,     0,
       0,    41,     0,    54,     0,     0,    21,     0,    11,    46,
      35,     0,    69,     0,    73,     0,     0,    37,     0,     0,
      44,    45,    43,    12,     0,     0,     6,     0,     0,    31,
      28,    30,    38,    29,    11,    25,     0,    60,    70,    71,
      72,    61,     0,    53,     0,    55,    34,     0,     0,    49,
      12,    11,    47,     0,    24,    52,     0,     0,     0,    48,
      27,    39,    40,    26,    56,     0,    11,    42,    11,     0,
       0,     0,     0,    50,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    28,    26,    54,    15,    88,
      65,    10,    17,    18,    19,    36,    37,    89,    39,    90,
      91,    92,    40,    93,    42,    43,    44,    94,   122,   108,
     109,    55,    84,   104,    46,   105,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int16 yypact[] =
{
     -92,    11,    60,   -92,   -92,   -92,   -92,   -92,   -92,    60,
     -13,   -92,   -92,   -92,   -92,     1,    73,    -2,   -92,     6,
     -13,     7,    73,   -92,   -92,   -92,   -92,   -92,    81,    98,
      10,    16,    19,     2,   -92,   -14,    81,   -92,   -92,   -92,
     -92,   -92,    21,    25,    29,    13,   -13,   112,   -92,   -92,
     -92,   112,    51,   -92,    43,   -92,   128,   -92,   112,   112,
     112,   -92,    81,   -92,   112,    42,   -92,    54,   161,   -92,
     -92,     0,   138,    22,   -92,   112,   112,   -92,   112,   112,
     138,   138,   138,    81,   102,   130,   -92,    63,    73,   -92,
     -92,   -92,    75,   -92,   161,   -92,   112,   -92,   138,   138,
     -92,   -92,    56,   -92,    69,   132,   -92,    65,    77,    63,
     -92,   161,   -92,   144,   -92,   -92,   112,    -1,    70,   -92,
     -92,   -92,   -92,   -92,   -92,    79,   161,   -92,   161,    86,
      88,    94,    96,   -92,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,   111,   -92,   -92,   -92,   -10,   -92,   -18,
     -81,   -92,   -92,   105,   -92,    83,   -35,   -22,    62,   -92,
     -92,   -91,   -92,   -21,   -92,   -92,   -92,   -92,   -92,    39,
     -92,   -24,   -92,    15,    67,    -4,   -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,    66,   102,   112,    45,   125,    38,    41,    27,    63,
      23,     3,    45,    64,    38,    41,    62,    13,    35,   126,
     121,    95,    21,    61,    16,    56,    35,    96,    22,   120,
      75,    76,    24,    58,    70,   129,    71,   130,    45,    59,
      38,    41,    60,    72,    45,    67,    97,    73,    66,    68,
      78,    79,    35,    69,    80,    81,    82,    74,    35,    45,
      85,    38,    41,     4,     5,     6,    63,     7,    86,    11,
      45,    98,    99,    35,   100,   101,    11,     5,     6,    87,
       7,   107,   114,    20,    35,     5,     6,    45,     7,    20,
     111,   127,   113,   115,    29,    30,   117,    31,    32,   128,
      33,    35,    45,   118,    45,   131,    34,   132,    47,    48,
      49,    13,    47,    48,    49,   133,    35,   134,    35,    50,
      12,    51,    47,    48,    49,    51,   103,    25,    13,    52,
      53,   124,    13,    52,    53,    51,    75,    76,    75,    76,
      75,    76,    13,    52,    53,    83,    75,    76,   119,    77,
     110,   106,    75,    76,   116,     0,    78,    79,    78,    79,
      78,    79,     0,     0,     0,   123,    78,    79,     0,     0,
       0,     0,    78,    79,    29,    30,     0,    31,    32,     0,
      33,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,    13
};

static const yytype_int16 yycheck[] =
{
      10,    36,    83,    94,    28,     6,    28,    28,    26,    23,
      20,     0,    36,    27,    36,    36,    34,    30,    28,    20,
     111,    21,    24,    21,    23,    29,    36,    27,    22,   110,
       8,     9,    25,    23,    21,   126,    46,   128,    62,    23,
      62,    62,    23,    47,    68,    24,    24,    51,    83,    24,
      28,    29,    62,    24,    58,    59,    60,     6,    68,    83,
      64,    83,    83,     3,     4,     5,    23,     7,    26,     2,
      94,    75,    76,    83,    78,    79,     9,     4,     5,    25,
       7,    18,    26,    16,    94,     4,     5,   111,     7,    22,
      15,    21,    96,    24,    13,    14,    31,    16,    17,    20,
      19,   111,   126,    26,   128,    19,    25,    19,    10,    11,
      12,    30,    10,    11,    12,    21,   126,    21,   128,    21,
       9,    23,    10,    11,    12,    23,    24,    22,    30,    31,
      32,   116,    30,    31,    32,    23,     8,     9,     8,     9,
       8,     9,    30,    31,    32,    62,     8,     9,   109,    21,
      88,    21,     8,     9,    22,    -1,    28,    29,    28,    29,
      28,    29,    -1,    -1,    -1,    21,    28,    29,    -1,    -1,
      -1,    -1,    28,    29,    13,    14,    -1,    16,    17,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,     0,     3,     4,     5,     7,    36,    37,
      44,    67,    36,    30,    40,    41,    23,    45,    46,    47,
      67,    24,    22,    40,    25,    46,    39,    42,    38,    13,
      14,    16,    17,    19,    25,    40,    48,    49,    50,    51,
      55,    56,    57,    58,    59,    64,    67,    10,    11,    12,
      21,    23,    31,    32,    40,    64,    68,    69,    23,    23,
      23,    21,    42,    23,    27,    43,    49,    24,    24,    24,
      21,    40,    68,    68,     6,     8,     9,    21,    28,    29,
      68,    68,    68,    48,    65,    68,    26,    25,    42,    50,
      52,    53,    54,    56,    60,    21,    27,    24,    68,    68,
      68,    68,    43,    24,    66,    68,    21,    18,    62,    63,
      51,    15,    54,    68,    26,    24,    22,    31,    26,    62,
      43,    54,    61,    21,    66,     6,    20,    21,    20,    54,
      54,    19,    19,    21,    21
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 61 "parser.ypp"
    { 
			if ( main_counter == 0 ) {
				output::errorMainMissing();
				exit(0);
			}
			
		//while(stack<Table*>::iterator it = tables->begin();it!=tables->end();it++) {	
		//	}
			
			output::endScope();
			list<Row*>::iterator it = (tables->top()->rows)->begin();
			++it;
			++it;
			for(; it!=(tables->top()->rows)->end();it++) {
				string fType = output::makeFunctionType((typeNames[(*it)->type]),castToStringVector((*it)->params));
				output::printID(((*it)->name).c_str(),0,fType.c_str());
			}
		;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 79 "parser.ypp"
    {
	bottomTable = new Table();
	// Add lib functions
	Row* print = new Row(TYPE_VOID, "print", NULL);
	list<type_t>* params = new list<type_t>();
	params->push_back(TYPE_STRING);
	print->setParams(params);
	(bottomTable->rows)->push_back(print);
	Row* printi = new Row(TYPE_VOID, "printi", NULL);
	list<type_t>* params2 = new list<type_t>();
	params2->push_back(TYPE_INT);
	printi->setParams(params2);
	(bottomTable->rows)->push_back(printi);
	
	tables->push(bottomTable);
	offsets->push(0);
;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 96 "parser.ypp"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 97 "parser.ypp"
    { if (saveyy != "") yyerror(""); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 98 "parser.ypp"
    {
				if (is_main) {
					if ( main_counter > 0 ) {
						yyerror(""); // TODO: Check if correct
					}
					main_counter++;
					if ( functionType != TYPE_VOID ) {
						output::errorMainMissing(); // TODO: Check if correct
						exit(0);
					}
				}				
				functionType = TYPE_NON;
				functionName = "";
			;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 112 "parser.ypp"
    {
	int i = -1;
	list<string>::iterator itN = formalNames->begin();
	list<type_t>::iterator itT = formalTypes->begin();
	
	for (; itN != formalNames->end(); ++itN, ++itT) {
		Row* r = new Row((*itT), (*itN), &(i));
		insert((tables->top())->rows, r);
		i--;
	}
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 123 "parser.ypp"
    {
		Row* r = new Row(functionType, functionName, NULL);
		r->setParams(formalTypes);
		insert((tables->top())->rows, r);
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 129 "parser.ypp"
    { (yyval).name = (yyvsp[(1) - (1)]).name; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 130 "parser.ypp"
    {
			(yyval).name = (yyvsp[(1) - (1)]).name;
			functionName = (yyvsp[(1) - (1)]).name;
			is_main = ((yyvsp[(1) - (1)]).name == "main");
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 135 "parser.ypp"
    {
		Table* t = new Table();
		t->parent = tables->top();
		tables->push(t);
		offsets->push(offsets->top());
	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 141 "parser.ypp"
    {
	output::endScope();
	list<Row*>::iterator ir = ((tables->top()->rows)->begin());
	for(; ir!=(tables->top()->rows)->end();ir++)
		output::printID(((*ir)->name).c_str(),*((*ir)->offset),(typeNames[(*ir)->type]));

	tables->pop();
	offsets->pop();
	
	saveyy = "";
	
	if(is_main) {
		if( formalTypes->size()>0 && (*(formalTypes->begin())) != TYPE_VOID ) {
			output::errorMainMissing();
			exit(0);
		}
	}
	
	formalTypes->clear();
	formalNames->clear();
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 162 "parser.ypp"
    { (yyval).type = (yyvsp[(1) - (1)]).type; functionType = (yyval).type; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 163 "parser.ypp"
    { (yyval).type = TYPE_VOID; functionType = (yyval).type; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 164 "parser.ypp"
    {  ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 165 "parser.ypp"
    { formalTypes->push_back(TYPE_VOID); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 166 "parser.ypp"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 167 "parser.ypp"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 168 "parser.ypp"
    {
				(yyval).type = (yyvsp[(1) - (2)]).type;
				(yyval).name = (yyvsp[(2) - (2)]).name;
				formalTypes->push_back((yyvsp[(1) - (2)]).type);
				formalNames->push_back((yyvsp[(2) - (2)]).name);
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 174 "parser.ypp"
    {;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 175 "parser.ypp"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 179 "parser.ypp"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 181 "parser.ypp"
    {
			Row* r = new Row((yyvsp[(1) - (3)]).type, (yyvsp[(2) - (3)]).name, &(offsets->top()));
			Table* top = tables->top();
			list<Row*>* rs = top->rows;
			insert(rs, r);
			offsets->pop();
			offsets->push(*(r->offset) + 1);
		;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 189 "parser.ypp"
    {
			assertNotDef((yyvsp[(2) - (5)]).name);
			if ((yyvsp[(1) - (5)]).type == TYPE_INT) {
				type_t ts[2] = {TYPE_INT, TYPE_BYTE};
				assertOneOfTypes((yyvsp[(4) - (5)]).type, ts, 2);
			} else {
				assertType((yyvsp[(1) - (5)]).type, (yyvsp[(4) - (5)]).type);
			}
			Row* r = new Row((yyvsp[(1) - (5)]).type, (yyvsp[(2) - (5)]).name, &(offsets->top()));
			Table* top = tables->top();
			list<Row*>* rs = top->rows;
			insert(rs, r);
			offsets->pop();
			offsets->push(*(r->offset) + 1); 
		;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 213 "parser.ypp"
    {
			assertDef((yyvsp[(1) - (4)]).name);
			Row* def = findDef((yyvsp[(1) - (4)]).name);
			if (!isVar(def)) {
				output::errorUndef(yylineno, ((yyvsp[(1) - (4)]).name).c_str());
				exit(0);
			}
			if (def->type == TYPE_INT) {
				type_t ts[2] = {TYPE_INT, TYPE_BYTE};
				assertOneOfTypes((yyvsp[(3) - (4)]).type, ts, 2);
			} else {
				assertType(def->type, (yyvsp[(3) - (4)]).type);
			}
		;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 227 "parser.ypp"
    { ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 228 "parser.ypp"
    { assertType(functionType, TYPE_VOID); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 229 "parser.ypp"
    { 
			assertNotType(functionType, TYPE_VOID); 
			if (functionType == TYPE_INT)
				assertNumber((yyvsp[(2) - (3)]).type);
			else 
				assertType(functionType, (yyvsp[(2) - (3)]).type); 
			
		;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 237 "parser.ypp"
    {;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 238 "parser.ypp"
    { ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 239 "parser.ypp"
    { ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 240 "parser.ypp"
    {
			if(whileCounter == 0) {
				output::errorUnexpectedBreak(yylineno);
				exit(0);
			}
		;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 247 "parser.ypp"
    {assertNumber((yyvsp[(3) - (3)]).type);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 248 "parser.ypp"
    { assertType((yyvsp[(3) - (3)]).type, TYPE_BOOL); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 249 "parser.ypp"
    { assertType((yyvsp[(3) - (3)]).type, TYPE_BOOL); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 250 "parser.ypp"
    {whileCounter += 1;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 251 "parser.ypp"
    {whileCounter -= 1;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 252 "parser.ypp"
    {;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 253 "parser.ypp"
    {;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 254 "parser.ypp"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 255 "parser.ypp"
    {;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 256 "parser.ypp"
    {
		Row* r = findFunction((yyvsp[(1) - (5)]).name);
		if (r == NULL) {
			output::errorUndefFunc(yylineno, ((yyvsp[(1) - (5)]).name).c_str());
			exit(0);
		}
		
		(yyval).type = r->type;
		(yyval).name = r->name;
			
		list<type_t>::iterator it = callParams->begin();
		
		if (!compare(callParams, r->params)) {
			output::errorPrototypeMismatch(yylineno, ((yyvsp[(1) - (5)]).name).c_str(), castToStringVector(r->params));
			exit(0);
		}
		callParams->clear();		
		callsStack.pop();
		callParams = callsStack.size() > 0 ? callsStack.top() : NULL;
	 ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 276 "parser.ypp"
    {
		Row* r = findFunction((yyvsp[(1) - (4)]).name);
		if (r == NULL) {
			output::errorUndefFunc(yylineno, ((yyvsp[(1) - (4)]).name).c_str());
			exit(0);
		}
		(yyval).type = r->type;
		(yyval).name = (yyvsp[(1) - (4)]).name;
		callParams->push_back(TYPE_VOID);
		if (!compare(callParams, r->params)) {
			output::errorPrototypeMismatch(yylineno, ((yyvsp[(1) - (4)]).name).c_str(), castToStringVector(r->params));
			exit(0);
		}
		
		callParams->clear();
		callsStack.pop();
		callParams = callsStack.size() > 0 ? callsStack.top(): new list<type_t>();
	 ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 294 "parser.ypp"
    {
	callParams = new list<type_t>();
	callsStack.push(callParams);
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 298 "parser.ypp"
    {
			callParams->push_front((yyvsp[(1) - (1)]).type);
		;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 301 "parser.ypp"
    {
			callParams->push_front((yyvsp[(1) - (3)]).type);
		;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 304 "parser.ypp"
    {(yyval).type = TYPE_INT;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 305 "parser.ypp"
    {(yyval).type = TYPE_BYTE;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 306 "parser.ypp"
    {(yyval).type = TYPE_BOOL;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 307 "parser.ypp"
    {(yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 308 "parser.ypp"
    {
			assertNumber((yyvsp[(1) - (3)]).type);
			assertNumber((yyvsp[(3) - (3)]).type);
			(yyval).type = ((yyvsp[(1) - (3)]).type == TYPE_INT || (yyvsp[(3) - (3)]).type == TYPE_INT) ? TYPE_INT : TYPE_BYTE;
		;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 313 "parser.ypp"
    { 
		assertDef((yyvsp[(1) - (1)]).name); 
		Row* r = findDef((yyvsp[(1) - (1)]).name);
		(yyval).type = r->type;
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 318 "parser.ypp"
    { ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 319 "parser.ypp"
    {;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 320 "parser.ypp"
    {;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 321 "parser.ypp"
    {(yyval).type = TYPE_STRING;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 322 "parser.ypp"
    {(yyval).type = TYPE_BOOL;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 323 "parser.ypp"
    {(yyval).type = TYPE_BOOL;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 324 "parser.ypp"
    {
			assertType((yyvsp[(2) - (2)]).type, TYPE_BOOL);
			(yyval).type = TYPE_BOOL;
		;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 328 "parser.ypp"
    {
			assertType((yyvsp[(1) - (3)]).type, TYPE_BOOL);
			assertType((yyvsp[(3) - (3)]).type, TYPE_BOOL);
			(yyval).type = TYPE_BOOL;
		;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 333 "parser.ypp"
    {
			assertType((yyvsp[(1) - (3)]).type, TYPE_BOOL);
			assertType((yyvsp[(3) - (3)]).type, TYPE_BOOL);
			(yyval).type = TYPE_BOOL;
		;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 338 "parser.ypp"
    {
			assertNumber((yyvsp[(1) - (3)]).type);
			assertNumber((yyvsp[(3) - (3)]).type);
			(yyval).type = TYPE_BOOL;
		;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 343 "parser.ypp"
    { 
			int val = atoi(((yyvsp[(1) - (2)]).name).c_str());
			if (val < 0 || val > 255) {
				char ret = val;
				output::errorByteTooLarge(yylineno, ((yyvsp[(1) - (2)]).name).c_str());
				exit(0);
			}
			(yyval).type = TYPE_BYTE;
		;}
    break;



/* Line 1455 of yacc.c  */
#line 2175 "parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 352 "parser.ypp"


int main()
{
	yyparse();
}

int yyerror(string message)
{
	output::errorSyn(yylineno);
	exit(0);
}

void assertType(type_t t1, type_t t2) {
	if(t1 != t2) {
		output::errorMismatch(yylineno);
		exit(0);
	}
	return;
}

void assertNotType(type_t t1, type_t t2) {
	if(t1 == t2) {
		output::errorMismatch(yylineno);
		exit(0);
	}
	return;
}

void assertNumber(type_t t) {
	assertNotType(t, TYPE_STRING);
	assertNotType(t, TYPE_BOOL);
}

void assertOneOfTypes(type_t t, type_t* ts, int len) {
	for (int i=0; i<len; i++)
		if (t == ts[i])
			return;
		
	output::errorMismatch(yylineno);
	exit(0);
}

Row* findDef(string name) {
	Table* it = tables->top();
	if (it == NULL) {
		return NULL;
	}
	for (; it != NULL; it = it->parent)	
		for (list<Row*>::iterator ir = (it->rows)->begin(); ir != (it->rows)->end(); ++ir) {
			if ( (*ir)->name == name ) {
				return (*ir);
			}
		}
	return NULL;
}

Row* findFunction(string name) {
	for (list<Row*>::iterator ir = (bottomTable->rows)->begin(); ir != (bottomTable->rows)->end(); ++ir) {
		if ( (*ir)->name == name ) {
			return (*ir);
		}
	}
	return NULL;
}

bool isFunction(string name) {
	Row* r = findFunction(name);
	return r != NULL;
}

bool isDef(string name) {
	Row* r = findDef(name);
	return r != NULL;
}

void assertNotDef(string name) {
	if (isDef(name)) {
		output::errorDef(yylineno, name.c_str());
		exit(0);
	}
}

void assertDef(string name) {
	if (!isDef(name)) {
		output::errorUndef(yylineno, name.c_str());
		exit(0);
	}
}

bool isVar(Row* r) {
	return (r->offset != NULL); 
}

void printList(list<Row*>* rs) {
	if (rs == NULL)
		return;
	cout << "Rows: " << endl;
	for (list<Row*>::iterator it=rs->begin(); it!=rs->end(); ++it) {
		//if (it == NULL)
			//continue;
		//std::cout << ' ' << (*it)->name;
	}
	cout << "\nEnd" << endl;
}

void insert(list<Row*>* rs, Row* r) {
	assertNotDef(r->name);
	rs->push_back(r);
}

bool compare(list<type_t>* l1, list<type_t>* l2) {
	if (l1 == NULL || l2 == NULL) {
		return false;
	}
		
	if(l1->size() != l2->size()){
		return false;
	}
	
	list<type_t>::iterator itLeft = l1->begin();
	list<type_t>::iterator itRight = l2->begin();

	for (; itLeft != l1->end(); ++itLeft, ++itRight) {
		
		if(*itRight == TYPE_INT){
			if ( !(*itLeft == TYPE_INT || *itLeft == TYPE_BYTE) ) 
				return false;
		} else if (*itLeft != *itRight) {
			return false;
		}
	}	
	return true;
}

std::vector<const char*> castToStringVector(list<type_t>* l) {
	std::vector<const char*> vec(l->size());
	if(*(l->begin()) == TYPE_VOID)
		return std::vector<const char*>();
	
	int i=0;
	for (list<type_t>::iterator it = l->begin(); it != l->end(); ++it, ++i) {
		vec[i] = typeNames[*it];
	}
	
	return vec;
	
}

