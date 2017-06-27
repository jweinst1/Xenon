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


void obj_del(XenonObject* xbj);

//constructor functions
//cons_ idiom for a function that constructs 

void obj_cons_int(XenonObject* xbj, int value);






#endif