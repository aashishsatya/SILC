#include "y.tab.h"
#include "expl.h"

#include "typetables.c"

FILE *fp = NULL;  // this file pointer will be used for writing the intermediate code to a file
extern int line_no;

struct Tnode* makeOperatorNode(int OPERATOR, struct Tnode *l, struct Tnode *r, struct Lsymbol *Lentry, struct ArgStruct *current_arg_list) {
    struct Typetable *VAR_TYPE_INT = Tlookup("integer");
    struct Typetable *VAR_TYPE_BOOL = Tlookup("boolean");
    struct Tnode *temp;
    // no matter what the type of the operator pointers l and r must have -> TYPE as INT
    switch(OPERATOR) {
      case PLUS:
      case MINUS:
      case MUL:
      case DIV:
        if (l -> TYPE != VAR_TYPE_INT || r -> TYPE != VAR_TYPE_INT) {
          printf("Incorrect operand type for arithmetic operator, exiting.");
          exit(0);
        }
        temp = TreeCreate(VAR_TYPE_INT, OPERATOR, -1, NULL, current_arg_list, l, r, NULL, Lentry, FALSE);
        break;
      case LT:
      case GT:
      case LE:
      case GE:
      case NEQ:
      case EQ:
        if ((l -> TYPE != VAR_TYPE_INT || r -> TYPE != VAR_TYPE_INT) && (l -> NODETYPE != NULL_NODE) && (r -> NODETYPE != NULL_NODE)) {
          printf("Line %d: Incorrect operand type for logical operator, exiting.", line_no);
          exit(0);
        }
        temp = TreeCreate(VAR_TYPE_BOOL, OPERATOR, -1, NULL, current_arg_list, l, r, NULL, Lentry, FALSE);
        break;
      default:
        printf("Unrecognized operator, exiting.\n");
        exit(0);
    }
    return temp;
}

struct Tnode *TreeCreate(struct Typetable *TYPE, int NODETYPE, int VALUE, char *NAME, struct ArgStruct *ArgList, struct Tnode *Ptr1, struct Tnode *Ptr2, struct Tnode *Ptr3, struct Lsymbol *Lentry, int array_or_not) {

  struct Tnode *temp;
  temp = (struct Tnode*) malloc(sizeof(struct Tnode));

  // initialize member variables

  temp -> TYPE = TYPE;
  temp -> NODETYPE = NODETYPE;
  temp -> VALUE = VALUE;
  if (NAME != NULL) {
    temp -> NAME = NAME;
  }
  else {
    temp->NAME = NULL;
  }
  temp -> ArgList = ArgList;
  temp -> Ptr1 = Ptr1;
  temp -> Ptr2 = Ptr2;
  temp -> Ptr3 = Ptr3;
  temp -> Lentry = Lentry;
  temp -> array_or_not = array_or_not;

  return temp;
}

struct Gsymbol *global_symbol_table_start = NULL;
struct Gsymbol *global_symbol_table_end = NULL;  // for easier appending

struct Gsymbol *Glookup(char *NAME) // Look up for a global identifier
{
    struct Gsymbol *temp = global_symbol_table_start;
    while (temp != NULL) {
      if (strcmp(temp -> NAME, NAME) == 0) {
        return temp;
      }
      temp = temp -> NEXT;
    }
    return temp;
}

int sim_binding = 1025;  // this variable will denote the next FREE memory location

void Ginstall(char *NAME, struct Typetable *TYPE, int SIZE, struct ArgStruct *ARGLIST, int array_or_not) // Installation
{

  // check if the variable name has already been used
  struct Gsymbol *new_entry = Glookup(NAME);
  if (new_entry != NULL) {
    // variable has already been declared
    // exit with error
    printf("Variable %s has already been declared, exiting.\n", NAME);
    exit(0);
  }

  // continue with allocation

  new_entry = (struct Gsymbol *) malloc(sizeof(struct Gsymbol));
  new_entry -> NAME = NAME;
  new_entry -> TYPE = TYPE;
  new_entry -> SIZE = SIZE;
  new_entry -> ARGLIST = ARGLIST;
  new_entry -> array_or_not = array_or_not;
  new_entry -> NEXT = NULL;

  // allocate space for the new entry
  // since the storage is internally all integers, we just have to allocate space
  // for SIZE integers

  int *int_space = (int *) malloc(sizeof(int) * SIZE);
  new_entry -> BINDING = int_space;
  new_entry -> SIM_BINDING = sim_binding;
  sim_binding += SIZE;

  // update the last entry of the symbol table to point to this new entry
  if (global_symbol_table_end == NULL) {
    // first entry
    global_symbol_table_end = new_entry;
    global_symbol_table_start = new_entry;
  }
  else {
    global_symbol_table_end -> NEXT = new_entry;
    global_symbol_table_end = new_entry;
  }
}

struct Lsymbol *Llookup(struct Lsymbol *current_lentry, char *NAME) {
  while (current_lentry != NULL) {
    if (strcmp(NAME, current_lentry -> NAME) == 0) {
      return current_lentry;
    }
    current_lentry = current_lentry -> NEXT;
  }
  return current_lentry;
}

struct ArgStruct *ArgLookup(struct ArgStruct *current_args, char *NAME) {
  while (current_args != NULL) {
    if (strcmp(NAME, current_args -> NAME) == 0) {
      return current_args;
    }
    current_args = current_args -> NEXT;
  }
  return current_args;
}

int find_array_or_not(struct Tnode *ptr) {
  // check the local symbol table
  struct Lsymbol *ltemp = Llookup(ptr -> Lentry, ptr -> NAME);
  if (ltemp != NULL) {
    // no array types are allowed for local variables
    return FALSE;
  }
  // check ArgList
  struct ArgStruct *fn_arg_list = ArgLookup(ptr -> ArgList, ptr -> NAME);
  if (fn_arg_list != NULL) {
    // no array types are allowed for arguments
    return FALSE;
  }
  struct Gsymbol *temp = Glookup(ptr -> NAME);
  if (temp != NULL) {
    return temp -> array_or_not;
  }
}

struct Typetable *find_id_type(struct Tnode *ptr) {
  struct Typetable *id_type;
  // check the local symbol table
  struct Lsymbol *ltemp = Llookup(ptr -> Lentry, ptr -> NAME);
  if (ltemp != NULL) {
    // can only be boolean or int, no array types are allowed
    return ltemp -> TYPE;
  }
  // check ArgList
  struct ArgStruct *fn_arg_list = ArgLookup(ptr -> ArgList, ptr -> NAME);
  if (fn_arg_list != NULL) {
    id_type = fn_arg_list -> TYPE;
    return id_type;
  }
  struct Gsymbol *temp = Glookup(ptr -> NAME);
  if (temp != NULL) {
    return temp -> TYPE;
  }
  return NULL;  // not a valid ID type
}

// install function for local entries

struct Lsymbol *current_local_symbol_table = NULL; // this variable will be initialized by
int local_symbol_table_counter = 1; // BP - this value will be used to access the variable in the intermediate code
// the grammar rule corresponding to function declaration

void Linstall(struct Lsymbol *local_symbol_table, char *NAME, struct Typetable *TYPE) {

  struct Lsymbol *temp = local_symbol_table;

  // loop till we find the end of the linked list of the symbol table
  while (temp != NULL && temp -> NEXT != NULL) {
    // check if the variable has already been installed
    if (strcmp(temp -> NAME, NAME) == 0) {
      printf("Variable has already been installed, exiting.\n");
      exit(0);
    }
    temp = temp -> NEXT;
  }

  struct Lsymbol *new_local_entry = (struct Lsymbol *) malloc(sizeof(struct Lsymbol));
  new_local_entry -> NAME = NAME;
  new_local_entry -> TYPE = TYPE;
  new_local_entry -> NEXT = NULL;
  new_local_entry -> LOCAL_SIM_BINDING = local_symbol_table_counter;
  local_symbol_table_counter++;

  // allocate space for the variable
  int *new_entry_binding = (int *) malloc(sizeof(int));
  new_local_entry -> BINDING = new_entry_binding;

  if (temp == NULL) {
    // means current_local_symbol_table hasn't been initialized yet
    current_local_symbol_table = new_local_entry;
  }
  else {
    temp -> NEXT = new_local_entry;
  }
}

int check_if_already_defined(struct ArgStruct *arg_list, char *NAME) {
  // check if a variable of the same name already exists in the arguments
  while (arg_list != NULL) {
    if (strcmp(arg_list -> NAME, NAME) == 0) {
      // they have the same name
      return 1;
    }
    arg_list = arg_list -> NEXT;
  }
  return 0;
}

struct ArgStruct *current_arg_list; // current_arg_list will denote the argument list of the current function that we're in
struct Tnode *current_fn_args;
struct ArgStruct *temp_current_arg_list; // to check if variables of the same name have already been used
struct Gsymbol *current_function; // the symbol table entry of the current function that's being handled
// this will be used to set the ARG_SIM_BINDING field for arguments
// it's set to three because when we're calculating BP - binding, because of the return value and the
// return address, an offset of two more comes in
// hence BP - 1 (say for the first argument) - 2 = BP - 3
int current_arg_binding = 3;
int no_declared_functions = 0;
int no_defined_functions = 0;
int no_return_statements = 0;
struct Typetable *function_return_statement_type; // stores the actual type of the return statement (i.e. type of expr in 'return expr')
int temp; // to be used as and when required

char *currently_defined_type = NULL;  // this is used to deal with self-referential data types
