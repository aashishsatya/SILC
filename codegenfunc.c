// source code for the function to generate intermediate code

#include "expl.c"

int register_to_use = -1;  // this is the next to be allocated
int next_register;  // this will be the variable used internally in the switch staements
int label_counter = 1;  // a concatenation of L and this value will be used for labels
// 1 because 0 and 1 were used to initialize heap values earlier (and we do label_counter++ before we use it)
int no_local_vbls_pushed;

struct Typetable *current_struct_type;

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
  else {
    printf("Error deallocating register; exiting.\n");
    exit(0);
  }
}

// gets the address where the value of a node is to be stored

int get_address(struct Tnode *ptr) {

  int lhs, rhs, ans;
  struct Lsymbol *local_sym_table_ptr;
  struct ArgStruct *function_arg_list = NULL; // to check if the current variable is in the declarations list
  struct Fieldlist *flist;
  int reqd_binding; // this will store the SIM binding value of a variable in the local symbol table or argument list
  int temp;
  struct Gsymbol *symbol_table_ptr;

  switch(ptr -> NODETYPE) {

    case NODETYPE_STRUCT_ELEM_ACCESS:

      // return the value address of the variable
      // we're accessing a structure element
      // get the address of the base structure
      ans = get_address(ptr -> Ptr1);
      // check the type of the variable we're accessing
      flist = current_struct_type -> fields;
      while (flist != NULL) {
        if (strcmp(flist -> name, ptr -> Ptr2 -> NAME) == 0) {
          current_struct_type = flist -> type;
          break;
        }
        flist = flist -> next;
      }
      // we need the address anyway
      // which is nothing but base address + fieldIndex
      temp = allocate_register();
      fprintf(fp, "MOV R%d, [R%d] // get the memory location allocated to the structure variable\n", ans, ans);
      fprintf(fp, "MOV R%d, %d\n", temp, flist -> fieldIndex);
      fprintf(fp, "ADD R%d, R%d\n", ans, temp);
      deallocate_register();  // free temp
      return ans;

    case ID:

      // the value of the ID is needed
      // load it into a register for now and return the register value
      lhs = allocate_register();
      // look up the variable
      local_sym_table_ptr = Llookup(ptr -> Lentry, ptr -> NAME);
      if (local_sym_table_ptr != NULL) {
        reqd_binding = local_sym_table_ptr -> LOCAL_SIM_BINDING;
        current_struct_type = local_sym_table_ptr -> TYPE;
      }
      else {
        // check argument list
        function_arg_list = ArgLookup(ptr -> ArgList, ptr -> NAME);
        if (function_arg_list != NULL) {
          reqd_binding = function_arg_list -> ARG_SIM_BINDING;
          current_struct_type = function_arg_list -> TYPE;
        }
      }
      // please be careful about the order of evaluation of the || (and its
      // breakability on finding an answer thereof)
      if (local_sym_table_ptr != NULL || function_arg_list != NULL) {
        next_register = allocate_register();
        temp = allocate_register();
        fprintf(fp, "MOV R%d, BP\n", next_register);
        fprintf(fp, "MOV R%d, %d\n", temp, reqd_binding);
        fprintf(fp, "ADD R%d, R%d\n", next_register, temp);
        // if the argument is called by reference, then [BP + 2] will contain the address of the
        // location where the result is to be stored
        // the intended code stores the result at [R_next_register]
        // so if we set R_next_register to be [BP + 2] (in case of call by reference) then both cases should work
        if (function_arg_list != NULL && function_arg_list -> PASS_TYPE == PASS_BY_REFERENCE)
          fprintf(fp, "MOV R%d, [R%d]\n", next_register, next_register);
        fprintf(fp, "MOV R%d, R%d\n", lhs, next_register);
        // next_register now contains BP + binding
        deallocate_register();  // free temp
        deallocate_register();  // free next_register
      }
      else {
        symbol_table_ptr = Glookup(ptr -> NAME);
        // TODO: this error check could be moved to the parsing phase
        if (symbol_table_ptr == NULL) {
          printf("Undeclared variable %s, exiting.\n", ptr -> NAME);
          exit(0);
        }
        current_struct_type = symbol_table_ptr -> TYPE;
        if (ptr -> Ptr1 == NULL) {
          // ptr is not the ID for an array
          // so just access the memory location directly stored in its binding
          fprintf(fp, "MOV R%d, %d\n", lhs, symbol_table_ptr -> SIM_BINDING);
        }
        else {
          // whoopsie, ID is an array
          // get and find the index of the required element
          rhs = code_gen(ptr -> Ptr1);
          temp = allocate_register();
          // now we need to add this to the base address of the array
          fprintf(fp, "MOV R%d, %d\n", temp, symbol_table_ptr -> SIM_BINDING);
          fprintf(fp, "ADD R%d, R%d\n", rhs, temp);
          deallocate_register();  // release temp
          // now we have the proper address to read into stored in rhs
          // move the value in the memory location in rhs
          fprintf(fp, "MOV R%d, R%d\n", lhs, rhs);
          deallocate_register();  // free rhs
        }
      }
      return lhs;
      break;
  }
  return -1;
}

int code_gen(struct Tnode *ptr) {

  // note that (most of) these variables absolutely have to be local
  // otherwise recursion will result in overwriting valid values
  // (of variables such as, say lhs)

  int lhs, rhs;
  int temp;
  int ans;  // this is to store the answer of operations like plus etc.
  int local_label_counter;  // because of nestings, we might lose the value of label counter at that particular "level"
  int start_of_loop_counter;  // for the while loops
  int end_of_loop_counter; // hence the need for these variables
  int return_reg;
  int reqd_binding; // this will store the SIM binding value of a variable in the local symbol table or argument list
  int no_registers_in_use;
  int no_of_args_pushed;
  struct Gsymbol *symbol_table_ptr;
  struct Lsymbol *local_sym_table_ptr;
  struct ArgStruct *function_arg_list = NULL; // to check if the current variable is in the declarations list
  struct ArgStruct *list_of_fn_args = NULL; // to traverse through the declarations list to determine if call by value or reference
  struct Tnode *arg_to_evaluate;
  struct Typetable *variable_type;
  struct Fieldlist *flist;

  switch(ptr -> NODETYPE) {
    case PLUS:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "ADD R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case MINUS:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "SUB R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case MUL:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "MUL R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case DIV:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "DIV R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case EQ:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "EQ R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case NEQ:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "NE R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case GT:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "GT R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case LT:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "LT R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case LE:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "LE R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case GE:
      lhs = code_gen(ptr -> Ptr1);
      rhs = code_gen(ptr -> Ptr2);
      fprintf(fp, "GE R%d, R%d\n", lhs, rhs);
      deallocate_register();  // free rhs
      return lhs;
    case NULL_NODE:
      // since ptr -> VALUE would be -1 in the case of NULL, that is exactly what we need
      // hence we can let this fall through
    case NUM:
      // just copy the number to the next available register
      next_register = allocate_register();
      fprintf(fp, "MOV R%d, %d\n", next_register, ptr -> VALUE);
      return next_register;
      break;

    case ASGN:

      // simple question of a move
      // but before that you have to write code for your RHS
      fprintf(fp, "// beginning of assignment operation to %s\n", ptr -> Ptr1 -> NAME);
      rhs = code_gen(ptr -> Ptr2);
      // get the address of the variable to store the value to
      lhs = get_address(ptr -> Ptr1);
      fprintf(fp, "MOV [R%d], R%d\n", lhs, rhs);
      deallocate_register();
      deallocate_register();
      return -1;

    case NODETYPE_ALLOC:

      // get the address of the structure to allocate
      ans = get_address(ptr -> Ptr1);
      temp = allocate_register();
      // find the next free block
      fprintf(fp, "MOV R%d, 1024  // code for alloc begins here\n", temp);
      fprintf(fp, "MOV [R%d], [R%d]\n", ans, temp);
      lhs = allocate_register();
      // update the heap values
      fprintf(fp, "MOV R%d, [R%d]\n", lhs, temp);
      fprintf(fp, "MOV R%d, [R%d]\n", lhs, lhs);
      fprintf(fp, "MOV [R%d], R%d\n", temp, lhs);
      deallocate_register();  // free lhs
      deallocate_register();  // free temp
      deallocate_register();  // free ans
      return -1;

    case NODETYPE_FREE:

      // get the address of the structure to deallocate
      ans = get_address(ptr -> Ptr1);
      temp = allocate_register();
      // OK, the idea here is this
      // 1024 would contain the value of the next free block
      // put this value in the CURRENT block that we're supposed to deallocate
      // set the address of the current block as the value in 1024
      // them step by step:
      fprintf(fp, "MOV R%d, [R%d]\n", ans, ans);
      fprintf(fp, "MOV R%d, 1024  // code for free begins here\n", temp);
      fprintf(fp, "MOV [R%d], [R%d]\n", ans, temp);
      fprintf(fp, "MOV [R%d], R%d\n", temp, ans);
      deallocate_register();  // free temp
      deallocate_register();  // free ans
      return -1;

    case NODETYPE_STRUCT_ELEM_ACCESS:

      // return the value like in ID
      // we're accessing a structure element
      // get the address of the base structure
      ans = get_address(ptr -> Ptr1);
      // check the type of the variable we're accessing
      flist = current_struct_type -> fields;
      while (flist != NULL) {
        if (strcmp(flist -> name, ptr -> Ptr2 -> NAME) == 0) {
          current_struct_type = flist -> type;
          break;
        }
        flist = flist -> next;
      }
      // we need the address anyway
      // which is nothing but base address + fieldIndex
      temp = allocate_register();
      fprintf(fp, "MOV R%d, [R%d] // get the memory location allocated to the structure variable\n", ans, ans);
      fprintf(fp, "MOV R%d, %d\n", temp, flist -> fieldIndex);
      fprintf(fp, "ADD R%d, R%d\n", ans, temp);
      fprintf(fp, "MOV R%d, [R%d]\n", ans, ans);
      // ans now has the required value
      deallocate_register();  // free temp
      return ans;

    case WRITE:

      // evaluate the argument within WRITE
      lhs = code_gen(ptr -> Ptr1);
      fprintf(fp, "OUT R%d\n", lhs);
      deallocate_register();  // give back lhs register
      break;

    case READ:

      lhs = allocate_register();
      fprintf(fp, "IN R%d\n", lhs);
      rhs = get_address(ptr -> Ptr1);
      fprintf(fp, "MOV [R%d], R%d\n", rhs, lhs);
      deallocate_register();
      deallocate_register();
      return -1;

    case ID:
      // the value of the ID is needed
      // load it into a register for now and return the register value
      lhs = allocate_register();
      local_sym_table_ptr = Llookup(ptr -> Lentry, ptr -> NAME);
      if (local_sym_table_ptr != NULL) {
        reqd_binding = local_sym_table_ptr -> LOCAL_SIM_BINDING;
      }
      else {
        // check argument list
        function_arg_list = ArgLookup(ptr -> ArgList, ptr -> NAME);
        if (function_arg_list != NULL) {
          reqd_binding = function_arg_list -> ARG_SIM_BINDING;
        }
      }
      // please be careful about the order of evaluation of the || (and its
      // breakability on finding an answer thereof)
      if (local_sym_table_ptr != NULL || function_arg_list != NULL) {
        next_register = allocate_register();
        temp = allocate_register();
        fprintf(fp, "MOV R%d, BP\n", next_register);
        fprintf(fp, "MOV R%d, %d\n", temp, reqd_binding);
        fprintf(fp, "ADD R%d, R%d\n", next_register, temp);
        // if the argument is called by reference, then [BP + 2] will contain the address of the
        // location where the result is to be stored
        // the intended code stores the result at [R_next_register]
        // so if we set R_next_register to be [BP + 2] (in case of call by reference) then both cases should work
        if (function_arg_list != NULL && function_arg_list -> PASS_TYPE == PASS_BY_REFERENCE)
          fprintf(fp, "MOV R%d, [R%d]\n", next_register, next_register);
        fprintf(fp, "MOV R%d, [R%d]\n", lhs, next_register);
        // next_register now contains BP + binding
        deallocate_register();  // free temp
        deallocate_register();  // free next_register
      }
      else {
        symbol_table_ptr = Glookup(ptr -> NAME);
        if (ptr -> Ptr1 == NULL) {
          // ptr is not the ID for an array
          // so just access the memory location directly stored in its binding
          fprintf(fp, "MOV R%d, [%d]\n", lhs, symbol_table_ptr -> SIM_BINDING);
        }
        else {
          // whoopsie, ID is an array
          // get and find the index of the required element
          rhs = code_gen(ptr -> Ptr1);
          temp = allocate_register();
          // now we need to add this to the base address of the array
          fprintf(fp, "MOV R%d, %d\n", temp, symbol_table_ptr -> SIM_BINDING);
          fprintf(fp, "ADD R%d, R%d\n", rhs, temp);
          deallocate_register();  // release temp
          // now we have the proper address to read into stored in rhs
          // move the value in the memory location in rhs
          fprintf(fp, "MOV R%d, [R%d]\n", lhs, rhs);
          deallocate_register();  // free rhs
        }
      }
      return lhs;
      break;
    case PARENS:
      // nothing to do, just evaluate what's inside the parens
      lhs = code_gen(ptr -> Ptr1);
      return lhs;
    case NODETYPE_SLIST:
      code_gen(ptr -> Ptr1);
      code_gen(ptr -> Ptr2);
      return -1;
    case NODETYPE_FUNCTION_CALL:
      fprintf(fp, "// setting up stack before call to %s\n", ptr -> NAME);
      // push registers
      no_registers_in_use = register_to_use;
      no_of_args_pushed = 0;
      temp = 0;
      fprintf(fp, "// pushing registers in use\n");
      while (temp <= no_registers_in_use) {
        fprintf(fp, "PUSH R%d\n", temp);
        temp++;
      }
      // push arguments of the function call
      // before we push the argument we need to evaluate it
      fprintf(fp, "// pushing arguments to function calls\n");
      arg_to_evaluate = ptr -> Ptr1;
      symbol_table_ptr = Glookup(ptr -> NAME);
      list_of_fn_args = symbol_table_ptr -> ARGLIST;  // this is needed to check if the arguments are called by value or reference
      list_of_fn_args = symbol_table_ptr -> ARGLIST;  // this is needed to check if the arguments are called by value or reference
      while (arg_to_evaluate != NULL) {
        if (arg_to_evaluate -> Ptr2 != NULL) {
          if (list_of_fn_args -> PASS_TYPE == PASS_BY_VALUE) {
            temp = code_gen(arg_to_evaluate -> Ptr2); // this '... -> Ptr2' is an expr
            fprintf(fp, "PUSH R%d\n", temp);
            no_of_args_pushed++;
            // free R_temp
            deallocate_register();
          }
          else {
            temp = get_address(arg_to_evaluate -> Ptr2); // this '... -> Ptr2' is an expr
            fprintf(fp, "PUSH R%d\n", temp);
            no_of_args_pushed++;
            // free R_temp
            deallocate_register();
          }
        }
        arg_to_evaluate = arg_to_evaluate -> Ptr1;
        if (list_of_fn_args != NULL)
          list_of_fn_args = list_of_fn_args -> NEXT;
      }
      // reserve space for return value
      temp = allocate_register();
      fprintf(fp, "// pushing space for return value\n");
      fprintf(fp, "PUSH R%d\n", temp);
      deallocate_register();
      // CALL!!
      fprintf(fp, "CALL %s\n", ptr -> NAME);
      // obtain the return value
      return_reg = allocate_register();
      fprintf(fp, "POP R%d\n", return_reg);
      // pop the arguments
      if (no_of_args_pushed > 0) {
          lhs = allocate_register();
          rhs = allocate_register();
          fprintf(fp, "// popping arguments off the stack\n");
          fprintf(fp, "MOV R%d, SP\n", lhs);
          fprintf(fp, "MOV R%d, %d\n", rhs, no_of_args_pushed);
          fprintf(fp, "SUB R%d, R%d\n", lhs, rhs);
          fprintf(fp, "MOV SP, R%d\n", lhs);
          deallocate_register();  // free rhs
          deallocate_register();  // free lhs
      }
      // restore registers
      temp = no_registers_in_use;
      while (temp > -1) {
        fprintf(fp, "POP R%d\n", temp);
        temp = temp - 1;
      }
      return return_reg;
      break;
    case NODETYPE_FUNCTION_DEFINITION:
      no_local_vbls_pushed = 0;
      fprintf(fp, "%s:\n", ptr -> NAME);
      fprintf(fp, "PUSH BP\n");
      fprintf(fp, "MOV BP, SP\n");
      // push the local variables
      fprintf(fp, "// push registers for local variables\n");
      symbol_table_ptr = Glookup(ptr -> NAME);
      local_sym_table_ptr = symbol_table_ptr -> local_sym_table;
      temp = allocate_register();
      while (local_sym_table_ptr != NULL) {
        fprintf(fp, "PUSH R%d // space for %s\n", temp, local_sym_table_ptr -> NAME);
        local_sym_table_ptr = local_sym_table_ptr -> NEXT;
        no_local_vbls_pushed++;
      }
      deallocate_register();  // deallocate temp
      // generate code for statements
      code_gen(ptr -> Ptr1);  // this will also include the return statement
      return -1;  // irrelevant
    case NODETYPE_RETURN_STMT:
      // just evaluate the expr to be returned
      ans = code_gen(ptr -> Ptr1);
      lhs = allocate_register();
      rhs = allocate_register();
      fprintf(fp, "MOV R%d, BP\n", lhs);
      fprintf(fp, "MOV R%d, 2\n", rhs);
      fprintf(fp, "SUB R%d, R%d\n", lhs, rhs);  // R_lhs contains BP - 2 now
      fprintf(fp, "MOV [R%d], R%d\n", lhs, ans);
      deallocate_register();  // free ans
      // clear the stack contents
      fprintf(fp, "// deallocate space given to local variables\n");
      fprintf(fp, "MOV R%d, SP\n", lhs);
      //printf("no_local_vbls_pushed = %d\n", no_local_vbls_pushed);
      fprintf(fp, "MOV R%d, %d\n", rhs, no_local_vbls_pushed);
      fprintf(fp, "SUB R%d, R%d\n", lhs, rhs);  // R_lhs now contains the number of local variables pushed
      fprintf(fp, "MOV SP, R%d\n", lhs);
      deallocate_register();  // free rhs
      deallocate_register();  // free lhs
      // set the base pointer back
      fprintf(fp, "POP BP\n");
      // RETURN!!
      fprintf(fp, "RET\n");
      return -1;
    case IF:
      // evaluate condition
      fprintf(fp, "// code for if begins here\n");
      lhs = code_gen(ptr -> Ptr1);
      // if condition is false jump to remaining instructions
      label_counter++;
      local_label_counter = label_counter;
      fprintf(fp, "JZ R%d, L%d\n", lhs, local_label_counter);
      // print out instrutions to be executed on condition being true
      code_gen(ptr -> Ptr2);
      fprintf(fp, "L%d:       // code for if ends\n", local_label_counter);
      deallocate_register();  // free lhs
      return -1;
    case WHILE:
      // ah the most complex of them all
      // while is basically
      // label1
      // check condition
      // statements if condition is valid
      // jump back to label1
      // label 2
      // so let's get on with it
      label_counter++;
      start_of_loop_counter = label_counter;
      fprintf(fp, "L%d:\n", start_of_loop_counter);
      lhs = code_gen(ptr -> Ptr1);
      label_counter++;
      end_of_loop_counter = label_counter;
      fprintf(fp, "JZ R%d, L%d\n", lhs, end_of_loop_counter);
      deallocate_register();  // free lhs
      code_gen(ptr -> Ptr2);
      fprintf(fp, "JMP L%d\n", start_of_loop_counter);
      fprintf(fp, "L%d:\n", end_of_loop_counter);
      return -1;
  }
  return 0;
}

struct ArgStruct *ArgInstall(struct ArgStruct *current_arg_list, struct Typetable *variable_type, char *NAME, int PASS_TYPE) {
	// append ID to the beginning of the argument list

	struct ArgStruct *new_arg_list = (struct ArgStruct *) malloc(sizeof(struct ArgStruct));
	new_arg_list -> TYPE = variable_type;
	new_arg_list -> NAME = NAME;
	new_arg_list -> NEXT = current_arg_list;
	new_arg_list -> BINDING = (int *) malloc(sizeof(int));
	new_arg_list -> ARG_SIM_BINDING = current_arg_binding * -1;	// multiplication with -1 is used to facilitate addition with BP
	// (arguments will be stored as BP - 1, BP - 2 etc)
	new_arg_list -> PASS_TYPE = PASS_TYPE;
	current_arg_binding++;
	return new_arg_list;
}
