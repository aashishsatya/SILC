// source code for the function to generate intermediate code

#include "expl.c"

int register_to_use = -1;  // this is the next to be allocated
int next_register;  // this will be the variable used internally in the switch staements
int label_counter = -1;  // a concatenation of L and this value will be used for labels
int no_local_vbls_pushed;

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

  // note that these variables absolutely have to be local
  // otherwise recursion will result in overwriting valid values
  // (of variables such as, say lhs)

  int lhs, rhs; // name should be enough
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
  struct ArgStruct *function_arg_list = NULL;
  struct Tnode *arg_to_evaluate;

  if (ptr == NULL) {
    printf("Warning: ptr is NULL!!\n");
  }

  //printf("In code_gen...\n");
  //printf("ptr -> TYPE = %d\n", ptr -> TYPE);
  //printf("ASGN = %d\n", ASGN);
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
    case NUM:
      // just copy the number to the next available register
      next_register = allocate_register();
      fprintf(fp, "MOV R%d, %d\n", next_register, ptr -> VALUE);
      return next_register;
      break;
    case ASGN:
      printf("In ASGN...\n");
      // simple question of a move
      // but before that you have to write code for your RHS
      fprintf(fp, "// beginning of assignment operation to %s\n", ptr -> Ptr1 -> NAME);
      rhs = code_gen(ptr -> Ptr2);
      // now, the LHS would already have a memory location alloted to it
      // during installation of the variables
      // just move the value in RHS to the memory location
      // but we need to get the binding first
      // check local symbol table
      local_sym_table_ptr = Llookup(ptr -> Lentry, ptr -> Ptr1 -> NAME);
      if (local_sym_table_ptr != NULL) {
        reqd_binding = local_sym_table_ptr -> LOCAL_SIM_BINDING;
      }
      else {
        // check argument list
        function_arg_list = ArgLookup(ptr -> ArgList, ptr -> Ptr1 -> NAME);
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
        if (function_arg_list != NULL)
          if (function_arg_list -> PASS_TYPE == PASS_BY_REFERENCE)
            fprintf(fp, "MOV R%d, [R%d]\n", next_register, next_register);
        fprintf(fp, "MOV [R%d], R%d\n", next_register, rhs);
        // next_register now contains BP + binding
        deallocate_register();  // free temp
        deallocate_register();  // free next_register
      }
      else {
        // check global symbol table
        symbol_table_ptr = Glookup(ptr -> Ptr1 -> NAME);
        if (symbol_table_ptr != NULL) {
          // check if LHS is an array now
          if (ptr -> Ptr1 -> Ptr1 != NULL)  {
            // issue instructions for the same
            // we can't reuse ID for LHS because we need to know the value of the memory location
            ans = code_gen(ptr -> Ptr1 -> Ptr1);  // generate code for index
            // ans has the register number corresponding to the index
            // calculate the base address of the location to store
            next_register = allocate_register();
            fprintf(fp, "MOV R%d, %d\n", next_register, symbol_table_ptr -> SIM_BINDING); // load the base address
            fprintf(fp, "ADD R%d, R%d\n", next_register, ans);  // add it to the index
            // write the value to the array
            fprintf(fp, "MOV [R%d], R%d\n", next_register, rhs);
            deallocate_register();  // deallocate next_register
            deallocate_register();  // deallocate storage location of index (ans)
          }
          else {
            // just variable assignment is needed
            fprintf(fp, "MOV [%d], R%d\n", symbol_table_ptr -> SIM_BINDING, rhs);
          }
        }
      }
      deallocate_register();  // deallocate rhs
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
      // check local symbol table
      if (ptr -> Lentry == NULL) {
        printf("Lentry is NULL.\n");
      }
      local_sym_table_ptr = Llookup(ptr -> Lentry, ptr -> Ptr1 -> NAME);
      if (local_sym_table_ptr != NULL) {
        reqd_binding = local_sym_table_ptr -> LOCAL_SIM_BINDING;
      }
      else {
        // check argument list
        function_arg_list = ArgLookup(ptr -> ArgList, ptr -> Ptr1 -> NAME);
        if (function_arg_list != NULL) {
          printf("Required binding = %d\n", function_arg_list -> ARG_SIM_BINDING);
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
        //printf("Name of the argument = %s\n", function_arg_list -> NAME);
        if (function_arg_list != NULL && function_arg_list -> PASS_TYPE == PASS_BY_REFERENCE)
          fprintf(fp, "MOV R%d, [R%d]\n", next_register, next_register);
        fprintf(fp, "MOV [R%d], R%d\n", next_register, lhs);
        // next_register now contains BP + binding
        deallocate_register();  // free temp
        deallocate_register();  // free next_register
      }
      else {
        // check global symbol table
        symbol_table_ptr = Glookup(ptr -> Ptr1 -> NAME);
        if (symbol_table_ptr == NULL) {
          printf("symbol_table_ptr is NULL, was looking for %s.\n", ptr -> Ptr1 -> NAME);
        }
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
          //printf("name = %s\n", ptr -> Ptr1 -> NAME);
          //printf("binding = %d\n", symbol_table_ptr -> SIM_BINDING);
          fprintf(fp, "MOV R%d, %d\n", temp, symbol_table_ptr -> SIM_BINDING);
          fprintf(fp, "ADD R%d, R%d\n", rhs, temp);
          deallocate_register();  // release temp
          // now we have the proper address to read into stored in rhs
          // move the value in R_lhs to the memory address in rhs
          fprintf(fp, "MOV [R%d], R%d\n", rhs, lhs);
          deallocate_register();  // release rhs
        }
      }
      deallocate_register();  // release lhs
      break;
    case ID:
      // the value of the ID is needed
      // load it into a register for now and return the register value
      lhs = allocate_register();
      printf("In ID...\n");
      // look up the variable
      printf("Looking up %s\n", ptr -> NAME);
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
      //printf("Evaluating first arg...\n");
      code_gen(ptr -> Ptr1);
      //printf("Done valuating first arg in SLIST.\nEvaluating next arg in SLIST...\n");
      //printf("Accessing t -> Ptr2...");
      //printf("done.\n");
      code_gen(ptr -> Ptr2);
      printf("Done valuating next arg in SLIST.\n");
      return -1;
    case NODETYPE_FUNCTION_CALL:
      printf("In function call...\n");
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
      function_arg_list = symbol_table_ptr -> ARGLIST;  // this is needed to check if the arguments are called by value or reference
      while (arg_to_evaluate != NULL) {
        if (arg_to_evaluate -> Ptr2 != NULL) {
          if (function_arg_list -> PASS_TYPE == PASS_BY_VALUE) {
            temp = code_gen(arg_to_evaluate -> Ptr2); // this '... -> Ptr2' is an expr
            fprintf(fp, "PUSH R%d\n", temp);
            no_of_args_pushed++;
            // free R_temp
            deallocate_register();
          }
          else {
            // if it's pass by reference it'll just be an ID
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
              // just push BP + reqd_binding to the stack
              lhs = allocate_register();
              rhs = allocate_register();
              fprintf(fp, "MOV R%d, BP\n", lhs);
              fprintf(fp, "MOV R%d, %d\n", rhs, reqd_binding);
              fprintf(fp, "ADD R%d, R%d\n", lhs, rhs);  // R_lhs now contains BP + reqd_binding (which is to be pushed)
              fprintf(fp, "PUSH R%d\n", lhs);
              deallocate_register();  // free lhs
              deallocate_register();  // free rhs
            }
            else {
              symbol_table_ptr = Glookup(ptr -> NAME);
              if (ptr -> Ptr1 == NULL) {
                // ptr is not the ID for an array
                // the binding required is symbol_table_ptr -> SIM_BINDING
                // so just push it to stack
                lhs = allocate_register();
                fprintf(fp, "MOV R%d, %d\n", lhs, symbol_table_ptr -> SIM_BINDING);
                fprintf(fp, "PUSH R%d\n", lhs);
                deallocate_register();
              }
          }
        }
        arg_to_evaluate = arg_to_evaluate -> Ptr1;
        function_arg_list = function_arg_list -> NEXT;
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
      printf("Dealing with function definition %s\n", ptr -> NAME);
      fprintf(fp, "%s:\n", ptr -> NAME);
      printf("...done dealing.\n");
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
      printf("no_local_vbls_pushed = %d\n", no_local_vbls_pushed);
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
      lhs = code_gen(ptr -> Ptr1);
      // if condition is false jump to remaining instructions
      label_counter++;
      local_label_counter = label_counter;
      fprintf(fp, "JZ R%d, L%d\n", lhs, local_label_counter);
      // print out instrutions to be executed on condition being true
      printf("Generating instructions for IF true condn...\n");
      code_gen(ptr -> Ptr2);
      // print out the label to resume execution otherwise
      printf("...done.\n");
      fprintf(fp, "L%d:\n", local_label_counter);
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

struct ArgStruct *ArgInstall(struct ArgStruct *current_arg_list, int variable_type, char *NAME, int PASS_TYPE) {
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

// generates code for a particular function and writes it towards the beginning of the intermediate code file
int code_gen_function(struct Tnode *ptr, char *NAME) {
  return 0;
}
