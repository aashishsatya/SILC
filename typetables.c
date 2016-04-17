#include "typetables.h"

struct Typetable *ttable; // this is the current type table that is
struct Typetable *temp_ttable;
struct Fieldlist *current_flist;
struct Fieldlist *temp_flist;

struct Typetable *VAR_TYPE_INT = NULL;
struct Typetable *VAR_TYPE_BOOL = NULL;
struct Typetable *VAR_TYPE_VOID = NULL;

void TypeTableCreate() {
  //char *decln_name = (char *) malloc (sizeof(30));

  // add "boolean" as a type

  ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
  ttable -> name = (char *) malloc(sizeof(char) * 30);
  strcpy(ttable -> name, "boolean");
  ttable -> fields = NULL;
  ttable -> next = NULL;
  VAR_TYPE_BOOL = ttable;

  // add integer as type

  struct Typetable *new_ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
  new_ttable -> name = (char *) malloc(sizeof(char) * 30);
  strcpy(new_ttable -> name, "integer");
  new_ttable -> fields = NULL;
  new_ttable -> next = ttable;
  ttable = new_ttable;
  VAR_TYPE_INT = ttable;
}

// search through the type table and return pointer to type table entry of type 'name'.
// Returns NULL if entry is not found.

struct Typetable *Tlookup (char *name) {
  temp_ttable = ttable;
  while (temp_ttable != NULL) {
    if (strcmp(temp_ttable -> name, name) == 0) {
      return temp_ttable;
    }
    temp_ttable = temp_ttable -> next;
  }
  return NULL;
}

struct Typetable *Tinstall (char *name, struct Fieldlist *fields) {
   temp_ttable = (struct Typetable *) malloc(sizeof(struct Typetable));
   strcpy(temp_ttable -> name, name);
   temp_ttable -> fields = fields;
   temp_ttable -> next = ttable;
   ttable = temp_ttable;
}

struct Fieldlist *FLookup(struct Typetable *type, char *name) {
  struct Fieldlist *reqd_fieldlist = type -> fields;
  while (reqd_fieldlist != NULL) {
    if (strcmp(reqd_fieldlist -> name, name)  == 0) {
      return reqd_fieldlist;
    }
    reqd_fieldlist = reqd_fieldlist -> next;
  }
  return NULL;
}

struct Fieldlist *Finstall(char *name) {

  // this will install a field of type 'type' with name 'name' :-P to the current_flist
  struct Fieldlist *new_flist = (struct Fieldlist *) malloc(sizeof(struct Fieldlist));
  strcpy(new_flist -> name, name);

  if (current_flist == NULL) {
    new_flist -> next = NULL;
    new_flist -> fieldIndex = 0;
  }
  else {
    new_flist -> next = current_flist;
    new_flist -> fieldIndex = current_flist -> fieldIndex + 1;
  }
  current_flist = new_flist;
  return new_flist;
}
