%{
/* Decleration section */


#include <stdio.h>
#include <string.h>

#include "hw4.hpp"
#include "hw4.tab.hpp"
#include "output.hpp"

using namespace output;
%}

%option yylineno
%option noyywrap
digit 		([0-9])
letter 		([a-zA-Z])
alphaNumeric 	([a-zA-Z0-9])
whitespace 	([\t\n\r ])
ger		([\"])
t		[^\-]
d		[^>\-]
/*Rules section*/
%%
\{			return LC;
\}			return RC;
\(			return LP;
\)			return RP;
;			return SC;
=			return ASSIGN;
[+]			return PLUS;
[-]			return MINUS;
[*]			return MULT;
[/]			return DIV;
(<=|>=|>=|<|>)		return REL_OP;
(==|!=)			return REL_OP_EQ;
and			return AND;
or			return OR;
sec			{yylval.type = SECOND_TYPE; return SECOND;}
min			{yylval.type = MINUTE_TYPE; return MINUTE;}
hr			{yylval.type = HOUR_TYPE; return HOUR;}
day			{yylval.type = DAY_TYPE; return DAY;}
week			{yylval.type = WEEK_TYPE; return WEEK;}
int			{yylval.type = INT_TYPE; return INT;}
print			return PRINT;
input			return INPUT;
\"[^"]*\"		return STRING;
true			return TRUE;
false			return FALSE;
if			return IF;
else			return ELSE;
while			return WHILE;
break			return BREAK;
not			return NOT;
bool			{yylval.type = BOOL_TYPE; return BOOL;}
[1-9][0-9]*|0		return NUM;
switch			return SWITCH;
case			return CASE;
([a-zA-Z])+		{ yylval.name = yytext; return ID;}
"//"[^\n]*\n		;
:			return COLON;
{whitespace}		;
.			{yyerror("");}
%%

void yyerror(const char* s) {
	errorLex(yylineno); exit(0);
}
