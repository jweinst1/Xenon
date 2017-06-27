#ifndef XENON_OBJECT_H
#define XENON_OBJECT_H

#include "allocator.h"



//used for casting
typedef unsigned XenonType;


//generic holder struct for raw void* data
typedef struct {
    XenonType type;
    void* data;
} XenonObject;

//frees memory and turns object to null
void obj_del(XenonObject* xbj);

//constructor functions
//cons_ idiom for a function that constructs 

void obj_cons_null(XenonObject* xbj);

void obj_cons_int(XenonObject* xbj, const int value);

void obj_cons_uint(XenonObject* xbj, const unsigned int value);

void obj_cons_char(XenonObject* xbj, const char value);

void obj_cons_str(XenonObject* xbj, const char* value, int length);







#endif