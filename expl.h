// these have also been reused for statement types

#define VAR_TYPE_BOOL 0
#define VAR_TYPE_BOOL_ARR 1
#define VAR_TYPE_INT 2
#define VAR_TYPE_INT_ARR 3
#define VAR_TYPE_VOID 4

#define NODETYPE_SLIST 5
#define FUNCTION_ENTRY 6

#include <string.h>

struct Tnode {

  int TYPE; // Integer, Boolean or Void (for statements)
  /* Points to the type expression tree for user defined types */
  int NODETYPE;
  /* this field should carry following information:
  * a) operator : (+,*,/ etc.) for expressions
  * b) statement Type : (WHILE, READ etc.) for statements */
  char* NAME; // For Identifiers/Functions
  int VALUE; // for constants
  struct ArgStruct *ArgList; // List of arguments for functions
  struct Tnode *Ptr1, *Ptr2, *Ptr3;
  /* Maximum of three subtrees (3 required for IF THEN ELSE) */
  struct Gsymbol *Gentry; // For global identifiers/functions
  struct Lsymbol *Lentry; // For Local variables
};

// structure for storing details about function argument

struct ArgStruct {
    char *NAME; // name of the argument
    int TYPE; // type of the argument
    int *BINDING; // memory location where the argument is stored
    struct ArgStruct *NEXT;
};

/** Symbol Table Entry is required for variables, arrays and functions**/

struct Gsymbol {
  char *NAME; // Name of the Identifier
  int TYPE; // TYPE can be INTEGER or BOOLEAN
  /***The TYPE field must be a TypeStruct if user defined types are allowed***/
  int SIZE; // Size field for arrays
  int *BINDING; // Address of the Identifier in Memory
  int SIM_BINDING;  // address of an identifier in SIM memory
  struct ArgStruct *ARGLIST; // Argument List for functions
  /***Argstruct must store the name and type of each argument ***/
  struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */
};

struct Gsymbol *Glookup(char *NAME); // Look up for a global identifier

void Ginstall(char *NAME, int TYPE, int SIZE, struct ArgStruct *ARGLIST); // Installation

struct Lsymbol {
/* Here only name, type, binding and pointer to next entry needed */
  char *NAME;
  int TYPE;
  int *BINDING;
  struct Lsymbol *NEXT;
};

struct Lsymbol *Llookup(struct Lsymbol *local_symbol_table, char *NAME);

void Linstall(struct Lsymbol *current_local_symbol_table, char *NAME, int TYPE);

struct Tnode *TreeCreate(int TYPE, int NODETYPE, int VALUE, char *NAME, struct ArgStruct *ArgList, struct Tnode *Ptr1, struct Tnode *Ptr2, struct Tnode *Ptr3);

/*Make a leaf Tnode and set the value of val field*/
struct Tnode* makeLeafNode(int n);

/*Make a Tnode with opertor, left and right branches set*/
struct Tnode* makeOperatorNode(int OPERATOR, struct Tnode *l, struct Tnode *r);

/*To evaluate an expression tree*/
int evaluate(struct Tnode *t);
