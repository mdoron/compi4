#ifndef __ATTRIBUTES_H
#define __ATTRIBUTES_H


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

#define YYSTYPE STYPE	// Tell Bison to use STYPE as the stack type

#endif