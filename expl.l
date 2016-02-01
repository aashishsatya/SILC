%{
	#include <stdio.h>
	#include <stdlib.h>	
%}

%%

[a-z] { yylval.character = yytext[0]; return ID;}
[0-9]+  { yylval.integer = atoi(yytext); return NUM;}

"read"   { return READ;}
"write" {return WRITE;}
"if" {return IF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"endif" {return ENDIF};

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
