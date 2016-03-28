%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "y.tab.h"
	#include "codegenfunc.c"

	int yylex(void);
	extern FILE *yyin;

  //int *var[26];
	int variable_type;	// this will store the type of the variable that is being processed
%}

%union {
	int int_val;
	struct  Tnode *tnode_ptr;
}

%token PLUS MUL ASGN READ WRITE LT GT EQ IF WHILE DO ENDWHILE ENDIF PARENS THEN ID NUM DIV MINUS DECL ENDDECL BOOL INT ENDOFFILE BEGINNING END MAIN
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

// now declarations mean global declarations

start: declarations funcDefnList MainBlock ENDOFFILE	{

		printf("In start...\n");

		fp = NULL;
		fp = fopen("intermediate_code", "w+");
		if (fp == NULL) {
			printf("Error opening file, exiting");
		}

		fprintf(fp, "START\n");
		//code_gen($3);	// generate the intermediate code
		fprintf(fp, "HALT\n");

		fclose(fp);

		// deallocate memory used in symbol table

		struct Gsymbol *temp = global_symbol_table_start;
		while (temp != NULL) {
			global_symbol_table_start = global_symbol_table_start -> NEXT;
			free(temp);
			temp = global_symbol_table_start;
		}

		exit(1);
	}
	;

funcDefnList: funcDefnList funcDefn {}
	|		{}
	;

funcDefn:	type ID '(' ArgList ')' '{' localDeclarations funcBody '}' {

		printf("Processing function %s...\n", $2 -> NAME);

		// check if the function name has been declared earlier

		// check if the number of arguments and their types are correct
		struct Gsymbol *fn_declaration = Glookup($2 -> NAME);
		// fn_declaration -> ARGLIST will contain the arguments of the function
		// this will have been declared by the 'declarations' section
		struct ArgStruct *fn_decln_arglist = fn_declaration -> ARGLIST;
		struct ArgStruct *fn_defn_arglist = current_arg_list;	// hope the names are clear
		struct ArgStruct *temp_decln_arglist = fn_decln_arglist;
		struct ArgStruct *temp_defn_arglist = fn_defn_arglist;

		current_arg_list = NULL;	// again, bug if not added
		// this will reset the argument list of functions so that new functions when
		// parsed can simply set this variable (see below rule) and continue

		while (temp_decln_arglist != NULL && temp_defn_arglist != NULL) {
			printf("Stored parameter of name %s\n", temp_decln_arglist -> NAME);
			if (strcmp(temp_decln_arglist -> NAME, temp_defn_arglist -> NAME) != 0) {
				printf("Arguments in declaration and definition of function %s are not the same type, exiting.\n", $2 -> NAME);
				exit(0);
			}
			if (temp_decln_arglist -> TYPE  != temp_defn_arglist -> TYPE) {
				printf("Arguments in declaration and definition of function %s are not the same type, exiting.\n", $2 -> NAME);
				exit(0);
			}
			temp_decln_arglist = temp_decln_arglist -> NEXT;
			temp_defn_arglist = temp_defn_arglist -> NEXT;
		}

		if (temp_defn_arglist != NULL || temp_decln_arglist != NULL) {
			printf("Incorrect number of arguments in declaration and definition of function %s, exiting.\n", $2 -> NAME);
			exit(0);
		}

		// function body can be just stored in any of $1, $2 or $3
		// or directly generate the code here?

		// DO NOT FORGET TO SET current_local_symbol_table AS NULL -- BUG OTHERWISE!!
		current_local_symbol_table = NULL;

	}
	;

	ArgList: type vbl_declns ';' ArgList {

		}

		| type vbl_declns {

		}

		|  {}	// no arguments?
		;

vbl_declns:	ID ',' vbl_declns {

		// append ID to the beginning of the argument list

		struct ArgStruct *new_arg_list = (struct ArgStruct *) malloc(sizeof(struct ArgStruct));
		new_arg_list -> TYPE = variable_type;
		new_arg_list -> NAME = $1 -> NAME;
		new_arg_list -> NEXT = current_arg_list;
		new_arg_list -> BINDING = (int *) malloc(sizeof(int));
		current_arg_list = new_arg_list;

	}

	| ID {

		struct ArgStruct *new_arg_list = (struct ArgStruct *) malloc(sizeof(struct ArgStruct));
		new_arg_list -> TYPE = variable_type;
		new_arg_list -> NAME = $1 -> NAME;
		new_arg_list -> NEXT = current_arg_list;
		new_arg_list -> BINDING = (int *) malloc(sizeof(int));
		current_arg_list = new_arg_list;

	}

// grammar for the main block (int main() {...})
MainBlock: INT MAIN '(' ')' '{' localDeclarations BEGINNING slist END '}' {
		printf("Processing main function...\n");
	}


// grammar for local declarations
// here the difference from global declarations is that function declarations are not allowed
// also you can't declare arrays

localDeclarations:	DECL local_dec_list ENDDECL {}

local_dec_list: local_dec local_dec_list {}
	| local_dec {}
	;

local_dec: type local_id_list ';' {}

local_id_list: local_id_list ',' ID {
		// install this in the LOCAL symbol table for a function
		Linstall(current_local_symbol_table, $3 -> NAME, variable_type);
		printf("Installed variable %s\n", $3 -> NAME);
	}

	| ID {
		Linstall(current_local_symbol_table, $1 -> NAME, variable_type);
		printf("Installed variable %s\n", $1 -> NAME);
	}
	;

funcBody: BEGINNING slist END {
		// generate code for the function here
		printf("Looking into the function body (code should be generated here)...\n");
	}
	;

slist: slist stmt	{$$ = TreeCreate(-1, NODETYPE_SLIST, -1, NULL, NULL, $1, $2, NULL);}
	| stmt	{$$ = $1;}
	;

// all these are for global variables

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

	| id_list ',' ID '(' ArgList ')' {

			// function declaration

			Ginstall($3 -> NAME, variable_type, -1, current_arg_list);	// size is irrelevant here
			current_arg_list = NULL;

		}

	| ID '(' ArgList ')' {

		Ginstall($1 -> NAME, variable_type, -1, current_arg_list);
		current_arg_list = NULL;

	}
	;

stmt: ID ASGN expr ';'	{
			//printf("Making ID node for %s\n", $1 -> NAME);
			$1 -> ArgList = current_arg_list;
			$1 -> Lentry = current_local_symbol_table;
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
			$1 -> ArgList = current_arg_list;
			$1 -> Lentry = current_local_symbol_table;
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
			$3 -> ArgList = current_arg_list;
			$3 -> Lentry = current_local_symbol_table;
			$3 -> TYPE = find_id_type($3);
			//printf("id type = %d\n", $3 -> TYPE);
			if ($3 -> TYPE != VAR_TYPE_INT) {
 			 printf("READ variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, NULL, $3, NULL, NULL);
		}

		| READ '(' ID '[' expr ']' ')' ';'	{
			$3 -> ArgList = current_arg_list;
			$3 -> Lentry = current_local_symbol_table;
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
		$1 -> Lentry = current_local_symbol_table;
 		$1 -> ArgList = current_arg_list;
		// since it can be assumed that this variable would already exist,
		// we can look it up and assign its type to it
		$1 -> TYPE = find_id_type($1);
    $$ = $1;
   }

	 | ID '[' expr ']' {
		 // can be referencing an array
		 //printf("ID given array\n");
		 //printf("name = %s\n", $1 -> NAME);
		 $1 -> ArgList = current_arg_list;
		 $1 -> Lentry = current_local_symbol_table;
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

	return 0;
}
