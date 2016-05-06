%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	#include "expl.h"

	int line_no = 0;
%}

whitespaces [ \t]
NL 	[\n]

%%

<<EOF>>    	{return ENDOFFILE;} //returns end of file
{NL}    {line_no++;}
{whitespaces} ;

[0-9]+  {
	//printf("ID'ed NUM, working...\n");
	//printf("Value of NUM = %d\n", atoi(yytext));
	yylval.tnode_ptr = TreeCreate(NULL, NUM, atoi(yytext), NULL, NULL, NULL, NULL, NULL, NULL, FALSE);
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
"begin" {return BEGINNING;}
"end" {return END;}
"main" {return MAIN;}
"return" {return RETURN;}
"typedef" {return TYPEDEF;}
"alloc" {return ALLOC;}

"NULL" {
	yylval.tnode_ptr = TreeCreate(NULL, NULL_NODE, -1, NULL, NULL, NULL, NULL, NULL, NULL, FALSE);
	return NULL_NODE;
}

[a-z][a-zA-Z0-9]* {

	char *variable_name = (char *) malloc (50 * sizeof(yytext));
	strcpy(variable_name, yytext);

	// note no information if it is an array or anything has been stored
	// you don't even know if the ID that is being referenced is an array and
	// the programmer is asking for a particular index
	// that has to be taken care of by the expl.y file
	yylval.tnode_ptr = TreeCreate(NULL, ID, -1, variable_name, NULL, NULL, NULL, NULL, NULL, FALSE);	// it's because we're initializing the last parameter
	// here as NULL that we have to include the statement $x -> Lentry = current_local_symbol_table everywhere

	return ID;
}

"-"	{return MINUS;}
"+"	{return PLUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"<" {return LT;}
">" {return GT;}
"<=" {return LE;}
">=" {return GE;}
"==" {return EQ;}
"!=" {return NEQ;}
[=]  {return ASGN;}
[();\[\],\{\}\&\.]	{return *yytext;}

.	{printf("The unknown character is: %s\n", yytext);yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
