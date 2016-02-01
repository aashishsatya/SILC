%{
	#include <stdio.h>
	#include <stdlib.h>

	#define YYSTYPE tnode *

	#include "expl.c"
	#include "expl.h"

  int *var[26];
%}

%union
{
	char character;
	int integer;

};

%token <character> ID
%token <integer> NUM
%type <integer> expr

%token PLUS MUL END ASGN READ WRITE LT GT EQ IF WHILE DO ENDWHILE ENDIF
%left PLUS
%left MUL
%nonassoc LT GT EQ

%%

start: slist END	{exit(1);}
	;

slist: slist stmt
	| stmt	{}
	;

stmt: ID ASGN expr ';'	{
			if(var[$1 - 'a'] == NULL) {
				var[$1 - 'a'] = malloc(sizeof(int));
			}
			*var[$1 - 'a'] = $3;
		}

		| READ '(' ID ')' ';'	{
			if (var[$3 - 'a'] == NULL) {
				var[$3 - 'a'] = malloc(sizeof(int));
			}
			scanf("%d", var[$3 - 'a']);
		}

		| WRITE '(' expr ')' ';' {
			printf("%d\n", $3);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {

		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {

		}
		;

expr: expr PLUS expr	{
	//printf("In PLUS\n");
	//printf("$1 = %d\n", $1);
	//printf("$3 = %d\n", $3);
	$$ = $1 + $3;
}
	 | expr MUL expr	{$$ = $1 * $3;}

	 | '(' expr ')'		{$$ = $2;}

	 | NUM			{$$ = $1;}

	 | ID {
    if (var[$1 - 'a'] == NULL)
      printf("Unassigned variable");
		else
			$$ = *var[$1 - 'a'];
   }

	 | expr LT expr {

	 }

	 | expr GT expr {

	 }

	 | expr EQ expr {

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
