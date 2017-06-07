#ifndef __ATTRIBUTES_H
#define __ATTRIBUTES_H

#include <list>
using namespace std;

typedef enum {
  TYPE_NON,
  TYPE_BOOL,
  TYPE_INT,
  TYPE_BYTE,
  TYPE_STRING,
  TYPE_VOID
} type_t; 

typedef struct {
  type_t type;  
  char* name;
} STYPE;

typedef struct row_t {
	char* name;
	type_t type;
	int offset; 
	
	~row_t(){}
} Row;

typedef struct table_t {
	list<Row*>* rows;
	struct table_t* parent;
	
	table_t() {
		this->rows=new list<Row*>();
		this->parent=NULL;
	}

	/*~table_t(){
		list<Row*> it = rows.begin();
		for(;it!=NULL;it=it->next)
	}*/
} Table;

#define YYSTYPE STYPE	// Tell Bison to use STYPE as the stack type

#endif