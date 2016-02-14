struct Tnode {

  int TYPE; // Integer, Boolean or Void (for statements)

  /* Points to the type expression tree for user defined types */

  int NODETYPE;

  /* this field should carry following information:

  * a) operator : (+,*,/ etc.) for expressions

  * b) statement Type : (WHILE, READ etc.) for statements */

  char* NAME; // For Identifiers/Functions

  int VALUE; // for constants

  struct Tnode *ArgList; // List of arguments for functions

  struct Tnode *Ptr1, *Ptr2, *Ptr3;

  /* Maximum of three subtrees (3 required for IF THEN ELSE) */

  //Gsymbol *Gentry; // For global identifiers/functions

  //Lsymbol *Lentry; // For Local variables

};

struct Tnode *TreeCreate(int TYPE, int NODETYPE, int VALUE, char *NAME, struct Tnode *ArgList, struct Tnode *Ptr1, struct Tnode *Ptr2, struct Tnode *Ptr3);

/*Make a leaf Tnode and set the value of val field*/
struct Tnode* makeLeafNode(int n);

/*Make a Tnode with opertor, left and right branches set*/
struct Tnode* makeOperatorNode(int c, struct Tnode *l,struct Tnode *r);

/*To evaluate an expression tree*/
int evaluate(struct Tnode *t);
