#ifndef __ATTRIBUTES_H
#define __ATTRIBUTES_H

#include <list>
#include <string>
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
  string name;
} STYPE;

typedef struct row_t {
	type_t type;
	list<type_t>* params;
	string name;
	int* offset; 
	
	row_t(type_t type, string name, int* offset) {
		this->type = type;
		this->params = new list<type_t>();
		this->name = name;
		if (offset == NULL) {
			this->offset = NULL;
		} else {
			this->offset = new int();
			*(this->offset) = *offset;
		}
	} 
	
	void setParams(list<type_t>* l) {
		for (list<type_t>::iterator it = l->begin(); it != l->end(); ++it)
			params->push_back((*it));
		this->offset = NULL;
	}

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