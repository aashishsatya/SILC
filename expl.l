%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

[a-z] {
	char variable_name = yytext[0];
	yylval.tnode_ptr = (struct Tnode *) TreeCreate(-1, ID, -1, &variable_name);
	//printf("Saw value %d", value);
	//yylval.tnode_ptr = value;
	return ID;
}
[0-9]+  {
	yylval.tnode_ptr = TreeCreate(-1, NUM, atoi(yytext));
	return NUM;
}

"read"   { return READ;}
"write" {return WRITE;}
"if" {return IF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"endif" {return ENDIF;}

"+"	{return PLUS;}
"*"	{return MUL;}
"<" {return LT;}
">" {return GT;}
"==" {return EQ;}
[=]  {return ASGN;}
[();]	{return *yytext;}

[ \t]	{}
[\n]	{return END;}
.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
