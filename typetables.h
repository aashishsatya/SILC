// header file to store all the structures and declarations of functions dealing with type declarations

struct Typetable {
    char *name;                 //type name
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
};

struct Fieldlist {
  char *name;              //name of the field
  int fieldIndex;          //the position of the field in the field list
  struct Typetable *type;  //pointer to type table entry of the field's type
  struct Fieldlist *next;  //pointer to the next field
};

void TypeTableCreate();

struct Typetable *Tlookup (char *name);

struct Typetable *Tinstall (char *name, struct Fieldlist *fields);

struct Fieldlist *FLookup(struct Typetable *type, char *name);

void add_id_to_current_flist(char *name);
