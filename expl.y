%{
	#include <stdio.h>
	#include <stdlib.h>

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

%token PLUS MUL END ASGN READ WRITE
%left PLUS
%left MUL

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
