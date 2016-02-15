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

int evaluate(struct Tnode *t){
    printf("Starting evaluate...\n");
    struct Tnode *id_to_assign = NULL;  // in case we need to get the name of the variable to work on
    struct Tnode *next_arg;
    char id_name; // this variable will store the name of the ID obtained from id_to_assign
    if (t == NULL) {
      printf("t is NULL\n");
      int t_nodetype = t -> NODETYPE;
      printf("t->NODETYPE = %d\n", t_nodetype);
    }
    switch (t -> NODETYPE) {
      case PLUS:
        return evaluate(t -> Ptr1) + evaluate(t -> Ptr2);
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
        id_name = (id_to_assign -> NAME)[0]; // [0] because NAME is a pointer
        printf("ID name to assign: %c\n", id_name);
        if (var[id_name - 'a'] == NULL) {
          printf("Allocating space for storing variable...");
          var[id_name - 'a'] = (int *) malloc (sizeof(int));
          printf("done.\n");
        }
        printf("Malloc successful...\n");
        //printf("Value to set = %d\n", evaluate(t -> Ptr2));
        *var[id_name - 'a'] = evaluate(t -> Ptr2);
        // just return something, doesn't matter what it is
        // point is, C can return any value, you just have to make sure that *SILC* doesn't.
        printf("Returning from ASGN...\n");
        return -1;
      case ID:
        printf("In case ID...\n");
        // in this case, we have to check if ID has been assigned a value
        // if not its an error
        // the only other case has been handled earlier
        //id_to_assign = t -> Ptr1;  // this will obviously be an ID
        // its name will be stored in NAME field
        // allocate memory accordingly
        //printf("Trying to get the ID name...\n");
        //printf("id_to_assign = %p\n", id_to_assign);
        /*if (id_to_assign == NULL) {
          printf("Warning: id_to_assign is NULL.\n");
        }
        if (id_to_assign -> NAME == NULL) {
          printf("Warning: id_to_assign -> NAME is NULL.\n");
        }*/
        printf("Trying to assign_name...\n");
        id_name = (t -> NAME)[0]; // [0] because NAME is a pointer
        printf("done.\n");
        printf("Dealing with ID %c...", id_name);
        if (var[id_name - 'a'] == NULL) {
          var[id_name - 'a'] = (int *) malloc (sizeof(int));
          return -1;
        }
        else {
          return *var[id_name - 'a'];
        }
        printf("done.\n");
      case PARENS:
        // again, nothing to do, just evaluate its parameter
        return evaluate(t -> Ptr1);
      case READ:
        printf("Inside READ...\n");
        // do the actual reading
        // find the name of the variable
        id_to_assign = t -> Ptr1;  // this will obviously be an ID
        // its name will be stored in NAME field
        // allocate memory accordingly
        id_name = (id_to_assign -> NAME)[0]; // [0] because NAME is a pointer
        if (var[id_name - 'a'] == NULL) {
          var[id_name - 'a'] = (int *) malloc (sizeof(int));
        }
        scanf("%d", var[id_name - 'a']);
        printf("...done reading.\n");
        return -1;
      case WRITE:
        printf("Inside WRITE, working...\n");
        // do the writing
        // find the name of the variable
        id_to_assign = t -> Ptr1;  // this will obviously be an ID
        // its name will be stored in NAME field
        id_name = (id_to_assign -> NAME)[0]; // [0] because NAME is a pointer
        printf("\n%d\n\n", *var[id_name - 'a']);
        return -1;
      case NODETYPE_SLIST:
        printf("Evaluating first arg...\n");
        evaluate(t->Ptr1);
        printf("Done valuating first arg in SLIST.\nEvaluating next arg in SLIST...\n");
        printf("Accessing t -> Ptr2...");
        next_arg = t -> Ptr2;
        printf("done.\n");
        evaluate(t->Ptr2);
        printf("Done valuating next arg in SLIST.\n");
        return -1;
      default:
        printf("Inside DEFAULT\n");
        break;
    }
}
