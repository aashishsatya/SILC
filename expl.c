#include "y.tab.h"
#include "expl.h"

#define NODETYPE_SLIST 1

int *var[26];

// this one is to be used just to make a node (and not variables)
/*struct Tnode* makeLeafNode(int n){
    struct Tnode *temp;
      temp = TreeCreate(-1, NUM, n);  // -1 -> no relevant type
    return temp;
}*/

struct Tnode* makeOperatorNode(int c, struct Tnode *l, struct Tnode *r){
    struct Tnode *temp;
    temp = TreeCreate(-1, c, -1, NULL, NULL, l, r, NULL);
    return temp;
}

struct Tnode *TreeCreate(int TYPE, int NODETYPE, int VALUE, char *NAME, struct Tnode *ArgList, struct Tnode *Ptr1, struct Tnode *Ptr2, struct Tnode *Ptr3) {

  struct Tnode *temp;
  temp = (struct Tnode*) malloc(sizeof(struct Tnode));

  // initialize member variables

  temp -> TYPE = TYPE;
  temp -> NODETYPE = NODETYPE;
  temp -> VALUE = VALUE;
  if (NAME != NULL) {
    //temp->NAME = (char *) malloc(sizeof(NAME));
    temp -> NAME = NAME;
  }
  else {
    temp->NAME = NULL;
  }
  temp -> ArgList = ArgList;
  temp -> Ptr1 = Ptr1;
  temp -> Ptr2 = Ptr2;
  temp -> Ptr3 = Ptr3;

  return temp;
}

// TODO: Sometimes you may need to write a get_location() function.

int evaluate(struct Tnode *t){
    //printf("Starting evaluate...\n");
    struct Tnode *id_to_assign = NULL;  // in case we need to get the name of the variable to work on
    struct Tnode *next_arg;
    struct Gsymbol *id_entry; // to store the pointer to the entry in the symbol table
    int truth_value;  // for if and while
    int value_to_write;
    char *id_name; // this variable will store the name of the ID obtained from id_to_assign
    if (t == NULL) {
      //printf("t is NULL\n");
      int t_nodetype = t -> NODETYPE;
      //printf("t->NODETYPE = %d\n", t_nodetype);
    }
    switch (t -> NODETYPE) {
      case PLUS:
        return evaluate(t -> Ptr1) + evaluate(t -> Ptr2);
      case MINUS:
        return evaluate(t -> Ptr1) - evaluate(t -> Ptr2);
      case DIV:
        return evaluate(t -> Ptr1) / evaluate(t -> Ptr2);
      case MUL:
        return evaluate(t -> Ptr1) * evaluate(t -> Ptr2);
      case EQ:
        return evaluate(t -> Ptr1) == evaluate(t -> Ptr2);
      case GT:
        return evaluate(t -> Ptr1) > evaluate(t -> Ptr2);
      case LT:
        return evaluate(t -> Ptr1) < evaluate(t -> Ptr2);
      case NUM:
        // nothing to do, simply return its value
        return t -> VALUE;
      case ASGN:
        // careful here
        // if we call evaluate on ID, if ID was not previously assigned a value the program will raise an error
        // so we must do at least the LHS part of the operation here
        id_to_assign = t -> Ptr1;  // this will obviously be an ID
        // its name will be stored in NAME field
        // allocate memory accordingly
        id_name = id_to_assign -> NAME; // [0] because NAME is a pointer
        // look up the symbol in the symbol table
        id_entry = Glookup(id_name);
        if (id_entry == NULL) {
          // entry was not defined
          // error
          printf("Identifier was not declared, exiting...\n");
          exit(0);
        }
        // we have a proper ID
        // assign the value to this ID
        *(id_entry -> BINDING) = evaluate(t -> Ptr2);
        // just return something, doesn't matter what it is
        // point is, C can return any value, you just have to make sure that *SILC* doesn't.
        //printf("Returning from ASGN...\n");
        return -1;
      case ID:
        // if we call evaluate on ID, if ID was not previously assigned a value the program will raise an error
        // so we must do at least the LHS part of the operation here
        // id_to_assign = t -> Ptr1;  // this will obviously be an ID
        // its name will be stored in NAME field
        // allocate memory accordingly
        id_name = t -> NAME; // [0] because NAME is a pointer
        // look up the symbol in the symbol table
        id_entry = Glookup(id_name);
        if (id_entry == NULL) {
          // entry was not defined
          // error
          printf("Identifier was not declared, exiting...\n");
          exit(0);
        }
        // there can be two cases when this case is reached:
        // 1) when evaluating an expression, such as price * quantity
        // 2) when assigning a value, e.g. price = 500
        // we are assured that at least memory for the variable has been allocated
        // so just return whatever's in the memory and let the caller take care of the rest
        return *(id_entry -> BINDING);
      case PARENS:
        // again, nothing to do, just evaluate its parameter
        return evaluate(t -> Ptr1);
      case READ:
        // do the actual reading
        // find the name of the variable
        id_to_assign = t -> Ptr1;  // this will obviously be an ID
        // its name will be stored in NAME field
        // allocate memory accordingly
        id_name = id_to_assign -> NAME; // [0] because NAME is a pointer
        // look up the symbol in the symbol table
        id_entry = Glookup(id_name);
        if (id_entry == NULL) {
          // entry was not defined
          // error
          printf("Identifier was not declared, exiting...\n");
          exit(0);
        }
        // allocate memory for BINDING field of id_entry
        id_entry -> BINDING = (int *) malloc (sizeof(int));
        scanf("%d", id_entry -> BINDING);
        return -1;
      case WRITE:
        // do the writing
        // find the name of the variable
        id_to_assign = t -> Ptr1;
        // this will obviously be something evaluatable
        // because we can have statements like write(a + b + c);
        value_to_write = evaluate(id_to_assign);
        printf("%d\n", value_to_write);
        return -1;
      case NODETYPE_SLIST:
        //printf("Evaluating first arg...\n");
        evaluate(t->Ptr1);
        //printf("Done valuating first arg in SLIST.\nEvaluating next arg in SLIST...\n");
        //printf("Accessing t -> Ptr2...");
        next_arg = t -> Ptr2;
        //printf("done.\n");
        evaluate(t->Ptr2);
        //printf("Done valuating next arg in SLIST.\n");
        return -1;
      case IF:
        // check if boolean expressione evaluates to true
        truth_value = evaluate(t -> Ptr1);
        if (truth_value) {
          evaluate(t -> Ptr2);
        }
        return -1;
      case WHILE:
        truth_value = evaluate(t -> Ptr1);
        while (truth_value) {
          evaluate(t -> Ptr2);
          truth_value = evaluate(t -> Ptr1);
        }
        return -1;
      default:
        break;
    }
}

struct Gsymbol *Glookup(char *NAME) // Look up for a global identifier
{
    struct Gsymbol *temp = global_symbol_table_start;
    while (temp != NULL) {
      if (strcmp(temp -> NAME, NAME) == 0)
        return temp;
    }
    return temp;
}

void Ginstall(char *NAME, int TYPE, int SIZE, struct ArgStruct *ARGLIST) // Installation
{
  struct Gsymbol *new_entry = (struct Gsymbol *) malloc(sizeof(struct Gsymbol));
  new_entry -> NAME = NAME;
  new_entry -> TYPE = TYPE;
  new_entry -> SIZE = SIZE;
  new_entry -> ARGLIST = ARGLIST;
  new_entry -> NEXT = NULL;

  // allocate space for the new entry
  // since the storage is internally all integers, we just have to allocate space
  // for SIZE integers

  int *int_space = (int *) malloc(sizeof(int) * SIZE);
  new_entry -> BINDING = int_space;

  // update the last entry of the symbol table to point to this new entry
  if (global_symbol_table_end == NULL) {
    // first entry
    global_symbol_table_end = new_entry;
    global_symbol_table_start = new_entry;
  }
  else
    global_symbol_table_end -> NEXT = new_entry;
}
