%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "expl.c"
	#include "y.tab.h"

	int yylex(void);
	extern FILE *yyin;

  int *var[26];
	int variable_type;	// this will store the type of the variable that is being processed
%}

%union {
	int int_val;
	struct  Tnode *tnode_ptr;
}

%token PLUS MUL ASGN READ WRITE LT GT EQ IF WHILE DO ENDWHILE ENDIF PARENS THEN ID NUM DIV MINUS DECL ENDDECL BOOL INT ENDOFFILE
%type <tnode_ptr> expr;
%type <tnode_ptr> stmt;
%type <tnode_ptr> NUM;
%type <tnode_ptr> start;
%type <tnode_ptr> slist;
%type <tnode_ptr> ID;
%type <tnode_ptr> PLUS;
%type <tnode_ptr> DIV;
%type <tnode_ptr> MINUS;
%type <tnode_ptr> MUL;
%type <tnode_ptr> ASGN;
%type <tnode_ptr> READ;
%type <tnode_ptr> WRITE;
%type <tnode_ptr> LT;
%type <tnode_ptr> GT;
%type <tnode_ptr> EQ;
%type <tnode_ptr> IF;
%type <tnode_ptr> WHILE;
%type <tnode_ptr> DO;
%type <tnode_ptr> ENDWHILE;
%type <tnode_ptr> ENDIF;
%type <tnode_ptr> PARENS;
%type <tnode_ptr> THEN;
%type <tnode_ptr> DECL;
%type <tnode_ptr> ENDDECL;
%type <tnode_ptr> INT;
%type <tnode_ptr> BOOL;
%type <tnode_ptr> declarations;
%type <tnode_ptr> ENDOFFILE;

%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT EQ

%%

start: declarations slist ENDOFFILE	{
		evaluate($2);	// evaluate statements
		exit(1);
	}
	;

slist: slist stmt	{$$ = TreeCreate(-1, NODETYPE_SLIST, -1, NULL, NULL, $1, $2, NULL);}
	| stmt	{$$ = $1;}
	;

declarations: DECL dec_list ENDDECL {}

dec_list: dec dec_list {}
	| dec {}
	;

// a declaration is a type followed by a name followed by [], which are optional

type: INT {variable_type = VAR_TYPE_INT;}
	| BOOL {variable_type = VAR_TYPE_BOOL;}
	;

dec: type id_list ';' {}

id_list:	id_list ',' ID	{
		Ginstall($3 -> NAME, variable_type, 1, NULL);
	}

	| id_list ',' ID '[' NUM ']' {
		Ginstall($3 -> NAME, variable_type, $5 -> VALUE, NULL);
	}

	|	ID {
		Ginstall($1 -> NAME, variable_type, 1, NULL);
	}

	| ID '[' NUM ']' {
		Ginstall($1 -> NAME, variable_type, $3 -> VALUE, NULL);
	}
	;

stmt: ID ASGN expr ';'	{
			printf("Found assignment operation..\n");
			$$ = TreeCreate(-1, ASGN, -1, NULL, NULL, $1, $3, NULL);
			printf("TreeCreate for ASGN successful.\n");
		}

		| READ '(' ID ')' ';'	{
			$$ = TreeCreate(-1, READ, -1, NULL, NULL, $3, NULL, NULL);
		}

		| WRITE '(' expr ')' ';' {
			$$ = TreeCreate(-1, WRITE, -1, NULL, NULL, $3, NULL, NULL);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {
			$$ = TreeCreate(-1, IF, -1, NULL, NULL, $3, $6, NULL);
		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {
			$$ = TreeCreate(-1, WHILE, -1, NULL, NULL, $3, $6, NULL);
		}
		;

expr: expr PLUS expr	{
		$$ = makeOperatorNode(PLUS, $1, $3);
	}
	 | expr MUL expr	{$$ = makeOperatorNode(MUL, $1, $3);}

	 | expr MINUS expr	{$$ = makeOperatorNode(MINUS, $1, $3);}

	 | expr DIV expr	{$$ = makeOperatorNode(DIV, $1, $3);}

	 | '(' expr ')'		{$$ = TreeCreate(-1, PARENS, -1, NULL, NULL, $2, NULL, NULL);}

	 | NUM			{printf("Found NUM...\n");$$ = $1;}

	 | ID {
    $$ = $1;
   }

	 | expr LT expr {
		 $$ = makeOperatorNode(LT, $1, $3);
	 }

	 | expr GT expr {
		 $$ = makeOperatorNode(GT, $1, $3);
	 }

	 | expr EQ expr {
		 $$ = makeOperatorNode(EQ, $1, $3);
	 }
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(int argc, char *argv[]) {
	if(argc>1)
	{
    	FILE *fp = fopen(argv[1],"r");
    	if(fp)
        	yyin = fp;
	}
	yyparse();
	return 0;
}
