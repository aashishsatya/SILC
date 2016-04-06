%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "y.tab.h"
	#include "codegenfunc.c"

	int yylex(void);
	extern FILE *yyin;
	extern int yylineno;
	extern char *yytext;
	extern int line_no;

  //int *var[26];
	int variable_type;	// this will store the type of the variable that is being processed
%}

%union {
	int int_val;
	struct  Tnode *tnode_ptr;
}

%token PLUS MUL ASGN READ WRITE LT GT EQ IF WHILE DO ENDWHILE ENDIF PARENS THEN ID NUM DIV MINUS DECL ENDDECL BOOL INT ENDOFFILE BEGINNING END MAIN RETURN LE GE
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
%type <tnode_ptr> funcBody;
%type <tnode_ptr> funcDefn;
%type <tnode_ptr> RETURN;
%type <tnode_ptr> ArgListFunctionCall;
%type <tnode_ptr> LE;
%type <tnode_ptr> GE;

%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT EQ LE GE

%%

// now declarations mean global declarations

start: declarations funcDefnList MainBlock ENDOFFILE	{

		printf("In start...\n");

		//fprintf(fp, "START\n");
		//code_gen($3);	// generate the intermediate code
		//fprintf(fp, "HALT\n");

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

funcDefnList: funcDefnList funcDefn {code_gen($2);}
	|		{}
	;

funcDefn:	type ID '(' ArgList ')' '{' localDeclarations funcBody '}' {

		printf("Processing function %s...\n", $2 -> NAME);

		// check if the function name has been declared earlier

		// check if the number of arguments and their types are correct
		struct Gsymbol *fn_declaration = Glookup($2 -> NAME);
		fn_declaration -> local_sym_table = current_local_symbol_table;
		// fn_declaration -> ARGLIST will contain the arguments of the function
		// this will have been declared by the 'declarations' section
		struct ArgStruct *fn_decln_arglist = fn_declaration -> ARGLIST;
		struct ArgStruct *fn_defn_arglist = current_arg_list;	// hope the names are clear
		struct ArgStruct *temp_decln_arglist = fn_decln_arglist;
		struct ArgStruct *temp_defn_arglist = fn_defn_arglist;

		current_arg_list = NULL;	// again, bug if not added
		current_arg_binding = 3;
		// this will reset the argument list of functions so that new functions when
		// parsed can simply set this variable (see below rule) and continue

		while (temp_decln_arglist != NULL && temp_defn_arglist != NULL) {
			printf("Stored parameter of name %s\n", temp_decln_arglist -> NAME);
			printf("Its argument binding is %d\n", temp_decln_arglist -> ARG_SIM_BINDING);
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

		// actually generate the function code
		// name is needed to look up the local symbol table
		// $8 will have the slist for functions
		printf("Creating tree for function definition of %s...\n", $2 -> NAME);
		$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, $2 -> NAME, NULL, $8, NULL, NULL, current_local_symbol_table);

		// DO NOT FORGET TO SET current_local_symbol_table AS NULL -- BUG OTHERWISE!!
		current_local_symbol_table = NULL;
		local_symbol_table_counter = 1;

		// this is where the file has to be dealt with because the rule for start won't
		// get reduced unless this has
		if (fp == NULL) {
			// means there are no function definitions
			// also we don't want fp to be initialized multiple times
			fp = fopen("intermediate_code", "w+");
			if (fp == NULL) {
				printf("Error opening file, exiting");
				exit(0);
			}
		}

	}
	;

	ArgList: type vbl_declns ';' ArgList {

		}

		| type vbl_declns {

		}

		|  {}	// no arguments?
		;

// TODO: this grammar will create problems on multiple declarations (e.g. integer a, b;); fix

vbl_declns:	vbl_declns ',' ID {
		// append ID to the beginning of the argument list
		current_arg_list = ArgInstall(current_arg_list, variable_type, $3 -> NAME, PASS_BY_VALUE);
	}

	|	vbl_declns ',' '&' ID {
			// append ID to the beginning of the argument list
			current_arg_list = ArgInstall(current_arg_list, variable_type, $4 -> NAME, PASS_BY_REFERENCE);
		}

	| ID {
		current_arg_list = ArgInstall(current_arg_list, variable_type, $1 -> NAME, PASS_BY_VALUE);
	}

	| '&' ID {
		current_arg_list = ArgInstall(current_arg_list, variable_type, $2 -> NAME, PASS_BY_REFERENCE);
	}
	;

// grammar for the main block (int main() {...})
MainBlock: type MAIN '(' ')' '{' localDeclarations BEGINNING slist END '}' {

		printf("Processing main function...\n");
		// add main() to the global symbol table
		Ginstall("main", variable_type, 0, current_arg_list);
		struct Gsymbol *main_symbol_table_entry = Glookup("main");
		main_symbol_table_entry -> local_sym_table = current_local_symbol_table;

		// this is where the file has to be dealt with because the rule for start won't
		// get reduced unless this has
		if (fp == NULL) {
			// means there are no function definitions
			// this is where we will have to open the file
			fp = fopen("intermediate_code", "w+");
			if (fp == NULL) {
				printf("Error opening file, exiting");
				exit(0);
			}
		}

		struct Tnode *main_defn = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, "main", NULL, $8, NULL, NULL, current_local_symbol_table);
		code_gen(main_defn);

		fprintf(fp, "START\n");
		// save space for global variables
		// it is the programmer's responsibility to suitably allocate stack pointers
		// SP will be sim_binding - 1
		fprintf(fp, "MOV SP, %d // leave space for global variables\n", sim_binding - 1);
		// leave space for local variables
		int temp = allocate_register();
		// reserve space for return value
		fprintf(fp, "PUSH R%d	// space for return value\n", temp);
		deallocate_register();
		fprintf(fp, "CALL main\n");
		// get the return value
		temp = allocate_register();
		fprintf(fp, "POP R%d\n", temp);
		fprintf(fp, "HALT\n");

		// as always
		current_arg_list = NULL;
		current_arg_binding	= 3;
	}
	;


// grammar for local declarations
// here the difference from global declarations is that function declarations are not allowed
// also you can't declare arrays

localDeclarations:	DECL local_dec_list ENDDECL {};

local_dec_list: local_dec local_dec_list {}
	| local_dec {}
	;

local_dec: type local_id_list ';' {};

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
		// printf("Looking into the function body (code should be generated here)...\n");
		$$ = $2;
	}
	;

slist: slist stmt	{$$ = TreeCreate(-1, NODETYPE_SLIST, -1, NULL, NULL, $1, $2, NULL, current_local_symbol_table);}
	| stmt	{$$ = $1;}
	;

// all these are for global variables

declarations: DECL dec_list ENDDECL {};

dec_list: dec dec_list {}
	| dec {}
	;

// a declaration is a type followed by a name followed by [], which are optional

type: INT {variable_type = VAR_TYPE_INT;}
	| BOOL {variable_type = VAR_TYPE_BOOL;}
	;

dec: type id_list ';' {};

id_list:	id_list ',' ID	{
		//printf("%s installed as %d\n", $3 -> NAME, variable_type);
		Ginstall($3 -> NAME, variable_type, 1, NULL);
	}

	| id_list ',' ID '[' NUM ']' {
		printf("Installing array %s\n", $3 -> NAME);
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

			Ginstall($3 -> NAME, variable_type, 0, current_arg_list);	// size is irrelevant here
			// so is the SIM_BINDING field
			// but sim_binding value that's used must not be changed, hence the zero for the size
			current_arg_list = NULL;
			current_arg_binding	= 3;

		}

	| ID '(' ArgList ')' {

		Ginstall($1 -> NAME, variable_type, 0, current_arg_list);
		current_arg_list = NULL;
		current_arg_binding	= 3;

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
			$$ = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, $1, $3, NULL, current_local_symbol_table);
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
			struct Tnode *new_id_node = TreeCreate($1 -> TYPE, ID, -1, $1 -> NAME, NULL, $3, NULL, NULL, current_local_symbol_table);
			////printf("Making ID array node\n");
			$$ = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, new_id_node, $6, NULL, current_local_symbol_table);
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
			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, $3, NULL, NULL, current_local_symbol_table);
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
			struct Tnode *new_id_node = TreeCreate(-1, ID, -1, $3 -> NAME, NULL, $5, NULL, NULL, current_local_symbol_table);
			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, new_id_node, NULL, NULL, current_local_symbol_table);
		}

		| WRITE '(' expr ')' ';' {
			if ($3 -> TYPE != VAR_TYPE_INT) {
 			 printf("WRITE variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, WRITE, -1, NULL, current_arg_list, $3, NULL, NULL, current_local_symbol_table);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {
			if ($3 -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for if condition statement; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, current_arg_list, $3, $6, NULL, current_local_symbol_table);
		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {
			if ($3 -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for while loop condition; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, WHILE, -1, NULL, current_arg_list, $3, $6, NULL, current_local_symbol_table);
		}

		| RETURN expr ';' {
			$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_RETURN_STMT, -1, NULL, current_arg_list, $2, NULL, NULL, current_local_symbol_table);
		}
		;

// the arguments to functions can be
ArgListFunctionCall:	ArgListFunctionCall ',' expr {
		$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, $1, $3, NULL, NULL);
	}

	|	expr {
		$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, NULL, $1, NULL, NULL);
	}

	|  {}	// no arguments
	;

expr: expr PLUS expr	{
		$$ = makeOperatorNode(PLUS, $1, $3, current_local_symbol_table, current_arg_list);
	}
	 | expr MUL expr	{$$ = makeOperatorNode(MUL, $1, $3, current_local_symbol_table, current_arg_list);}

	 | expr MINUS expr	{$$ = makeOperatorNode(MINUS, $1, $3, current_local_symbol_table, current_arg_list);}

	 | expr DIV expr	{$$ = makeOperatorNode(DIV, $1, $3, current_local_symbol_table, current_arg_list);}

	 | '(' expr ')'		{$$ = TreeCreate($2 -> TYPE, PARENS, -1, NULL, NULL, $2, NULL, NULL, current_local_symbol_table);}

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
			 	$$ = TreeCreate(VAR_TYPE_INT, ID, -1, $1 -> NAME, current_arg_list, $3, NULL, NULL, current_local_symbol_table);
				break;
			 case VAR_TYPE_BOOL_ARR:
			 	$$ = TreeCreate(VAR_TYPE_BOOL, ID, -1, $1 -> NAME, current_arg_list, $3, NULL, NULL, current_local_symbol_table);
				break;
			 default:
			  printf("Trying to index into a non-array variable %s; exiting.\n", $1 -> NAME);
			  exit(0);
		 }
	 }

	 | ID '(' ArgListFunctionCall ')' {
		 // the most complex of them all, function call
		 // just create a new node that will be processed by codegenfunc.c
		 struct Gsymbol *function_call_lookup = Glookup($1 -> NAME);
		 if (function_call_lookup == NULL) {
			 printf("Error, undeclared function %s\n", $1 -> NAME);
			 exit(0);
		 }
		 $$ = TreeCreate(function_call_lookup -> TYPE, NODETYPE_FUNCTION_CALL, -1, $1 -> NAME, current_arg_list, $3, NULL, NULL, current_local_symbol_table);
	 }

	 | expr LT expr {
		 $$ = makeOperatorNode(LT, $1, $3, current_local_symbol_table, current_arg_list);
	 }

	 | expr GT expr {
		 $$ = makeOperatorNode(GT, $1, $3, current_local_symbol_table, current_arg_list);
	 }

	 | expr EQ expr {
		 $$ = makeOperatorNode(EQ, $1, $3, current_local_symbol_table, current_arg_list);
	 }

	 | expr LE expr {
		 $$ = makeOperatorNode(LE, $1, $3, current_local_symbol_table, current_arg_list);
	 }

	 | expr GE expr {
		 $$ = makeOperatorNode(GE, $1, $3, current_local_symbol_table, current_arg_list);
	 }
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror, %s: '%s' in line %d\n", s, yytext, line_no + 1);
}

int main(int argc, char *argv[]) {
	if(argc > 1)
	{
    	FILE *fp = fopen(argv[1],"r");
    	if(fp)
        	yyin = fp;
	}
	yyparse();

	return 0;
}
