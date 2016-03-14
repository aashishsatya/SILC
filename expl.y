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

%token PLUS MUL ASGN READ WRITE LT GT EQ IF WHILE DO ENDWHILE ENDIF PARENS THEN ID NUM DIV MINUS DECL ENDDECL BOOL INT ENDOFFILE BEGINNING END
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
%type <tnode_ptr> BEGINNING;
%type <tnode_ptr> END;
%type <tnode_ptr> INT;
%type <tnode_ptr> BOOL;
%type <tnode_ptr> declarations;
%type <tnode_ptr> ENDOFFILE;

%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT EQ

%%

start: declarations BEGINNING slist END ENDOFFILE	{
		evaluate($3);	// evaluate statements
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
		//printf("%s installed as %d\n", $3 -> NAME, variable_type);
		Ginstall($3 -> NAME, variable_type, 1, NULL);
		struct Gsymbol *temp = Glookup($3 -> NAME);
		if (temp != NULL) {
			//printf("Installation confirmed...\n");
		}
	}

	| id_list ',' ID '[' NUM ']' {
		switch (variable_type) {
			case VAR_TYPE_INT:
				// so the variable is of type integer
				// but it's an array
				// so install it as such
				Ginstall($3 -> NAME, VAR_TYPE_INT_ARR, $5 -> VALUE, NULL);
				break;
			case VAR_TYPE_BOOL:
				// ditto
				Ginstall($3 -> NAME, VAR_TYPE_BOOL_ARR, $5 -> VALUE, NULL);
				break;
		}
	}

	|	ID {
		Ginstall($1 -> NAME, variable_type, 1, NULL);
		//printf("%s installed as standalone variable\n", $1 -> NAME);
		struct Gsymbol *temp = Glookup($1 -> NAME);
		if (temp != NULL) {
			//printf("Installation confirmed...\n");
		}
	}

	| ID '[' NUM ']' {
		switch (variable_type) {
			case VAR_TYPE_INT:
				// so the variable is of type integer
				// but it's an array
				// so install it as such
				//variable_type = VAR_TYPE_INT_ARR;
				Ginstall($1 -> NAME, VAR_TYPE_INT_ARR, $3 -> VALUE, NULL);
				break;
			case VAR_TYPE_BOOL:
				// ditto
				//variable_type = VAR_TYPE_BOOL_ARR;
				Ginstall($1 -> NAME, VAR_TYPE_BOOL_ARR, $3 -> VALUE, NULL);
				break;
		}
		//printf("%s installed as array\n", $1 -> NAME);
	}
	;

stmt: ID ASGN expr ';'	{
			//printf("Making ID node for %s\n", $1 -> NAME);
			$1 -> TYPE = find_id_type($1);
			//printf("id type = %d\n", $1 -> TYPE);
			//printf("expr type = %d\n", $3 -> TYPE);
			if ($1 -> TYPE != $3 -> TYPE) {
				printf("Inconsistent types for assignment; exiting.\n");
				exit(0);
			}
			$$ = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, NULL, $1, $3, NULL);
		}

		| ID '[' expr ']' ASGN expr ';' {
			$1 -> TYPE = find_id_type($1);
			if ($1 -> TYPE != VAR_TYPE_INT_ARR && $1 -> TYPE != VAR_TYPE_BOOL_ARR) {
				printf("Trying to index into a non-array variable %s of type %d; exiting.\n", $1 -> NAME, $1 -> TYPE);
				exit(0);
			}
			// means ID is array alright
			// now we just have to check if expr is compatible with ID
			if (($1 -> TYPE == VAR_TYPE_INT_ARR && $6 -> TYPE == VAR_TYPE_BOOL) || ($1 -> TYPE == VAR_TYPE_BOOL_ARR && $6 -> TYPE == VAR_TYPE_INT)) {
				printf("Inconsistent types for assignment; exiting.\n");
				exit(0);
			}
			struct Tnode *new_id_node = TreeCreate($1 -> TYPE, ID, -1, $1 -> NAME, NULL, $3, NULL, NULL);
			////printf("Making ID array node\n");
			$$ = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, NULL, new_id_node, $6, NULL);
		}

		| READ '(' ID ')' ';'	{
			$3 -> TYPE = find_id_type($3);
			//printf("id type = %d\n", $3 -> TYPE);
			if ($3 -> TYPE != VAR_TYPE_INT) {
 			 printf("READ variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, NULL, $3, NULL, NULL);
		}

		| READ '(' ID '[' expr ']' ')' ';'	{
			$3 -> TYPE = find_id_type($3);
			//printf("id type read = %d\n", $3 -> TYPE);
			// this is READ for arrays
			// reason why you can't have READ(expr) (similar to WRITE below)
			// is because READ can only read into VARIABLES (and not expressions).
			// any statements of the form read(a + b + c) (which is an expr) is
			// wrong, but write(a + b + c) works

			// but before all that check the type of variables
			if ($3 -> TYPE != VAR_TYPE_INT_ARR) {
				printf("Incorrect array type for READ statement; exiting.\n");
				exit(0);
			}
			if ($5 -> TYPE != VAR_TYPE_INT) {
				printf("Incorrect index type for array; exiting.\n");
				exit(0);
			}
			struct Tnode *new_id_node = TreeCreate(-1, ID, -1, $3 -> NAME, NULL, $5, NULL, NULL);
			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, NULL, new_id_node, NULL, NULL);
		}

		| WRITE '(' expr ')' ';' {
			if ($3 -> TYPE != VAR_TYPE_INT) {
 			 printf("WRITE variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, WRITE, -1, NULL, NULL, $3, NULL, NULL);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {
			if ($3 -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for if condition statement; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, NULL, $3, $6, NULL);
		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {
			if ($3 -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for while loop condition; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, WHILE, -1, NULL, NULL, $3, $6, NULL);
		}
		;

expr: expr PLUS expr	{
		$$ = makeOperatorNode(PLUS, $1, $3);
	}
	 | expr MUL expr	{$$ = makeOperatorNode(MUL, $1, $3);}

	 | expr MINUS expr	{$$ = makeOperatorNode(MINUS, $1, $3);}

	 | expr DIV expr	{$$ = makeOperatorNode(DIV, $1, $3);}

	 | '(' expr ')'		{$$ = TreeCreate($2 -> TYPE, PARENS, -1, NULL, NULL, $2, NULL, NULL);}

	 | NUM			{$$ = $1;}

	 | ID {
		// since it can be assumed that this variable would already exist,
		// we can look it up and assign its type to it
		$1 -> TYPE = find_id_type($1);
    $$ = $1;
   }

	 | ID '[' expr ']' {
		 // can be referencing an array
		 //printf("ID given array\n");
		 //printf("name = %s\n", $1 -> NAME);
		 $1 -> TYPE = find_id_type($1);
		 if ($3 -> TYPE != VAR_TYPE_INT) {
			 printf("Incorrect type for array index; exiting.\n");
			 exit(0);
		 }
		 switch($1 -> TYPE) {
			 case VAR_TYPE_INT_ARR:
			 	$$ = TreeCreate(VAR_TYPE_INT, ID, -1, $1 -> NAME, NULL, $3, NULL, NULL);
				break;
			 case VAR_TYPE_BOOL_ARR:
			 	$$ = TreeCreate(VAR_TYPE_BOOL, ID, -1, $1 -> NAME, NULL, $3, NULL, NULL);
				break;
			 default:
			  printf("Trying to index into a non-array variable %s; exiting.\n", $1 -> NAME);
			  exit(0);
		 }
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

	// deallocate memory used in symbol table
	struct Gsymbol *temp = global_symbol_table_start;

	while (temp != NULL) {
		global_symbol_table_start = global_symbol_table_start -> NEXT;
		free(temp);
		temp = global_symbol_table_start;
	}

	return 0;
}
