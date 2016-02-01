%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "y.tab.h"
%}

%%

[a-z] { yylval.character = yytext[0]; return ID;}
[0-9]+  { yylval.integer = atoi(yytext); return NUM;}
"read"   { return READ;}
"write" {return WRITE;}
[=]      { return ASGN;}
"+"	{return PLUS;}
"*"	{return MUL;}
[ \t]	{}
[();]	{return *yytext;}
[\n]	{return END;}
.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
