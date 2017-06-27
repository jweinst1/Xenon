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

//constructor functions

XenonObject cons_int_s(int value);



#endif