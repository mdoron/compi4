%{
#include "attributes.hpp"
#include "parser.tab.hpp"
#include "output.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace output;

string saveyy;
%}

%option yylineno
%option noyywrap


%%
void 									return VOID;
int										return INT;
byte									return BYTE;
b										{ yylval.name = yytext; return B; }
bool 									return BOOL;
and 									return AND;
or 										return OR;
not 									return NOT;
true 									return TRUE;
false 									return FALSE;
return 									return RETURN;
if										return IF;
else									return ELSE;
while									return WHILE;
switch									return SWITCH;
case						  			return CASE;
break									return BREAK;
:								  		return COLON;
;								  		return SC;
,							  			return COMMA;
\(										return LPAREN;
\)										return RPAREN;
\{										return LBRACE;
\}										return RBRACE;
[=]										return ASSIGN;
(==|!=|<|>|<=|>=)		  				{ yylval.name = yytext; return RELOP; }
[\\*|/]					     			{ yylval.name=yytext; return MULTOP; }
[\+|\-]			   			  			{ yylval.name=yytext; return PLUSOP; }
\"[^"]*\" 								{ yylval.name = yytext; return STRING; }
[a-zA-Z][a-zA-Z0-9]*					{ saveyy=yytext; yylval.name=yytext; return ID; }
(0|[1-9][0-9]*)      					{ yylval.type = TYPE_INT; yylval.name=yytext; return NUM; }
\/\/[^\r\n]*[\r|\n|\r\n]?   			{}
[ \t\n\r]           					{}
.                  						{ errorLex(yylineno); }
%%