%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
%}

whitespaces [ \t]
NL 	[\n]

%%

<<EOF>>    	{return ENDOFFILE;} //returns end of file
{NL}    	;
{whitespaces} ;

[0-9]+  {
	//printf("ID'ed NUM, working...\n");
	//printf("Value of NUM = %d\n", atoi(yytext));
	yylval.tnode_ptr = TreeCreate(-1, NUM, atoi(yytext));
	//printf("Created a node for NUM...\n");
	return NUM;
}

"read"   { return READ;}
"write" {return WRITE;}
"if" {return IF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"endif" {return ENDIF;}
"then" {return THEN;}
"decl" {return DECL;}
"enddecl" {return ENDDECL;}
"integer" {return INT;}
"boolean" {return BOOL;}

[a-z][a-zA-Z0-9]* {
	//char variable_name = yytext[0];
	char *variable_name = (char *) malloc (50 * sizeof(yytext));

	strcpy(variable_name, yytext);
	//printf("Vbl name: %c\n", variable_name[0]);
	yylval.tnode_ptr = TreeCreate(-1, ID, -1, variable_name);
	//printf("Returning ID...\n");
	//printf("Saw value %d", value);
	//yylval.tnode_ptr = value;
	//printf("Reading back\n");
	//char *id_name_ptr = yylval.tnode_ptr->NAME;
	//printf("%c\n", id_name_ptr[0]);
	return ID;
}

"-"	{return MINUS;}
"+"	{return PLUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"<" {return LT;}
">" {return GT;}
"==" {return EQ;}
[=]  {return ASGN;}
[();]	{return *yytext;}

.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
