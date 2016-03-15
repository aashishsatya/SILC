// source code for the function to generate intermediate code

#include "expl.c"

int register_to_use = -1;  // this is the next to be allocated
int next_register;  // this will be the variable used internally in the switch staements
int lhs, rhs; // name should be enough
int temp;
struct Gsymbol *symbol_table_ptr;
struct Tnode *id_to_assign;

int allocate_register() {
  if (register_to_use < 7) {
    register_to_use++;
    return register_to_use;
  }
  printf("Not enough registers to allocate; exiting.\n");
  exit(0);
}

void deallocate_register() {
  if (register_to_use > -1)
    register_to_use--;
  else
    printf("Error deallocating register; exiting.\n");
}

int code_gen(struct Tnode *ptr) {
  //printf("In code_gen...\n");
  //printf("ptr -> TYPE = %d\n", ptr -> TYPE);
  //printf("ASGN = %d\n", ASGN);
  switch(ptr -> NODETYPE) {
    case NUM:
      // just copy the number to the next available register
      next_register = allocate_register();
      fprintf(fp, "MOV R%d, %d\n", next_register, ptr -> VALUE);
      return next_register;
      break;
    case ASGN:
      //printf("In ASGN...\n");
      // simple question of a move
      // but before that you have to write code for your LHS
      rhs = code_gen(ptr -> Ptr2);
      // now, the LHS would already have a memory location alloted to it
      // during installation of the variables
      // just move the value in RHS to the memory location
      // but we need to get the binding first
      symbol_table_ptr = Glookup(ptr -> Ptr1 -> NAME);
      fprintf(fp, "MOV [%d], R%d\n", symbol_table_ptr -> SIM_BINDING, rhs);
      deallocate_register();
      break;
    case WRITE:
      // evaluate the argument within WRITE
      //printf("In WRITE...\n");
      lhs = code_gen(ptr -> Ptr1);
      fprintf(fp, "OUT R%d\n", lhs);
      deallocate_register();  // give back lhs register
      break;
    case READ:
      lhs = allocate_register();
      fprintf(fp, "IN R%d\n", lhs);
      symbol_table_ptr = Glookup(ptr -> Ptr1 -> NAME);
      // check if it's an array and generate code for the same
      if (ptr -> Ptr1 -> Ptr1 == NULL) {
        // not an array
        fprintf(fp, "MOV [%d], R%d\n", symbol_table_ptr -> SIM_BINDING, lhs);
      }
      else {
        // we have with us an array
        // so generate code for the array index first
        rhs = code_gen(ptr -> Ptr1 -> Ptr1);  // index of the required ID
        // rhs now contains the register containing the index of the required array
        // rhs + base address of variable ID will give you the location to store the incoming number
        // bring in the base address into memory
        temp = allocate_register();
        fprintf(fp, "MOV R%d, %d\n", temp, symbol_table_ptr -> SIM_BINDING);
        fprintf(fp, "ADD R%d, %d\n", rhs, temp);
        deallocate_register();  // release temp
        // now we have the proper address to read into stored in rhs
        // move the value in R_lhs to the memory address in rhs
        fprintf(fp, "MOV [%d], %d\n", rhs, lhs);
      }
      deallocate_register();  // release lhs
      break;
    case ID:
      // the value of the ID is needed
      // load it into a register for now and return the register value
      lhs = allocate_register();
      // look up the variable
      symbol_table_ptr = Glookup(ptr -> NAME);
      fprintf(fp, "MOV R%d, [%d]\n", lhs, symbol_table_ptr -> SIM_BINDING);
      return lhs;
      break;
    case NODETYPE_SLIST:
      //printf("Evaluating first arg...\n");
      code_gen(ptr -> Ptr1);
      //printf("Done valuating first arg in SLIST.\nEvaluating next arg in SLIST...\n");
      //printf("Accessing t -> Ptr2...");
      //printf("done.\n");
      code_gen(ptr -> Ptr2);
      //printf("Done valuating next arg in SLIST.\n");
      return -1;
  }
}
