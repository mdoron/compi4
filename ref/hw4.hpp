#ifndef _HW4_HPP
#define _HW4_HPP

#include <string>
using namespace std;

typedef enum {
	INT_TYPE,
	BOOL_TYPE,
	SECOND_TYPE,
	MINUTE_TYPE,
	HOUR_TYPE,
	DAY_TYPE,
	WEEK_TYPE,
} type_t;

typedef struct {
	string name;
	unsigned int offset;
	type_t type;
	unsigned int declerationIndex;
} yystype;

#define YYSTYPE yystype


#endif
