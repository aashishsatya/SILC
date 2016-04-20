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
	struct Typetable *variable_type;	// this will store the type of the variable that is being processed
%}

%union {
	int int_val;
	struct  Tnode *tnode_ptr;
	struct Fieldlist *fields_ptr;
	struct Typetable *type_entry;
}

%token PLUS MUL ASGN READ WRITE LT GT EQ IF WHILE DO ENDWHILE ENDIF PARENS THEN ID NUM DIV MINUS DECL ENDDECL ENDOFFILE BEGINNING END MAIN RETURN LE GE TYPEDEF ALLOC
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
%type <tnode_ptr> declarations;
%type <tnode_ptr> ENDOFFILE;
%type <tnode_ptr> funcBody;
%type <tnode_ptr> funcDefn;
%type <tnode_ptr> RETURN;
%type <tnode_ptr> ArgListFunctionCall;
%type <tnode_ptr> LE;
%type <tnode_ptr> GE;
%type <type_entry> type;
%type <tnode_ptr> dataTypeName;
%type <tnode_ptr> userDataTypeAccess;

%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT EQ LE GE

%%

// now declarations mean global declarations

start: starterCode userDataTypeDecln declarations funcDefnList MainBlock ENDOFFILE	{

		if (no_defined_functions != no_declared_functions) {
			printf("All declared functions have not been defined, exiting.\n");
			exit(0);
		}

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

starterCode: {
	// this code was just meant to initialize TypeTableCreate()
	if (VAR_TYPE_INT == NULL) {
		printf("TypeTableCreate called by starter code.\n");
		TypeTableCreate();
	}
}

// grammar rules for dealing with new types

userDataTypeDecln: userDataTypeDecln dataTypeDecln {

		// add dataTypeDecln to type table

	}

	|  {}	// no user data types have been declared
	;

dataTypeDecln: TYPEDEF dataTypeName '{' fieldDeclarations '}' {

		// install ID to type table
		Tinstall($2 -> NAME, current_flist);
		struct Typetable *current_ttentry = Tlookup($2 -> NAME);

		int fieldIndex = 1;	// cannot be zero because the zeroth entry is reserved for next free block

		printf("ID'ed data type %s\n", $2 -> NAME);
		temp_flist = current_flist;
		if (temp_flist == NULL) {
			printf("current_flist is NULL.\n");
		}
		while (temp_flist != NULL) {
			// fix self-referential data types
			if (temp_flist -> type == NULL) {
				//printf("Type entry corresponding to variable %s was NULL, editing it now...\n", temp_flist -> name);
				temp_flist -> type = current_ttentry;
			}
			temp_flist -> fieldIndex = fieldIndex;
			fieldIndex++;
			printf("Stored variable %s of type %s with fieldIndex %d\n", temp_flist -> name, temp_flist -> type -> name, temp_flist -> fieldIndex);
			temp_flist = temp_flist -> next;
		}
		current_flist = NULL;	// because the next time code reaches here it will be a different type definition
		free(currently_defined_type);
		currently_defined_type = NULL;
	}
	;

dataTypeName: ID {
		if (currently_defined_type == NULL) {
			currently_defined_type = (char *) malloc(sizeof(char) * 30);
			strcpy(currently_defined_type, $1 -> NAME);
		}
		$$ = $1;
	};

fieldDeclarations: fieldDeclarations field_decln  {

		// add type_decln to fields list (current_flist)

	}

	| field_decln {

	}
	;

field_decln: ID user_type_list ';' {
		// check the ID corresponds to a data type in the type table
		struct Typetable *tt_entry = Tlookup($1 -> NAME);
		/*printf("Looked up type %s\n", $1 -> NAME);
		if (tt_entry == NULL) {
			printf("Received NULL\n");
		}*/
		if (tt_entry == NULL && strcmp($1 -> NAME, currently_defined_type) != 0) {
			printf("Line %d: undefined data type %s, exiting.\n", line_no + 1, $1 -> NAME);
		}
		// temp_current_flist will not have the field 'type' initialized because this information
		// is available only now
		// so initialize the field
		temp_flist = temp_current_flist;
		while (temp_flist != NULL) {
			temp_flist -> type = tt_entry;	// if tt_entry is NULL it'll correspond to the fact that we're
			// dealing with a self-referential data type
			temp_flist = temp_flist -> next;
		}

		// add this list to the end of current_flist
		temp_flist = temp_current_flist;
		while (temp_flist != NULL && temp_flist -> next != NULL) {
			temp_flist = temp_flist -> next;
		}
		// the if (temp_current_flist == NULL) doesn't have to be checked because there will always be
		// at least one entry
		temp_flist -> next = current_flist;
		current_flist = temp_current_flist;

		temp_current_flist = NULL;

		/*temp_flist = current_flist;
		while (temp_flist != NULL) {
			if (tt_entry != NULL)
				printf("Assigning type %s to variable %s...\n", tt_entry -> name, temp_flist -> name);
			temp_flist -> type = tt_entry;	// if tt_entry is NULL it'll correspond to the fact that we're
			// dealing with a self-referential data type
			temp_flist = temp_flist -> next;
		}*/
	}
	;

user_type_list: user_type_list ',' ID {
		temp_current_flist = Finstall($3 -> NAME);
	}

	| ID {
		temp_current_flist = Finstall($1 -> NAME);
	}
	;

// grammar rules for dealing with function definitions

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
			//printf("Stored parameter of name %s\n", temp_decln_arglist -> NAME);
			//printf("Its argument binding is %d\n", temp_decln_arglist -> ARG_SIM_BINDING);
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

		if (no_return_statements == 0) {
			printf("A return statement is required for function %s, exiting.\n", $2 -> NAME);
		}
		else if (no_return_statements != 1) {
			printf("In function %s: only one return statement is allowed (found %d), exiting.\n", $2 -> NAME, no_return_statements);
			exit(0);
		}

		if ($1 != function_return_statement_type) {
			printf("Function %s returns value of incorrect type, exiting.\n", $2 -> NAME);
			exit(0);
		}

		// actually generate the function code
		// name is needed to look up the local symbol table
		// $8 will have the slist for functions
		//printf("Creating tree for function definition of %s...\n", $2 -> NAME);
		$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, $2 -> NAME, NULL, $8, NULL, NULL, current_local_symbol_table, FALSE);

		no_defined_functions++;
		no_return_statements = 0;

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
		// check if an argument of the same name has already been declared
		temp = check_if_already_defined(current_arg_list, $3 -> NAME);
		if (temp == 1) {
			printf("Arguments of the function declaration have the same name %s, exiting.\n", $3 -> NAME);
			exit(0);
		}
		// append ID to the beginning of the argument list
		current_arg_list = ArgInstall(current_arg_list, variable_type, $3 -> NAME, PASS_BY_VALUE);
	}

	|	vbl_declns ',' '&' ID {
			temp = check_if_already_defined(current_arg_list, $4 -> NAME);
			if (temp == 1) {
				printf("Arguments of the function declaration have the same name %s, exiting.\n", $4 -> NAME);
				exit(0);
			}
			// append ID to the beginning of the argument list
			current_arg_list = ArgInstall(current_arg_list, variable_type, $4 -> NAME, PASS_BY_REFERENCE);
		}

	| ID {
		temp = check_if_already_defined(current_arg_list, $1 -> NAME);
		if (temp == 1) {
			printf("Arguments of the function declaration have the same name %s, exiting.\n", $1 -> NAME);
			exit(0);
		}
		current_arg_list = ArgInstall(current_arg_list, variable_type, $1 -> NAME, PASS_BY_VALUE);
	}

	| '&' ID {
		temp = check_if_already_defined(current_arg_list, $2 -> NAME);
		if (temp == 1) {
			printf("Arguments of the function declaration have the same name %s, exiting.\n", $2 -> NAME);
			exit(0);
		}
		current_arg_list = ArgInstall(current_arg_list, variable_type, $2 -> NAME, PASS_BY_REFERENCE);
	}
	;

// grammar for the main block (int main() {...})
MainBlock: type MAIN '(' ')' '{' localDeclarations BEGINNING slist END '}' {

		printf("Processing main function...\n");
		// add main() to the global symbol table
		Ginstall("main", variable_type, 0, NULL, FALSE);
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

		struct Tnode *main_defn = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, "main", NULL, $8, NULL, NULL, current_local_symbol_table, FALSE);
		code_gen(main_defn);

		fprintf(fp, "START\n");

		// code for initialize()

		fprintf(fp, "MOV R1, 0	// to store i\n");
		fprintf(fp, "MOV R2, 1016\n");
		fprintf(fp, "MOV R3, 8	// to store i + 8\n");
		fprintf(fp, "MOV R4, 8	// to store '8'\n");
		fprintf(fp, "MOV R0, R1	// to store '8'\n");
		fprintf(fp, "L0:\n");
		fprintf(fp, "LT R0, R2\n");
		fprintf(fp, "JZ R0, L1\n");
		fprintf(fp, "MOV [R1], R3	// heap[i] = i + 8\n");

		/*
		fprintf(fp, "MOV R5, [R1]\n");
		fprintf(fp, "OUT R5\n");
		*/

		fprintf(fp, "ADD R1, R4	// i = i + 8\n");
		fprintf(fp, "ADD R3, R4\n");
		fprintf(fp, "MOV R0, R1\n");
		fprintf(fp, "JMP L0\n");
		fprintf(fp, "L1:\n");
		fprintf(fp, "MOV R0, 1016	// there are no free entries after this entry\n");
		fprintf(fp, "MOV [R0], -1\n");
		fprintf(fp, "MOV R0, 1024	// this will store the location of the next free entry\n");
		fprintf(fp, "MOV [R0], 0\n");

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
		printf("Installed local variable %s as type %s\n", $3 -> NAME, variable_type -> name);
	}

	| ID {
		Linstall(current_local_symbol_table, $1 -> NAME, variable_type);
		printf("Installed local variable %s as type %s\n", $1 -> NAME, variable_type -> name);
	}
	;

funcBody: BEGINNING slist END {
		// generate code for the function here
		// printf("Looking into the function body (code should be generated here)...\n");
		$$ = $2;
	}
	;

slist: slist stmt	{$$ = TreeCreate(NULL, NODETYPE_SLIST, -1, NULL, NULL, $1, $2, NULL, current_local_symbol_table, FALSE);}
	| stmt	{$$ = $1;}
	;

// all these are for global variables

declarations: DECL dec_list ENDDECL {};

dec_list: dec dec_list {}
	| dec {}
	;

// a declaration is a type followed by a name followed by [], which are optional

type:	ID {
		variable_type = Tlookup($1 -> NAME);
		$$ = variable_type;
	}
	;

dec: type id_list ';' {};

id_list:	id_list ',' ID	{
		printf("Global variable %s installed as %s\n", $3 -> NAME, variable_type -> name);
		Ginstall($3 -> NAME, variable_type, 1, NULL, FALSE);
	}

	| id_list ',' ID '[' NUM ']' {
		printf("Installing array %s\n", $3 -> NAME);
		$5 -> TYPE = VAR_TYPE_INT;
		Ginstall($3 -> NAME, variable_type, $5 -> VALUE, NULL, TRUE);
	}

	|	ID {
		Ginstall($1 -> NAME, variable_type, 1, NULL, FALSE);
		printf("Global variable %s installed as %s\n", $1 -> NAME, variable_type -> name);
	}

	| ID '[' NUM ']' {
		$3 -> TYPE = VAR_TYPE_INT;
		Ginstall($1 -> NAME, variable_type, $3 -> VALUE, NULL, TRUE);
	}

	| id_list ',' ID '(' ArgList ')' {

			// function declaration

			Ginstall($3 -> NAME, variable_type, 0, current_arg_list, FALSE);	// size is irrelevant here
			no_declared_functions++;
			// so is the SIM_BINDING field
			// but sim_binding value that's used must not be changed, hence the zero for the size
			current_arg_list = NULL;
			current_arg_binding	= 3;

		}

	| ID '(' ArgList ')' {

		Ginstall($1 -> NAME, variable_type, 0, current_arg_list, FALSE);
		no_declared_functions++;
		current_arg_list = NULL;
		current_arg_binding	= 3;

	}
	;

stmt: userDataTypeAccess ASGN expr ';' {
			$$ = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, $1, $3, NULL, current_local_symbol_table, FALSE);
		}

		/*

		|	ID ASGN expr ';'	{
			//printf("Making ID node for %s\n", $1 -> NAME);
			$1 -> ArgList = current_arg_list;
			$1 -> Lentry = current_local_symbol_table;
			$1 -> TYPE = find_id_type($1);
			//printf("id type = %d\n", $1 -> TYPE);
			//printf("expr type = %d\n", $3 -> TYPE);
			if ($1 -> TYPE != $3 -> TYPE) {
				printf("Inconsistent types for assignment at line %d; exiting.\n", line_no + 1);
				exit(0);
			}
			$$ = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, $1, $3, NULL, current_local_symbol_table, FALSE);
		}

		| ID '[' expr ']' ASGN expr ';' {
			$1 -> ArgList = current_arg_list;
			$1 -> Lentry = current_local_symbol_table;
			$1 -> TYPE = find_id_type($1);
			$1 -> array_or_not = find_array_or_not($1);
			if (!($1 -> array_or_not)) {
				printf("Trying to index into a non-array variable %s of type %s; exiting.\n", $1 -> NAME, $1 -> TYPE -> name);
				exit(0);
			}
			// means ID is array alright
			// now we just have to check if expr is compatible with ID
			if ($1 -> TYPE != $6 -> TYPE) {
				printf("Inconsistent types for assignment; exiting.\n");
				exit(0);
			}
			struct Tnode *new_id_node = TreeCreate($1 -> TYPE, ID, -1, $1 -> NAME, NULL, $3, NULL, NULL, current_local_symbol_table, FALSE);
			////printf("Making ID array node\n");
			$$ = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, new_id_node, $6, NULL, current_local_symbol_table, FALSE);
		}

		*/

		| ALLOC '(' userDataTypeAccess ')' ';' {
			$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_ALLOC, -1, NULL, current_arg_list, $3, NULL, NULL, current_local_symbol_table, FALSE);

		}

		/*

		| READ '(' ID ')' ';'	{
			$3 -> ArgList = current_arg_list;
			$3 -> Lentry = current_local_symbol_table;
			$3 -> TYPE = find_id_type($3);
			//printf("id type = %d\n", $3 -> TYPE);
			if ($3 -> TYPE != VAR_TYPE_INT) {
 			 printf("READ variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, $3, NULL, NULL, current_local_symbol_table, FALSE);
		}

		| READ '(' ID '[' expr ']' ')' ';'	{
			$3 -> ArgList = current_arg_list;
			$3 -> Lentry = current_local_symbol_table;
			$3 -> TYPE = find_id_type($3);
			$3 -> array_or_not = find_array_or_not($3);
			//printf("id type read = %d\n", $3 -> TYPE);
			// this is READ for arrays
			// reason why you can't have READ(expr) (similar to WRITE below)
			// is because READ can only read into VARIABLES (and not expressions).
			// e.g. any statements of the form read(a + b + c) (which is an expr) is
			// wrong, but write(a + b + c) works

			// but before all that check the type of variables
			if ($3 -> TYPE != VAR_TYPE_INT || !$3 -> array_or_not) {
				printf("Incorrect array type for READ statement; exiting.\n");
				exit(0);
			}
			if ($5 -> TYPE != VAR_TYPE_INT) {
				printf("Incorrect index type for array; exiting.\n");
				exit(0);
			}
			struct Tnode *new_id_node = TreeCreate(NULL, ID, -1, $3 -> NAME, NULL, $5, NULL, NULL, current_local_symbol_table, FALSE);
			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, new_id_node, NULL, NULL, current_local_symbol_table, FALSE);
		}

		*/

		| READ '(' userDataTypeAccess ')' ';' {

			if ($3 -> TYPE != VAR_TYPE_INT) {
				printf("Line %d, error: you can read only into an integer variable, exiting.\n", line_no + 1);
				exit(0);
			}

			// this is READ for arrays
			// reason why you can't have READ(expr) (similar to WRITE below)
			// is because READ can only read into VARIABLES (and not expressions).
			// e.g. any statements of the form read(a + b + c) (which is an expr) is
			// wrong, but write(a + b + c) works

			$$ = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, $3, NULL, NULL, current_local_symbol_table, FALSE);
		}

		| WRITE '(' expr ')' ';' {
			if ($3 -> TYPE != VAR_TYPE_INT) {
 			 printf("WRITE variable was of type %s (should have been integer); exiting.\n", $3 -> TYPE -> name);
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, WRITE, -1, NULL, current_arg_list, $3, NULL, NULL, current_local_symbol_table, FALSE);
		}

		| IF '(' expr ')' THEN slist ENDIF ';' {
			if ($3 -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for if condition statement; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, current_arg_list, $3, $6, NULL, current_local_symbol_table, FALSE);
		}

		| WHILE '(' expr ')' DO slist ENDWHILE ';' {
			if ($3 -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for while loop condition; exiting.\n");
 			 exit(0);
 		  }
			$$ = TreeCreate(VAR_TYPE_VOID, WHILE, -1, NULL, current_arg_list, $3, $6, NULL, current_local_symbol_table, FALSE);
		}

		| RETURN expr ';' {
			$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_RETURN_STMT, -1, NULL, current_arg_list, $2, NULL, NULL, current_local_symbol_table, FALSE);
			function_return_statement_type = $2 -> TYPE;
			no_return_statements++;
		}
		;

userDataTypeAccess: userDataTypeAccess '.' ID {

		// check if ID is a type other than integer and boolean
		// but this is a little tricky
		// you have to draw up the type of userDataTypeAccess ($1)
		// then go through its field entries in the type table

		struct Typetable *uDataType = $1 -> TYPE;
		struct Fieldlist *flist = uDataType -> fields;
		while (flist != NULL) {
			if (strcmp(flist -> name, $3 -> NAME) == 0) {
				break;
			}
			flist = flist -> next;
		}

		$$ = TreeCreate(flist -> type, NODETYPE_STRUCT_ELEM_ACCESS, -1, $1 -> NAME, current_arg_list, $1, $3, NULL, current_local_symbol_table, FALSE);

	}

	// we don't have to check for userDataTypeAccess '.' ID '[' expr ']' because a structure can never have
	// an array as a member

	| ID {
		$1 -> ArgList = current_arg_list;
		$1 -> Lentry = current_local_symbol_table;
		$1 -> TYPE = find_id_type($1);
		$1 -> array_or_not = find_array_or_not($1);
		$$ = TreeCreate($1 -> TYPE, NODETYPE_STRUCT_ELEM_ACCESS, -1, $1 -> NAME, current_arg_list, $1, NULL, NULL, current_local_symbol_table, FALSE);
	}

	| ID '[' expr ']' {

		// to deal with the case of plain old array access

		if ($1 -> TYPE == VAR_TYPE_BOOL || $1 -> TYPE == VAR_TYPE_INT) {
			// can be referencing an array
 		 //printf("ID given array\n");
 		 //printf("name = %s\n", $1 -> NAME);
 		 $1 -> ArgList = current_arg_list;
 		 $1 -> Lentry = current_local_symbol_table;
 		 $1 -> TYPE = find_id_type($1);
 		 $1 -> array_or_not = find_array_or_not($1);
 		 if ($3 -> TYPE != VAR_TYPE_INT) {
 			 printf("Line %d: incorrect type for array index; exiting.\n", line_no + 1);
 			 exit(0);
 		 }
 		 if (!$1 -> array_or_not) {
 			 printf("Trying to index into a non-array variable %s; exiting.\n", $1 -> NAME);
 			 exit(0);
 		 }
 		 $$ = TreeCreate($1 -> TYPE, ID, -1, $1 -> NAME, current_arg_list, $3, NULL, NULL, current_local_symbol_table, FALSE);
		}

		// to deal with if structures are involved

		$$ = TreeCreate($1 -> TYPE, NODETYPE_STRUCT_ELEM_ACCESS, -1, $1 -> NAME, current_arg_list, $1, NULL, $3, current_local_symbol_table, FALSE);
	}
	;

// the arguments to functions can be
ArgListFunctionCall:	ArgListFunctionCall ',' expr {
		$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, $1, $3, NULL, NULL, FALSE);
	}

	|	expr {
		$$ = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, NULL, $1, NULL, NULL, FALSE);
	}

	|  {}	// no arguments
	;

expr: expr PLUS expr	{
		$$ = makeOperatorNode(PLUS, $1, $3, current_local_symbol_table, current_arg_list);
	}
	 | expr MUL expr	{$$ = makeOperatorNode(MUL, $1, $3, current_local_symbol_table, current_arg_list);}

	 | expr MINUS expr	{$$ = makeOperatorNode(MINUS, $1, $3, current_local_symbol_table, current_arg_list);}

	 | expr DIV expr	{$$ = makeOperatorNode(DIV, $1, $3, current_local_symbol_table, current_arg_list);}

	 | '(' expr ')'		{$$ = TreeCreate($2 -> TYPE, PARENS, -1, NULL, NULL, $2, NULL, NULL, current_local_symbol_table, FALSE);}

	 | NUM			{$1 -> TYPE = VAR_TYPE_INT; $$ = $1;}

	 /*

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
		 $1 -> array_or_not = find_array_or_not($1);
		 if ($3 -> TYPE != VAR_TYPE_INT) {
			 printf("Line %d: incorrect type for array index; exiting.\n", line_no + 1);
			 exit(0);
		 }
		 if (!$1 -> array_or_not) {
			 printf("Trying to index into a non-array variable %s; exiting.\n", $1 -> NAME);
			 exit(0);
		 }
		 $$ = TreeCreate($1 -> TYPE, ID, -1, $1 -> NAME, current_arg_list, $3, NULL, NULL, current_local_symbol_table, FALSE);
	 }

	 */

	 | userDataTypeAccess {
		 	$$ = $1;
	 }

	 | ID '(' ArgListFunctionCall ')' {
		 // the most complex of them all, function call
		 // just create a new node that will be processed by codegenfunc.c
		 struct Gsymbol *function_call_lookup = Glookup($1 -> NAME);
		 if (function_call_lookup == NULL) {
			 printf("Error, undeclared function %s\n", $1 -> NAME);
			 exit(0);
		 }

		 // check the number of arguments

		 current_fn_args = $3;
		 temp_current_arg_list = function_call_lookup -> ARGLIST;
		 while (current_fn_args != NULL) {
			 if (current_fn_args -> Ptr2 != NULL) {
				 if (current_fn_args -> Ptr2 -> TYPE != temp_current_arg_list -> TYPE) {
					 printf("Incorrect argument type for function call %s at line %d, exiting.\n", $1 -> NAME, line_no);
				 }
				 //printf("Line %d: checking %s against argument %s\n", line_no + 1, current_fn_args -> Ptr2 -> NAME, temp_current_arg_list -> NAME);
				 current_fn_args = current_fn_args -> Ptr1;
				 temp_current_arg_list = temp_current_arg_list -> NEXT;
			 }
		 }

		 if (temp_current_arg_list != NULL || current_fn_args != NULL) {
			 printf("temp_current_arg_list has value %s\n", temp_current_arg_list -> NAME);
			 printf("Incorrect number of arguments in function call %s at line %d, exiting.\n", $1 -> NAME, line_no);
			 exit(0);
		 }

		 $$ = TreeCreate(function_call_lookup -> TYPE, NODETYPE_FUNCTION_CALL, -1, $1 -> NAME, current_arg_list, $3, NULL, NULL, current_local_symbol_table, FALSE);
		 //current_arg_list = NULL;
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
