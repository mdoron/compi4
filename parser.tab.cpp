
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
	const char* typeName(type_t t);
	std::vector<const char*> castToStringVector(list<type_t>* l);
	bool compare(list<type_t>* l1, list<type_t>* l2);
	
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
	


/* Line 189 of yacc.c  */
#line 125 "parser.tab.cpp"

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
#line 199 "parser.tab.cpp"

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
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

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
      28,    30,    32,    33,    34,    36,    38,    40,    41,    43,
      47,    50,    52,    55,    61,    65,    71,    76,    79,    82,
      86,    92,   100,   108,   111,   122,   123,   124,   127,   129,
     136,   144,   150,   154,   155,   157,   161,   163,   165,   167,
     171,   175,   177,   179,   181,   184,   186,   188,   190,   193,
     197,   201
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    36,    -1,    -1,    37,    36,    -1,
      -1,    44,    41,    23,    45,    24,    25,    39,    42,    38,
      48,    43,    26,    -1,    -1,    -1,     6,    -1,    30,    -1,
      40,    -1,    -1,    -1,    57,    -1,     3,    -1,    46,    -1,
      -1,    47,    -1,    47,    22,    46,    -1,    57,    40,    -1,
      49,    -1,    48,    49,    -1,    25,    42,    48,    43,    26,
      -1,    57,    40,    21,    -1,    57,    40,    27,    58,    21,
      -1,    40,    27,    58,    21,    -1,    54,    21,    -1,    13,
      21,    -1,    13,    58,    21,    -1,    14,    23,    58,    24,
      49,    -1,    14,    23,    58,    24,    49,    15,    49,    -1,
      16,    23,    50,    58,    51,    24,    49,    -1,    19,    21,
      -1,    17,    23,    58,    24,    25,    42,    52,    43,    26,
      21,    -1,    -1,    -1,    53,    52,    -1,    53,    -1,    18,
      31,    20,    49,    19,    21,    -1,    18,    31,     6,    20,
      49,    19,    21,    -1,    40,    23,    55,    56,    24,    -1,
      40,    23,    24,    -1,    -1,    58,    -1,    58,    22,    56,
      -1,     4,    -1,     5,    -1,     7,    -1,    23,    58,    24,
      -1,    58,    29,    58,    -1,    40,    -1,    54,    -1,    31,
      -1,    31,     6,    -1,    32,    -1,    11,    -1,    12,    -1,
      10,    58,    -1,    58,     8,    58,    -1,    58,     9,    58,
      -1,    58,    28,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    64,    81,    82,    83,    96,   108,   114,
     114,   116,   121,   127,   131,   132,   133,   134,   135,   136,
     137,   143,   144,   145,   146,   154,   169,   179,   180,   181,
     182,   183,   184,   185,   191,   192,   193,   194,   195,   196,
     197,   198,   218,   236,   240,   243,   246,   247,   248,   249,
     250,   255,   260,   261,   262,   271,   272,   273,   274,   277,
     282,   287
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
  "Formals", "FormalsList", "FormalDecl", "Stmts", "Stmt", "Wlparen",
  "Wrparen", "CaseList", "CaseStat", "Call", "NewCall", "ExpList", "Type",
  "Exp", 0
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
      40,    41,    42,    43,    44,    44,    45,    45,    46,    46,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    51,    52,    52,    53,
      53,    54,    54,    55,    56,    56,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,    12,     0,     0,     1,
       1,     1,     0,     0,     1,     1,     1,     0,     1,     3,
       2,     1,     2,     5,     3,     5,     4,     2,     2,     3,
       5,     7,     7,     2,    10,     0,     0,     2,     1,     6,
       7,     5,     3,     0,     1,     3,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     1,     1,     2,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     5,     1,    15,    46,    47,    48,     2,     5,
       0,    14,     4,     9,    10,    11,     0,    17,     0,    16,
      18,     0,     0,     0,    20,     8,    19,    12,     7,     0,
       0,     0,     0,     0,     0,    12,     0,    13,    21,     0,
       0,     0,    56,    57,    28,     0,    53,    55,    51,    52,
       0,     0,    35,     0,    33,     0,    43,     0,     0,    22,
      27,     0,    58,     0,    54,     0,     0,    29,     0,     0,
       0,     0,     0,    13,    42,     0,     0,     6,    24,     0,
      49,    59,    60,    61,    50,     0,    36,     0,     0,     0,
      44,    26,     0,    30,     0,    12,    23,    41,     0,    25,
       0,     0,     0,    45,    31,    32,     0,    13,    38,     0,
       0,    37,     0,     0,     0,     0,     0,    34,     0,     0,
       0,    39,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    29,    27,    48,    16,    28,
      58,    10,    18,    19,    20,    37,    38,    71,    94,   107,
     108,    49,    75,    89,    40,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
     -70,     7,    80,   -70,   -70,   -70,   -70,   -70,   -70,    80,
      -1,   -70,   -70,   -70,   -70,   -70,     0,    88,    -6,   -70,
      -2,    -1,     6,    88,   -70,   -70,   -70,   -70,   -70,    93,
       3,     2,    16,    18,    22,   -70,   -15,    93,   -70,    29,
      -1,   105,   -70,   -70,   -70,   105,    47,   -70,    31,   -70,
      73,   105,   -70,   105,   -70,    93,    44,   105,    50,   -70,
     -70,    -5,   125,    43,   -70,   105,   105,   -70,   105,   105,
     116,   105,   118,    93,   -70,   105,   122,   -70,   -70,   105,
     -70,   -70,   -70,   -70,   -70,    93,   125,    53,    54,    45,
     130,   -70,   140,    74,    72,   -70,   -70,   -70,   105,   -70,
      93,    93,    86,   -70,   -70,   -70,    77,   -70,    86,    -3,
      87,   -70,    94,    93,    98,    93,   101,   -70,   102,   108,
     111,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   113,   -70,   -70,   -70,   -10,   -70,   -29,
     -69,   -70,   -70,   132,   -70,   107,   -36,   -70,   -70,    33,
     -70,   -27,   -70,    58,    38,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      15,    59,    39,   112,    88,    13,    55,     3,    56,    13,
      39,    24,    57,    41,    42,    43,    78,   113,    22,    36,
      23,    50,    79,    17,    44,    51,    45,    36,    39,    14,
      61,    25,    62,    14,    46,    47,    63,    59,   110,    52,
      11,    53,    70,    54,    72,    36,    39,    11,    76,    93,
      60,    65,    66,    64,    56,    21,    81,    82,    39,    83,
      84,    21,    86,    36,   104,   105,   102,    80,    74,    97,
      92,    68,    69,    39,    39,    36,    77,   116,    95,   118,
      96,    65,    66,     4,     5,     6,    39,     7,    39,   100,
      36,    36,     5,     6,    67,     7,   101,     5,     6,    13,
       7,    68,    69,    36,   106,    36,    30,    31,   109,    32,
      33,    13,    34,   114,   115,    41,    42,    43,    35,   117,
     119,   120,    12,    14,    65,    66,    65,    66,    45,   121,
      65,    66,   122,    65,    66,    14,    46,    47,    65,    66,
      85,   111,    87,    91,    68,    69,    68,    69,    65,    66,
      68,    69,    98,    68,    69,    26,   103,     0,    68,    69,
       0,    99,    73,     0,     0,     0,     0,     0,    68,    69
};

static const yytype_int8 yycheck[] =
{
      10,    37,    29,     6,    73,     6,    35,     0,    23,     6,
      37,    21,    27,    10,    11,    12,    21,    20,    24,    29,
      22,    30,    27,    23,    21,    23,    23,    37,    55,    30,
      40,    25,    41,    30,    31,    32,    45,    73,   107,    23,
       2,    23,    51,    21,    53,    55,    73,     9,    57,    85,
      21,     8,     9,     6,    23,    17,    65,    66,    85,    68,
      69,    23,    71,    73,   100,   101,    95,    24,    24,    24,
      79,    28,    29,   100,   101,    85,    26,   113,    25,   115,
      26,     8,     9,     3,     4,     5,   113,     7,   115,    15,
     100,   101,     4,     5,    21,     7,    24,     4,     5,     6,
       7,    28,    29,   113,    18,   115,    13,    14,    31,    16,
      17,     6,    19,    26,    20,    10,    11,    12,    25,    21,
      19,    19,     9,    30,     8,     9,     8,     9,    23,    21,
       8,     9,    21,     8,     9,    30,    31,    32,     8,     9,
      24,   108,    24,    21,    28,    29,    28,    29,     8,     9,
      28,    29,    22,    28,    29,    23,    98,    -1,    28,    29,
      -1,    21,    55,    -1,    -1,    -1,    -1,    -1,    28,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,     0,     3,     4,     5,     7,    36,    37,
      44,    57,    36,     6,    30,    40,    41,    23,    45,    46,
      47,    57,    24,    22,    40,    25,    46,    39,    42,    38,
      13,    14,    16,    17,    19,    25,    40,    48,    49,    54,
      57,    10,    11,    12,    21,    23,    31,    32,    40,    54,
      58,    23,    23,    23,    21,    42,    23,    27,    43,    49,
      21,    40,    58,    58,     6,     8,     9,    21,    28,    29,
      58,    50,    58,    48,    24,    55,    58,    26,    21,    27,
      24,    58,    58,    58,    58,    24,    58,    24,    43,    56,
      58,    21,    58,    49,    51,    25,    26,    24,    22,    21,
      15,    24,    42,    56,    49,    49,    18,    52,    53,    31,
      43,    52,     6,    20,    26,    20,    49,    21,    49,    19,
      19,    21,    21
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
#line 58 "parser.ypp"
    { 
			if ( main_counter == 0 ) {
				output::errorMainMissing();
				exit(0);
			}
		;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 64 "parser.ypp"
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
#line 81 "parser.ypp"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 82 "parser.ypp"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 83 "parser.ypp"
    {
				if (is_main) {
					if ( main_counter > 0 )
						yyerror(""); // TODO: Check if correct
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
#line 96 "parser.ypp"
    {
	int i = -1;
	list<string>::iterator itN = formalNames->begin();
	list<type_t>::iterator itT = formalTypes->begin();
	for (; itN != formalNames->end(); ++itN, ++itT) {
		Row* r = new Row((*itT), (*itN), &(i));
		insert((tables->top())->rows, r);
		i--;
	}
	formalTypes->clear();
	formalNames->clear();
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 108 "parser.ypp"
    {
		Row* r = new Row(functionType, functionName, NULL);
		r->setParams(formalTypes);
		insert((tables->top())->rows, r);
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 114 "parser.ypp"
    { (yyval).name = (yyvsp[(1) - (1)]).name; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 114 "parser.ypp"
    { (yyval).name = (yyvsp[(1) - (1)]).name;
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 116 "parser.ypp"
    {
			(yyval).name = (yyvsp[(1) - (1)]).name;
			functionName = (yyvsp[(1) - (1)]).name;
			is_main = ((yyvsp[(1) - (1)]).name == "main");
		;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 121 "parser.ypp"
    {
		Table* t = new Table();
		t->parent = tables->top();
		tables->push(t);
		offsets->push(offsets->top());
	;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 127 "parser.ypp"
    {
		tables->pop();
		offsets->pop();
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 131 "parser.ypp"
    { (yyval).type = (yyvsp[(1) - (1)]).type; functionType = (yyval).type; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 132 "parser.ypp"
    { (yyval).type = TYPE_VOID; functionType = (yyval).type; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 133 "parser.ypp"
    {  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 134 "parser.ypp"
    { formalTypes->push_back(TYPE_VOID); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 135 "parser.ypp"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 136 "parser.ypp"
    {;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 137 "parser.ypp"
    {
				(yyval).type = (yyvsp[(1) - (2)]).type;
				(yyval).name = (yyvsp[(2) - (2)]).name;
				formalTypes->push_back((yyvsp[(1) - (2)]).type);
				formalNames->push_back((yyvsp[(2) - (2)]).name);
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 143 "parser.ypp"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 144 "parser.ypp"
    {;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 145 "parser.ypp"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 146 "parser.ypp"
    {
			Row* r = new Row((yyvsp[(1) - (3)]).type, (yyvsp[(2) - (3)]).name, &(offsets->top()));
			Table* top = tables->top();
			list<Row*>* rs = top->rows;
			insert(rs, r);
			offsets->pop();
			offsets->push(*(r->offset) + 1);
		;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 154 "parser.ypp"
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

  case 26:

/* Line 1455 of yacc.c  */
#line 169 "parser.ypp"
    {
			assertDef((yyvsp[(1) - (4)]).name);
			Row* def = findDef((yyvsp[(1) - (4)]).name);
			if (def->type == TYPE_INT) {
				type_t ts[2] = {TYPE_INT, TYPE_BYTE};
				assertOneOfTypes((yyvsp[(3) - (4)]).type, ts, 2);
			} else {
				assertType(def->type, (yyvsp[(3) - (4)]).type);
			}
		;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 179 "parser.ypp"
    { ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 180 "parser.ypp"
    { assertType(functionType, TYPE_VOID); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 181 "parser.ypp"
    { assertType(functionType, (yyvsp[(2) - (3)]).type); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 182 "parser.ypp"
    {;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 183 "parser.ypp"
    {;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 184 "parser.ypp"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 185 "parser.ypp"
    { 
			if(whileCounter == 0) {
				output::errorUnexpectedBreak(yylineno);
				exit(0);
			}
		;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 191 "parser.ypp"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 192 "parser.ypp"
    {whileCounter += 1;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 193 "parser.ypp"
    {whileCounter -= 1;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 194 "parser.ypp"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 195 "parser.ypp"
    {;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 196 "parser.ypp"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 197 "parser.ypp"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 198 "parser.ypp"
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

  case 42:

/* Line 1455 of yacc.c  */
#line 218 "parser.ypp"
    {
		Row* r = findFunction((yyvsp[(1) - (3)]).name);
		(yyval).type = r->type;
		(yyval).name = (yyvsp[(1) - (3)]).name;
		callParams->push_back(TYPE_VOID);
		
		if (r == NULL) {
			output::errorUndefFunc(yylineno, ((yyvsp[(1) - (3)]).name).c_str());
			exit(0);
		}
		if (!compare(callParams, r->params)) {
			output::errorPrototypeMismatch(yylineno, ((yyvsp[(1) - (3)]).name).c_str(), castToStringVector(r->params));
			exit(0);
		}
		callParams->clear();
		callsStack.pop();
		callParams = callsStack.size() > 0 ? callsStack.top() : NULL;
	 ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 236 "parser.ypp"
    {
	callParams = new list<type_t>();
	callsStack.push(callParams);
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 240 "parser.ypp"
    {
			callParams->push_back((yyvsp[(1) - (1)]).type);
		;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 243 "parser.ypp"
    {
			callParams->push_back((yyvsp[(1) - (3)]).type);
		;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 246 "parser.ypp"
    {(yyval).type = TYPE_INT;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 247 "parser.ypp"
    {(yyval).type = TYPE_BYTE;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 248 "parser.ypp"
    {(yyval).type = TYPE_BOOL;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 249 "parser.ypp"
    {(yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 250 "parser.ypp"
    {
			assertNumber((yyvsp[(1) - (3)]).type);
			assertNumber((yyvsp[(3) - (3)]).type);
			(yyval).type = ((yyvsp[(1) - (3)]).type == TYPE_INT || (yyvsp[(3) - (3)]).type == TYPE_INT) ? TYPE_INT : TYPE_BYTE;
		;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 255 "parser.ypp"
    { 
		assertDef((yyvsp[(1) - (1)]).name); 
		Row* r = findDef((yyvsp[(1) - (1)]).name);
		(yyval).type = r->type;
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 260 "parser.ypp"
    { ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 261 "parser.ypp"
    {(yyval).type = TYPE_INT;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 262 "parser.ypp"
    { 
			int val = atoi(((yyvsp[(1) - (2)]).name).c_str());
			if (val < 0 || val > 255) {
				char ret = val;
				output::errorByteTooLarge(yylineno, &ret);
				exit(0);
			}
			(yyval).type = TYPE_BYTE;
		;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 271 "parser.ypp"
    {(yyval).type = TYPE_STRING;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 272 "parser.ypp"
    {(yyval).type = TYPE_BOOL;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 273 "parser.ypp"
    {(yyval).type = TYPE_BOOL;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 274 "parser.ypp"
    {
			assertType((yyvsp[(1) - (2)]).type, TYPE_BOOL);
		;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 277 "parser.ypp"
    {
			assertType((yyvsp[(1) - (3)]).type, TYPE_BOOL);
			assertType((yyvsp[(3) - (3)]).type, TYPE_BOOL);
			(yyval).type = TYPE_BOOL;
		;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 282 "parser.ypp"
    {
			assertType((yyvsp[(1) - (3)]).type, TYPE_BOOL);
			assertType((yyvsp[(3) - (3)]).type, TYPE_BOOL);
			(yyval).type = TYPE_BOOL;
		;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 287 "parser.ypp"
    {
			assertType((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type);
			assertNumber((yyvsp[(1) - (3)]).type);
			(yyval).type = TYPE_BOOL;
		;}
    break;



/* Line 1455 of yacc.c  */
#line 2099 "parser.tab.cpp"
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
#line 292 "parser.ypp"


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

const char* typeName(type_t t) {
	string ret = "";
	switch( t ) {
		case TYPE_BOOL: ret = "bool"; break;
		case TYPE_INT: ret = "int"; break;
		case TYPE_BYTE: ret = "byte"; break;
		case TYPE_STRING: ret = "string"; break;
		case TYPE_VOID: ret = "void"; break;
		default: ret = "non"; break;
	}
	return ret.c_str();
}

bool compare(list<type_t>* l1, list<type_t>* l2) {
	if (l1 == NULL || l2 == NULL) {
		return false;
	}
	
	list<type_t>::iterator itN = l1->begin();
	list<type_t>::iterator itT = l2->begin();
	
	if(l1->size() != l2->size()){
		return false;
	}
	for (; itN != l1->end(); ++itN, ++itT) {
		
		if(*itT==TYPE_INT){
			if((*itN!=*itT)&&(*itN!=TYPE_BYTE))
				return false;
		} else if (*itN != *itT) {
			return false;
		}
	}	
	return true;
}

std::vector<const char*> castToStringVector(list<type_t>* l) {
	std::vector<const char*> ret;// = new std::vector<const char*>();
	if (l == NULL) {
		return ret;
	}
	list<type_t>::iterator it = l->begin();
	for (; it != l->end(); ++it) {
		ret.push_back(typeName(*it));
	}
}
