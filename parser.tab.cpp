
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

	#include "attributes.hpp"
	#include "output.hpp"
	#include <iostream>
	#include <ostream>
	#include <sstream>
	#include <stdlib.h>
	#include <string>
	#include <set>
	#include <stack>
	#include <assert.h>
	#include "bp.hpp"
	
	#define STOI(x) atoi(x.c_str())
	#define DEBUG 0
	
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
	bool isBool(string name);
	
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
	
	int stringLabelIdx = 0;
	int divLabelIdx = 0;
	
	// ************************ hw5 ***************************** //
	string getAddu (string Rdest, string Rsrc, string num2);
	string getSubu (string Rdest, string Rsrc, string num2);
	string getMulo (string Rdest, string Rsrc, string num2);
	string getDivu (string Rdest, string Rsrc, string num2);
	string getMove (string Rdest, string Rsrc);
	string getLoadint (string Rdest, string num);
	string emitBinop(string binop, string R1, string R2);
	string getRelop(string op);
	string getIf(string relop, string reg, string val, string label);
	string emitBooleanAssignment(vector<address_t> trueList, vector<address_t> falseList);
	string getSw(string Rsrc, string offset, string Rdest);
	string emitLeaf(string name);
	string getLw(string Rdest, string offset, string Rsrc);
	string loadVar(string name, STYPE* S);
	void storeVar(string name, string value);
	string popVars();
	void handleReturn();
	void emitPrint();
	void emitPrinti();
	
	class Registers {
		set<string> releasedRegs;
		set<string> allocatedRegs;
		
		public:

		Registers(){
			int i=0;
			string a="0123456789";
			string t = "$t";
			string s = "$s";
			while(i!=8){
				string tmp = t;
				tmp.append(&a[i],0, 1);
				releasedRegs.insert(tmp);
				tmp = s;
				tmp.append(&a[i], 0, 1);
				releasedRegs.insert(tmp);
				i++;
			}
			string tmp = t;
			tmp.append(&a[i],0, 1);
			releasedRegs.insert(tmp);
			i++;
			tmp = t;
			tmp.append(&a[i],0, 1);
			releasedRegs.insert(tmp);
		}
		
		~Registers(){}

		set<string> getReleasedRegs() {
			return releasedRegs;
		}

		set<string> getAllocatedRegs() {
			return allocatedRegs;
		}		
		
		string allocate(){
			assert(releasedRegs.size()!=0);
			set<string>::iterator it = releasedRegs.begin();
			string reg = *it;
			allocatedRegs.insert(reg);
			releasedRegs.erase(reg);
			return reg;
		}

		void release(string reg){
			if (reg == "")
				return;
			assert(releasedRegs.find(reg)==releasedRegs.end());
			releasedRegs.insert(reg);
			allocatedRegs.erase(reg);	
		}
		
		void releaseAll() {
			for(set<string>::iterator it = allocatedRegs.begin(); it != allocatedRegs.end(); ++it)
				release(*it);
		}

		unsigned long long int numOfValidRegisters(){
			return releasedRegs.size();
		}

	};
	
	
	int labelCounter;
	Registers regsPool;
	CodeBuffer& cb = CodeBuffer::instance();



/* Line 189 of yacc.c  */
#line 231 "parser.tab.cpp"

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
#line 305 "parser.tab.cpp"

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
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

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
      48,    50,    54,    56,    58,    64,    68,    74,    78,    80,
      82,    84,    86,    88,    90,    95,    98,   101,   105,   110,
     119,   127,   130,   138,   142,   146,   150,   151,   152,   155,
     157,   165,   174,   180,   185,   186,   188,   192,   194,   196,
     198,   202,   206,   208,   210,   212,   214,   216,   218,   220,
     223,   228,   233,   237,   238,   239
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    36,    -1,    -1,    37,    36,    -1,
      -1,    44,    41,    23,    45,    24,    25,    39,    42,    38,
      48,    43,    26,    -1,    -1,    -1,    30,    -1,    40,    -1,
      -1,    -1,    67,    -1,     3,    -1,    46,    -1,    -1,    47,
      -1,    47,    22,    46,    -1,    67,    40,    -1,    49,    -1,
      48,    69,    49,    -1,    55,    -1,    50,    -1,    25,    42,
      48,    43,    26,    -1,    67,    40,    21,    -1,    67,    40,
      27,    68,    21,    -1,    42,    51,    43,    -1,    52,    -1,
      56,    -1,    53,    -1,    50,    -1,    51,    -1,    56,    -1,
      40,    27,    68,    21,    -1,    64,    21,    -1,    13,    21,
      -1,    13,    68,    21,    -1,    58,    69,    24,    54,    -1,
      58,    69,    24,    54,    15,    70,    69,    54,    -1,    69,
      59,    24,    69,    60,    54,    61,    -1,    19,    21,    -1,
      57,    70,    24,    25,    62,    26,    21,    -1,    17,    23,
      68,    -1,    14,    23,    68,    -1,    16,    23,    68,    -1,
      -1,    -1,    63,    62,    -1,    63,    -1,    18,    31,    20,
      69,    54,    19,    21,    -1,    18,    31,     6,    20,    69,
      54,    19,    21,    -1,    40,    23,    65,    66,    24,    -1,
      40,    23,    65,    24,    -1,    -1,    68,    -1,    68,    22,
      66,    -1,     4,    -1,     5,    -1,     7,    -1,    23,    68,
      24,    -1,    68,    29,    68,    -1,    40,    -1,    64,    -1,
      31,    -1,    71,    -1,    32,    -1,    11,    -1,    12,    -1,
      10,    68,    -1,    68,     8,    69,    68,    -1,    68,     9,
      69,    68,    -1,    68,    28,    68,    -1,    -1,    -1,    31,
       6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   185,   208,   209,   210,   229,   240,   246,
     251,   264,   270,   292,   293,   294,   295,   296,   297,   298,
     304,   305,   311,   311,   313,   318,   330,   358,   362,   363,
     365,   366,   368,   369,   371,   398,   399,   404,   425,   430,
     436,   443,   450,   466,   472,   477,   482,   483,   484,   491,
     496,   501,   506,   570,   616,   624,   628,   633,   634,   635,
     636,   643,   651,   669,   670,   673,   676,   686,   691,   696,
     704,   715,   724,   734,   737,   741
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
  "Call", "NewCall", "ExpList", "Type", "Exp", "M", "N", "NumByte", 0
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
      68,    68,    68,    69,    70,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,    12,     0,     0,     1,
       1,     0,     0,     1,     1,     1,     0,     1,     3,     2,
       1,     3,     1,     1,     5,     3,     5,     3,     1,     1,
       1,     1,     1,     1,     4,     2,     2,     3,     4,     8,
       7,     2,     7,     3,     3,     3,     0,     0,     2,     1,
       7,     8,     5,     4,     0,     1,     3,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     3,     0,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     5,     1,    14,    57,    58,    59,     2,     5,
       0,    13,     4,     9,    10,     0,    16,     0,    15,    17,
       0,     0,     0,    19,     8,    18,    11,     7,    73,     0,
       0,     0,     0,    11,     0,    73,    20,    23,    32,    22,
      33,    74,    73,     0,     0,     0,     0,    67,    68,    36,
       0,    64,    66,    62,    63,     0,    65,     0,     0,    41,
      73,    54,     0,     0,    73,     0,     0,    35,     0,     0,
       0,    69,     0,    75,    73,    73,    37,     0,     0,    44,
      43,    73,     0,     0,     6,    21,     0,    11,    25,     0,
       0,    73,    60,     0,     0,    72,    61,     0,    53,     0,
      55,    34,     0,     0,    31,    28,    30,    38,    29,     0,
      45,    46,    70,    71,    24,    52,     0,     0,     0,    49,
      12,    74,    26,    11,    56,     0,     0,    48,    27,    73,
      47,     0,    73,    42,    11,    40,    73,    11,    39,    11,
       0,     0,     0,     0,    50,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    28,    26,    53,    15,   103,
      63,    10,    17,    18,    19,    35,    36,   104,    38,   105,
     106,   107,    39,   108,    41,    42,    70,   123,   135,   118,
     119,    54,    82,    99,    44,   100,    45,    65,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
    -121,     9,   182,  -121,  -121,  -121,  -121,  -121,  -121,   182,
     -26,  -121,  -121,  -121,  -121,     6,    86,     1,  -121,     5,
     -26,     7,    86,  -121,  -121,  -121,  -121,  -121,    75,    53,
       8,    26,    32,  -121,    19,    31,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,    41,   -26,    50,   110,  -121,  -121,  -121,
     110,    63,  -121,    47,  -121,   126,  -121,   110,   110,  -121,
      75,  -121,   110,    49,    75,    54,    57,  -121,    -6,    64,
      62,    30,   135,  -121,  -121,  -121,  -121,   110,   110,    30,
      30,    31,   107,   137,  -121,  -121,    48,   158,  -121,   110,
     110,  -121,  -121,   110,   110,  -121,  -121,    69,  -121,    73,
     140,  -121,    80,    86,  -121,  -121,  -121,    88,  -121,   152,
      30,  -121,    30,    30,  -121,  -121,   110,    70,    78,    80,
    -121,  -121,  -121,   158,  -121,     2,    87,  -121,  -121,  -121,
    -121,    89,  -121,  -121,   158,  -121,  -121,   158,  -121,   158,
      92,    95,    94,   102,  -121,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -121,  -121,  -121,   116,  -121,  -121,  -121,   -10,  -121,    -3,
     -79,  -121,  -121,   104,  -121,    56,    68,   -17,    25,  -121,
    -121,  -120,  -121,   -12,  -121,  -121,  -121,  -121,  -121,    17,
    -121,   -27,  -121,    34,     4,   -22,   -30,    35,  -121
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -74
static const yytype_int16 yytable[] =
{
      14,    43,    97,   130,    13,    64,    11,    55,   131,     3,
      23,    37,    66,    11,   138,    88,    40,   140,    34,   141,
      20,    89,   132,    27,    71,    21,    20,    22,    72,    16,
      60,    57,    24,    43,    68,    79,    80,    43,    74,    75,
      83,   128,    61,    37,    93,    94,    62,    37,    40,    58,
      34,    64,    40,    59,    34,    95,    96,   -12,    77,    78,
      43,   111,    67,    46,    47,    48,    69,   109,   110,    73,
      61,   112,   113,   102,    49,    84,    50,    34,    86,     5,
       6,    87,     7,    13,    51,    52,    91,    90,    29,    30,
       5,     6,    31,     7,    32,   114,    43,   115,   117,   134,
      33,   125,   137,   121,   126,    13,   139,    43,   133,   136,
      43,   142,    43,    34,   143,   144,    81,    46,    47,    48,
      46,    47,    48,   145,    34,    12,    25,    34,   120,    34,
      50,    98,    85,    50,    74,    75,   127,    13,    51,    52,
      13,    51,    52,    74,    75,    74,    75,    76,    74,    75,
     124,     0,     0,     0,    77,    78,   129,     0,   101,    92,
      74,    75,   116,    77,    78,    77,    78,     0,    77,    78,
       0,    29,    30,   122,   -73,    31,     0,    32,     0,     0,
      77,    78,     0,    33,     0,     4,     5,     6,    13,     7
};

static const yytype_int16 yycheck[] =
{
      10,    28,    81,   123,    30,    35,     2,    29,     6,     0,
      20,    28,    42,     9,   134,    21,    28,   137,    28,   139,
      16,    27,    20,    26,    46,    24,    22,    22,    50,    23,
      33,    23,    25,    60,    44,    57,    58,    64,     8,     9,
      62,   120,    23,    60,    74,    75,    27,    64,    60,    23,
      60,    81,    64,    21,    64,    77,    78,    26,    28,    29,
      87,    91,    21,    10,    11,    12,    16,    89,    90,     6,
      23,    93,    94,    25,    21,    26,    23,    87,    24,     4,
       5,    24,     7,    30,    31,    32,    24,    23,    13,    14,
       4,     5,    17,     7,    19,    26,   123,    24,    18,   129,
      25,    31,   132,    15,    26,    30,   136,   134,    21,    20,
     137,    19,   139,   123,    19,    21,    60,    10,    11,    12,
      10,    11,    12,    21,   134,     9,    22,   137,   103,   139,
      23,    24,    64,    23,     8,     9,   119,    30,    31,    32,
      30,    31,    32,     8,     9,     8,     9,    21,     8,     9,
     116,    -1,    -1,    -1,    28,    29,   121,    -1,    21,    24,
       8,     9,    22,    28,    29,    28,    29,    -1,    28,    29,
      -1,    13,    14,    21,    16,    17,    -1,    19,    -1,    -1,
      28,    29,    -1,    25,    -1,     3,     4,     5,    30,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,     0,     3,     4,     5,     7,    36,    37,
      44,    67,    36,    30,    40,    41,    23,    45,    46,    47,
      67,    24,    22,    40,    25,    46,    39,    42,    38,    13,
      14,    17,    19,    25,    40,    48,    49,    50,    51,    55,
      56,    57,    58,    64,    67,    69,    10,    11,    12,    21,
      23,    31,    32,    40,    64,    68,    71,    23,    23,    21,
      42,    23,    27,    43,    69,    70,    69,    21,    40,    16,
      59,    68,    68,     6,     8,     9,    21,    28,    29,    68,
      68,    48,    65,    68,    26,    49,    24,    24,    21,    27,
      23,    24,    24,    69,    69,    68,    68,    43,    24,    66,
      68,    21,    25,    42,    50,    52,    53,    54,    56,    68,
      68,    69,    68,    68,    26,    24,    22,    18,    62,    63,
      51,    15,    21,    60,    66,    31,    26,    62,    43,    70,
      54,     6,    20,    21,    69,    61,    20,    69,    54,    69,
      54,    54,    19,    19,    21,    21
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
#line 164 "parser.ypp"
    { 
			if ( main_counter == 0 ) {
				output::errorMainMissing();
				exit(0);
			}
			
		//while(stack<Table*>::iterator it = tables->begin();it!=tables->end();it++) {	
		//	}
			
			/*output::endScope();
			list<Row*>::iterator it = (tables->top()->rows)->begin();
			++it;
			++it;
			for(; it!=(tables->top()->rows)->end();it++) {
				string fType = output::makeFunctionType((typeNames[(*it)->type]),castToStringVector((*it)->params));
				output::printID(((*it)->name).c_str(),0,fType.c_str());
			}
			*/
			cb.printCodeBuffer();
			cb.printDataBuffer();
		;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 185 "parser.ypp"
    {
	emitPrint();
	emitPrinti();
	ostringstream stringLabel;
	stringLabel << "aErrorZeroDivision";
	cb.emitData(stringLabel.str() + ": .ascii " + "\"Error division by zero\"");
	
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
#line 208 "parser.ypp"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 209 "parser.ypp"
    { if (saveyy != "") yyerror(""); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 210 "parser.ypp"
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
				cb.emit((yyvsp[(2) - (12)]).name + "_end:");
				cb.bpatch((yyvsp[(10) - (12)]).nextList, (yyvsp[(2) - (12)]).name+"_end");
				if((yyvsp[(1) - (12)]).type == TYPE_VOID) { 
					cb.emit("jr $ra");
				}
				functionType = TYPE_NON;
				functionName = "";
			;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 229 "parser.ypp"
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
#line 240 "parser.ypp"
    {
		Row* r = new Row(functionType, functionName, NULL);
		r->setParams(formalTypes);
		insert((tables->top())->rows, r);
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 246 "parser.ypp"
    { (yyval).name = (yyvsp[(1) - (1)]).name; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 251 "parser.ypp"
    {
			regsPool.releaseAll();
			
			(yyval).name = (yyvsp[(1) - (1)]).name;
			functionName = (yyvsp[(1) - (1)]).name;
			is_main = ((yyvsp[(1) - (1)]).name == "main");
			
			if((yyval).name == "main")
				cb.emit(".globl main");
			cb.emit((yyval).name + ":");
			cb.emit(getMove("$fp", "$sp"));
			cb.emit(getSubu("$fp", "$fp", "4"));
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 264 "parser.ypp"
    {
		Table* t = new Table();
		t->parent = tables->top();
		tables->push(t);
		offsets->push(offsets->top());
	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 270 "parser.ypp"
    {
	/*output::endScope();
	list<Row*>::iterator ir = ((tables->top()->rows)->begin());
	for(; ir!=(tables->top()->rows)->end();ir++)
		output::printID(((*ir)->name).c_str(),*((*ir)->offset),(typeNames[(*ir)->type]));
	*/
	cb.emit(popVars());
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
#line 292 "parser.ypp"
    { (yyval).type = (yyvsp[(1) - (1)]).type; functionType = (yyval).type; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 293 "parser.ypp"
    { (yyval).type = TYPE_VOID; functionType = (yyval).type; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 294 "parser.ypp"
    {  ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 295 "parser.ypp"
    { formalTypes->push_back(TYPE_VOID); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 296 "parser.ypp"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 297 "parser.ypp"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 298 "parser.ypp"
    {
				(yyval).type = (yyvsp[(1) - (2)]).type;
				(yyval).name = (yyvsp[(2) - (2)]).name;
				formalTypes->push_back((yyvsp[(1) - (2)]).type);
				formalNames->push_back((yyvsp[(2) - (2)]).name);
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 304 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList; (yyval).breakList = (yyvsp[(1) - (1)]).breakList; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 305 "parser.ypp"
    {
		  cb.bpatch((yyvsp[(1) - (3)]).nextList, (yyvsp[(2) - (3)]).quad);
		  (yyval).nextList = (yyvsp[(3) - (3)]).nextList;
		  (yyval).breakList = cb.merge((yyvsp[(1) - (3)]).breakList, (yyvsp[(3) - (3)]).breakList); 
		;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 311 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList; (yyval).breakList = (yyvsp[(1) - (1)]).breakList; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 311 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList; (yyval).breakList = (yyvsp[(1) - (1)]).breakList; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 313 "parser.ypp"
    {
	(yyval).nextList = (yyvsp[(3) - (5)]).nextList;
	(yyval).breakList = (yyvsp[(3) - (5)]).breakList; 
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 318 "parser.ypp"
    {
			Row* r = new Row((yyvsp[(1) - (3)]).type, (yyvsp[(2) - (3)]).name, &(offsets->top()));
			Table* top = tables->top();
			list<Row*>* rs = top->rows;
			insert(rs, r);
			offsets->pop();
			offsets->push(*(r->offset) + 1);
			
			cb.emit(getSubu("$sp", "$sp", "4"));
			
			//$$.nextList = NULL;
		;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 330 "parser.ypp"
    {
			assertNotDef((yyvsp[(2) - (5)]).name);
			if ((yyvsp[(1) - (5)]).type == TYPE_INT) {
				type_t ts[2] = {TYPE_INT, TYPE_BYTE};
				assertOneOfTypes((yyvsp[(4) - (5)]).type, ts, 2);
			} else {
				assertType((yyvsp[(1) - (5)]).type, (yyvsp[(4) - (5)]).type);
			}
			string Rdest = ""; 
			if((yyvsp[(1) - (5)]).type == TYPE_BOOL)
				Rdest = emitBooleanAssignment((yyvsp[(4) - (5)]).trueList, (yyvsp[(4) - (5)]).falseList);
			else
				Rdest = (yyvsp[(4) - (5)]).place;
				
			cb.emit(getSubu("$sp", "$sp", "4"));
			cb.emit(getSw(Rdest, "0",  "$sp"));
			regsPool.release(Rdest);
			
			Row* r = new Row((yyvsp[(1) - (5)]).type, (yyvsp[(2) - (5)]).name, &(offsets->top()));
			Table* top = tables->top();
			list<Row*>* rs = top->rows;
			insert(rs, r);
			offsets->pop();
			offsets->push(*(r->offset) + 1); 
			
			//$$.nextList = NULL;
		;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 358 "parser.ypp"
    {
	(yyval).nextList = (yyvsp[(2) - (3)]).nextList;
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 362 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 363 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList; (yyval).breakList = (yyvsp[(1) - (1)]).breakList; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 365 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList; (yyval).breakList = (yyvsp[(1) - (1)]).breakList; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 366 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList; (yyval).breakList = (yyvsp[(1) - (1)]).breakList; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 368 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 369 "parser.ypp"
    {(yyval).nextList = (yyvsp[(1) - (1)]).nextList; (yyval).breakList = (yyvsp[(1) - (1)]).breakList; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 371 "parser.ypp"
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

			string Rdest = ""; 
			if(isBool((yyvsp[(1) - (4)]).name))
				Rdest = emitBooleanAssignment((yyvsp[(3) - (4)]).trueList, (yyvsp[(3) - (4)]).falseList);
			else
				Rdest = (yyvsp[(3) - (4)]).place;
				
			storeVar((yyvsp[(1) - (4)]).name, Rdest);
			//cb.emit(getSubu("$sp", "$sp", "4"));
			//cb.emit(getSw(Rdest, "0", "$sp"));
			regsPool.release(Rdest);
			
			//$$.nextList = NULL;
		;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 398 "parser.ypp"
    { ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 399 "parser.ypp"
    { 
			assertType(functionType, TYPE_VOID); 
			cb.emit(popVars());
			cb.emit("jr $ra");
		;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 404 "parser.ypp"
    { 
			assertNotType(functionType, TYPE_VOID); 
			if (functionType == TYPE_INT)
				assertNumber((yyvsp[(2) - (3)]).type);
			else 
				assertType(functionType, (yyvsp[(2) - (3)]).type);
			if((yyvsp[(2) - (3)]).type != TYPE_BOOL)
				cb.emit(getMove("$v0", (yyvsp[(2) - (3)]).place));
			else {
				string ret1 = cb.next();
				cb.emit("li $v0, 1");
				vector<address_t> jumpToExit = cb.makelist(cb.emit("j "));
				string ret0 = cb.next();
				cb.emit("li $v0, 0");
				cb.bpatch((yyvsp[(2) - (3)]).trueList, ret1);
				cb.bpatch((yyvsp[(2) - (3)]).falseList, ret0);
				cb.bpatch(jumpToExit, cb.next());
			}
			cb.emit(popVars());
			cb.emit("jr $ra");
		;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 425 "parser.ypp"
    {
		cb.bpatch((yyvsp[(1) - (4)]).trueList, (yyvsp[(2) - (4)]).quad);
		(yyval).nextList = cb.merge((yyvsp[(1) - (4)]).falseList, (yyvsp[(4) - (4)]).nextList);
		(yyval).breakList = (yyvsp[(4) - (4)]).breakList; 
	 ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 430 "parser.ypp"
    { 
		cb.bpatch((yyvsp[(1) - (8)]).trueList,(yyvsp[(2) - (8)]).quad);
		cb.bpatch((yyvsp[(1) - (8)]).falseList,(yyvsp[(7) - (8)]).quad);
		(yyval).nextList = cb.merge(cb.merge((yyvsp[(4) - (8)]).nextList, (yyvsp[(6) - (8)]).nextList), (yyvsp[(8) - (8)]).nextList);
		(yyval).breakList = cb.merge((yyvsp[(4) - (8)]).breakList, (yyvsp[(8) - (8)]).breakList); 
	 ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 436 "parser.ypp"
    {
		cb.bpatch((yyvsp[(6) - (7)]).nextList, (yyvsp[(1) - (7)]).quad);
		cb.bpatch((yyvsp[(2) - (7)]).trueList, (yyvsp[(4) - (7)]).quad);
		(yyval).nextList = cb.merge((yyvsp[(6) - (7)]).breakList, (yyvsp[(2) - (7)]).falseList);
		(yyval).breakList = (yyvsp[(6) - (7)]).breakList; 
		cb.emit("j " + (yyvsp[(1) - (7)]).quad);
	 ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 443 "parser.ypp"
    {
			if(whileCounter == 0) {
				output::errorUnexpectedBreak(yylineno);
				exit(0);
			}
			(yyval).breakList = cb.makelist(cb.emit("j "));
		;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 450 "parser.ypp"
    {
			cb.bpatch((yyvsp[(2) - (7)]).nextList, cb.next());
			
			while(!(yyvsp[(5) - (7)]).valueList.empty()){
				int value = (yyvsp[(5) - (7)]).valueList.top();
				(yyvsp[(5) - (7)]).valueList.pop();
				string quad = (yyvsp[(5) - (7)]).quadList.top();
				(yyvsp[(5) - (7)]).quadList.pop();
				ostringstream temp;
				temp << value;
				cb.emit("beq " + (yyvsp[(1) - (7)]).place + ", " + temp.str() + ", " + quad);
			}
			cb.next();
			(yyval).nextList = cb.merge((yyvsp[(5) - (7)]).nextList, cb.makelist(cb.emit("j ")));

	 ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 466 "parser.ypp"
    {
			assertNumber((yyvsp[(3) - (3)]).type);
			(yyval).place = (yyvsp[(3) - (3)]).place;
			(yyval).trueList = (yyvsp[(3) - (3)]).trueList;
			(yyval).falseList = (yyvsp[(3) - (3)]).falseList;
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 472 "parser.ypp"
    {
			assertType((yyvsp[(3) - (3)]).type, TYPE_BOOL);
			(yyval).trueList = (yyvsp[(3) - (3)]).trueList;
			(yyval).falseList = (yyvsp[(3) - (3)]).falseList;
		;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 477 "parser.ypp"
    { 
			assertType((yyvsp[(3) - (3)]).type, TYPE_BOOL); 
			(yyval).trueList = (yyvsp[(3) - (3)]).trueList;
			(yyval).falseList = (yyvsp[(3) - (3)]).falseList;
		;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 482 "parser.ypp"
    {whileCounter += 1;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 483 "parser.ypp"
    {whileCounter -= 1;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 484 "parser.ypp"
    {
			(yyval).quadList = (yyvsp[(2) - (2)]).quadList;
			(yyval).quadList.push((yyvsp[(1) - (2)]).quad);
			(yyval).valueList = (yyvsp[(2) - (2)]).valueList;
			(yyval).valueList.push((yyvsp[(1) - (2)]).value);
			(yyval).nextList = cb.merge((yyvsp[(2) - (2)]).nextList,(yyvsp[(1) - (2)]).nextList);
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 491 "parser.ypp"
    {
			 (yyval).quadList.push((yyvsp[(1) - (1)]).quad);
			 (yyval).valueList.push((yyvsp[(1) - (1)]).value);
			 (yyval).nextList = (yyvsp[(1) - (1)]).nextList; 
		 ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 496 "parser.ypp"
    {
			(yyval).quad = (yyvsp[(4) - (7)]).quad;
			(yyval).value = atoi(((yyvsp[(2) - (7)]).name).c_str());
			(yyval).nextList = cb.merge((yyvsp[(5) - (7)]).nextList, cb.makelist(cb.emit("j "))) ;
		;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 501 "parser.ypp"
    {
			(yyval).quad = (yyvsp[(5) - (8)]).quad;
			(yyval).value = atoi(((yyvsp[(2) - (8)]).name).c_str());
			(yyval).nextList = cb.merge((yyvsp[(6) - (8)]).nextList, cb.makelist(cb.emit("j "))) ;
		 ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 506 "parser.ypp"
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
		
		// push allocated registers
		for( list<string>::iterator it = (yyval).allocatedRegsList.begin(); it != (yyval).allocatedRegsList.end(); ++it ) {
			cb.emit(getSubu("$sp", "$sp", "4"));
			cb.emit(getSw(*it, "0", "$sp"));
		}
		// push ra
		cb.emit(getSubu("$sp", "$sp", "4"));
		cb.emit(getSw("$ra", "0", "$sp"));
		
		// push params backwards
		for( list<string>::reverse_iterator rit = (yyvsp[(4) - (5)]).paramPlaceList.rbegin(); rit != (yyvsp[(4) - (5)]).paramPlaceList.rend(); ++rit ) {
			cb.emit(getSubu("$sp", "$sp", "4"));
			cb.emit(getSw(*rit, "0", "$sp"));
		}
		// call
		cb.emit("jal " + (yyvsp[(1) - (5)]).name);
		// get value
		if (findFunction((yyvsp[(1) - (5)]).name)->type != TYPE_VOID) {
			string Rdest = regsPool.allocate();
			cb.emit(getMove(Rdest, "$v0"));
			(yyval).place = Rdest;
		}
		// pop params - I decided that the function will remove the locals
		/*for( list<string>::iterator it = $4.paramPlaceList.begin(); it != $4.paramPlaceList.end(); ++it ) {
			cb.emit(getLw(*it, "0", "$sp"));
			cb.emit(getAddu("$sp", "$sp", "4"));
		}*/
		
		// pop ra
		cb.emit(getLw("$ra", "0", "$sp"));
		cb.emit(getAddu("$sp", "$sp", "4"));		
		
		// pop allocated registers
		for( list<string>::reverse_iterator rit = (yyval).allocatedRegsList.rbegin(); rit != (yyval).allocatedRegsList.rend(); ++rit ) {
			cb.emit(getLw(*rit, "0", "$sp"));
			cb.emit(getAddu("$sp", "$sp", "4"));
		}
		
		// release ExpList registers
		for( list<string>::iterator it = (yyvsp[(4) - (5)]).paramPlaceList.begin(); it != (yyvsp[(4) - (5)]).paramPlaceList.end(); ++it ) {
			regsPool.release(*it);
		}
		
	 ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 570 "parser.ypp"
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
		
		// push allocated registers
		for( list<string>::iterator it = (yyval).allocatedRegsList.begin(); it != (yyval).allocatedRegsList.end(); ++it ) {
			cb.emit(getSubu("$sp", "$sp", "4"));
			cb.emit(getSw(*it, "0", "$sp"));
		}
		// push ra
		cb.emit(getSubu("$sp", "$sp", "4"));
		cb.emit(getSw("$ra", "0", "$sp"));

		// call
		cb.emit("jal " + (yyvsp[(1) - (4)]).name);
		// get value
		if (findFunction((yyvsp[(1) - (4)]).name)->type != TYPE_VOID) {
			string Rdest = regsPool.allocate();
			cb.emit(getMove(Rdest, "$v0"));
			(yyval).place = Rdest;
		}

		// pop ra
		cb.emit(getLw("$ra", "0", "$sp"));
		cb.emit(getAddu("$sp", "$sp", "4"));		
		
		// pop allocated registers
		for( list<string>::reverse_iterator rit = (yyval).allocatedRegsList.rbegin(); rit != (yyval).allocatedRegsList.rend(); ++rit ) {
			cb.emit(getLw(*rit, "0", "$sp"));
			cb.emit(getAddu("$sp", "$sp", "4"));
		}
	 ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 616 "parser.ypp"
    {
	callParams = new list<type_t>();
	callsStack.push(callParams);
	set<string> temp = regsPool.getAllocatedRegs();
	for( set<string>::iterator it = temp.begin(); it != temp.end(); ++it ) {
		(yyval).allocatedRegsList.push_back(*it);
	}
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 624 "parser.ypp"
    {
			callParams->push_front((yyvsp[(1) - (1)]).type);
			(yyval).paramPlaceList.push_front((yyvsp[(1) - (1)]).place);
		;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 628 "parser.ypp"
    {
			callParams->push_front((yyvsp[(1) - (3)]).type);
			(yyval).paramPlaceList = (yyvsp[(3) - (3)]).paramPlaceList;
			(yyval).paramPlaceList.push_front((yyvsp[(1) - (3)]).place);
		;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 633 "parser.ypp"
    {(yyval).type = TYPE_INT;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 634 "parser.ypp"
    {(yyval).type = TYPE_BYTE;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 635 "parser.ypp"
    {(yyval).type = TYPE_BOOL;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 636 "parser.ypp"
    {
			(yyval) = (yyvsp[(2) - (3)]);
			(yyval).falseList = (yyvsp[(2) - (3)]).falseList;
			(yyval).trueList = (yyvsp[(2) - (3)]).trueList;
			
			(yyval).place = (yyvsp[(2) - (3)]).place;
		;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 643 "parser.ypp"
    {
			assertNumber((yyvsp[(1) - (3)]).type);
			assertNumber((yyvsp[(3) - (3)]).type);
			(yyval).type = ((yyvsp[(1) - (3)]).type == TYPE_INT || (yyvsp[(3) - (3)]).type == TYPE_INT) ? TYPE_INT : TYPE_BYTE;
			(yyval).place = emitBinop((yyvsp[(2) - (3)]).name, (yyvsp[(1) - (3)]).place, (yyvsp[(3) - (3)]).place);
			//regsPool.release($1.place);
			regsPool.release((yyvsp[(3) - (3)]).place);
		;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 651 "parser.ypp"
    { 
		assertDef((yyvsp[(1) - (1)]).name); 
		Row* r = findDef((yyvsp[(1) - (1)]).name);
		(yyval).type = r->type;
		(yyval).name = (yyvsp[(1) - (1)]).name;
		
		string Rdest = regsPool.allocate();
		ostringstream offset;
		offset << 4*(-*(r->offset));
		cb.emit(getLw(Rdest, offset.str(), "$fp"));
		if (isBool((yyval).name)) {
			(yyval).trueList = cb.makelist(cb.emit(getIf("beq", Rdest, "1", "")));
			(yyval).falseList = cb.makelist(cb.emit(getIf("beq", Rdest, "0", "")));
			regsPool.release(Rdest);
		}	
		
		(yyval).place = Rdest;
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 669 "parser.ypp"
    {;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 670 "parser.ypp"
    {
		(yyval).place = emitLeaf((yyvsp[(1) - (1)]).name);
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 673 "parser.ypp"
    {
		(yyval).place = emitLeaf((yyvsp[(1) - (1)]).name);
	;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 676 "parser.ypp"
    {
		(yyval).type = TYPE_STRING;
		ostringstream stringLabel;
		stringLabel << "aString" << stringLabelIdx;
		cb.emitData(stringLabel.str() + ": .ascii " +  (yyvsp[(1) - (1)]).name );
		stringLabelIdx++;
		string Rdest = regsPool.allocate();
		cb.emit("la " + Rdest + ", " + stringLabel.str());
		(yyval).place = Rdest;
	;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 686 "parser.ypp"
    {
			(yyval).name = "1"; 
			(yyval).type = TYPE_BOOL;
			(yyval).trueList = cb.makelist(cb.emit("j "));
		;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 691 "parser.ypp"
    {
			(yyval).name = "0"; 
			(yyval).type = TYPE_BOOL;
			(yyval).falseList = cb.makelist(cb.emit("j "));
		;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 696 "parser.ypp"
    {
			assertType((yyvsp[(2) - (2)]).type, TYPE_BOOL);
			(yyval).type = TYPE_BOOL;
			
			(yyval).place = (yyvsp[(2) - (2)]).place;
			(yyval).falseList = (yyvsp[(2) - (2)]).trueList;
			(yyval).trueList = (yyvsp[(2) - (2)]).falseList;
		;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 704 "parser.ypp"
    {
			assertType((yyvsp[(1) - (4)]).type, TYPE_BOOL);
			assertType((yyvsp[(4) - (4)]).type, TYPE_BOOL);
			(yyval).type = TYPE_BOOL;
			
			cb.bpatch((yyvsp[(1) - (4)]).trueList, (yyvsp[(3) - (4)]).quad);
			(yyval).trueList = (yyvsp[(4) - (4)]).trueList;
			(yyval).falseList = cb.merge((yyvsp[(1) - (4)]).falseList,(yyvsp[(4) - (4)]).falseList);
			
			
		;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 715 "parser.ypp"
    {
			assertType((yyvsp[(1) - (4)]).type, TYPE_BOOL);
			assertType((yyvsp[(4) - (4)]).type, TYPE_BOOL);
			(yyval).type = TYPE_BOOL;
			
			cb.bpatch((yyvsp[(1) - (4)]).falseList, (yyvsp[(3) - (4)]).quad);
			(yyval).trueList = cb.merge((yyvsp[(1) - (4)]).trueList,(yyvsp[(4) - (4)]).trueList);
			(yyval).falseList = (yyvsp[(4) - (4)]).falseList;			
		;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 724 "parser.ypp"
    {
			assertNumber((yyvsp[(1) - (3)]).type);
			assertNumber((yyvsp[(3) - (3)]).type);
			(yyval).type = TYPE_BOOL;
			
			(yyval).trueList = cb.makelist(cb.emit(getIf(getRelop((yyvsp[(2) - (3)]).name), (yyvsp[(1) - (3)]).place, (yyvsp[(3) - (3)]).place, "")));
			(yyval).falseList = cb.makelist(cb.emit("j "));
			regsPool.release((yyvsp[(1) - (3)]).place);
			regsPool.release((yyvsp[(3) - (3)]).place);
		;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 734 "parser.ypp"
    {
	(yyval).quad = cb.next();
;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 737 "parser.ypp"
    {
	cb.next();
	(yyval).nextList = cb.makelist(cb.emit("j "));
;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 741 "parser.ypp"
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
#line 2651 "parser.tab.cpp"
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
#line 750 "parser.ypp"


int main()
{
	yyparse();
}

int yyerror(string message)
{
	output::errorSyn(yylineno);
	exit(0);
}


/***********************HW5***************************/

string getAddu (string Rdest, string Rsrc, string num2){
    return "addu " + Rdest + ", " + Rsrc + ", " + num2;
}

string getSubu (string Rdest, string Rsrc, string num2){
    return "subu " + Rdest + ", " + Rsrc + ", " + num2;
}

string getMulo (string Rdest, string Rsrc, string num2){
    return "mulo " + Rdest + ", " + Rsrc + ", " + num2;
}

string getDivu (string Rdest, string Rsrc, string src2){
    return "divu " + Rdest + ", " + Rsrc + ", " + src2;
}

string getMove (string Rdest, string Rsrc){
    return "move " + Rdest + ", " + Rsrc;
}

string getLoadint (string Rdest, string num) {
	return "li " + Rdest + ", " + num;
}

string getSw(string Rsrc, string offset, string Rdest) {
	return "sw " + Rsrc + ", " + offset + "(" + Rdest + ")";
}

string getLw(string Rdest, string offset, string Rsrc) {
	return "lw " + Rdest + ", " + offset + "(" + Rsrc + ")";
}

string emitBinop(string binop, string R1, string R2) {
	string command = "";
	switch(binop[0]) {
		case '+': command += getAddu(R1, R1, R2); break;
		case '-': command += getSubu(R1, R1, R2); break;
		case '*': command += getMulo(R1, R1, R2); break;
		case '/': command += getDivu(R1, R1, R2);
				  // push ra
				  ostringstream divOk;
				  divOk << "divOk" << divLabelIdx;
				  cb.emit(getIf("bne", R2, "0", divOk.str()));
				  cb.emit(getSubu("$sp", "$sp", "4"));
				  cb.emit(getSw("$ra", "0", "$sp"));
				  string Rdest = regsPool.allocate();
				  cb.emit("la " + Rdest + ", aErrorZeroDivision");
				  cb.emit(getSw(Rdest, "0", "$sp"));
				  regsPool.release(Rdest);
				  cb.emit("jal print");
				  cb.emit("li $v0, 10");
				  cb.emit("syscall");
				  // pop ra
    			  cb.emit(getLw("$ra", "0", "$sp"));
				  cb.emit(getAddu("$sp", "$sp", "4"));
				  
				  cb.emit(divOk.str()+":");
				  divLabelIdx++;
				  break;
	}
	cb.emit(command);
	return R1;
}

string emitBooleanAssignment(vector<address_t> trueList, vector<address_t> falseList) {
	string trueLabel = cb.next();
	string Rdest = regsPool.allocate();
	cb.emit(getLoadint(Rdest, "1"));
	vector<address_t> saveToStackList = cb.makelist(cb.emit("j "));
	cb.bpatch(trueList, trueLabel);
	string falseLabel = cb.next();
	cb.emit(getLoadint(Rdest, "0"));
	cb.bpatch(falseList, falseLabel);
	string saveToStackLabel = cb.next();
	cb.bpatch(saveToStackList, saveToStackLabel);
	return Rdest;
}

string getIf(string relop, string reg, string val, string label) {
	return relop + " " + reg + ", " + val + ", " + label;
}

string getRelop(string op) {
	if (op == "<")
		return "blt";
	if (op == "<=")
		return "ble";
	if (op == "==")
		return "beq";
	if (op == ">=")
		return "bge";
	if (op == ">")
		return "bgt";
	if (op == "!=")
		return "bne";
	return "";
}

string emitLeaf(string name) {
	string Rdest = regsPool.allocate();
	cb.emit(getLoadint(Rdest, name));
	return Rdest;
}

string loadVar(string name, STYPE* S) {
	Row* r = findDef(name);
	string Rdest = regsPool.allocate();
	ostringstream offset;
	offset << 4*(-*(r->offset));
	cb.emit(getLw(Rdest, offset.str(), "$fp"));
	if (isBool(name)) {
		S->trueList = cb.makelist(cb.emit(getIf("beq", Rdest, "1", "")));
		S->falseList = cb.makelist(cb.emit(getIf("beq", Rdest, "0", "")));
		regsPool.release(Rdest);
	}
	return Rdest;
}

void storeVar(string name, string value) {
	Row* r = findDef(name);
	ostringstream offset;
	offset << 4*(*(r->offset));
	cb.emit(getSw(value, offset.str(), "$fp"));
}

string popVars()  {
	// not enough: block inside block. 
	ostringstream tmp;	
	tmp << 4*(tables->top()->rows->size());
	return getAddu("$sp", "$sp", tmp.str());
}

void emitPrint() {
	cb.emit("print:");
	cb.emit("li $v0, 4");
	cb.emit("syscall");
	cb.emit(getAddu("$sp", "$sp", "4"));
	cb.emit("jr $ra");
}

void emitPrinti() {
	cb.emit("printi:");
	cb.emit("lw $a0, 0($sp)");
	cb.emit("li $v0, 1");
	cb.emit("syscall");
	cb.emit(getAddu("$sp", "$sp", "4"));
	cb.emit("jr $ra");
}
/* ********************************************************* */

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


bool isBool(string name) {
	Row* r = findDef(name);
	return isVar(r) && (r->type == TYPE_BOOL);
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
