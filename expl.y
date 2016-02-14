%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "expl.c"

	int yylex(void);

  int *var[26];
%}

%union {
	int int_val;
	struct  Tnode *tnode_ptr;
}

%token PLUS MUL END ASGN READ WRITE LT GT EQ IF WHILE DO ENDWHILE ENDIF PARENS THEN ID NUM
%type <tnode_ptr> expr;
%type <tnode_ptr> stmt;
%type <tnode_ptr> NUM;
%type <tnode_ptr> start;
%type <tnode_ptr> slist;
%type <tnode_ptr> ID;
%type <tnode_ptr> PLUS;
%type <tnode_ptr> MUL;
%type <tnode_ptr> END;
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
%left PLUS
%left MUL
%nonassoc LT GT EQ

%%

start: slist END	{evaluate($1);exit(1);}
	;

slist: slist stmt
	| stmt	{}
	;

stmt: ID ASGN expr ';'	{
			$$ = TreeCreate(-1, ASGN, -1, NULL, NULL, $1, $3, NULL);
		}

		| READ '(' ID ')' ';'	{
			$$ = TreeCreate(-1, READ, -1, NULL, NULL, $3, NULL, NULL);
		}

		| WRITE '(' expr ')' ';' {
			$$ = TreeCreate(-1, PARENS, -1, NULL, NULL, $3, NULL, NULL);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {

		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {

		}
		;

expr: expr PLUS expr	{
		$$ = makeOperatorNode(PLUS, $1, $3);
	}
	 | expr MUL expr	{$$ = makeOperatorNode(MUL, $1, $3);}

	 | '(' expr ')'		{$$ = TreeCreate(-1, PARENS, -1, NULL, NULL, $2, NULL, NULL);}

	 | NUM			{$$ = $1;}

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


int main(void) {
	yyparse();
	return 0;
}
