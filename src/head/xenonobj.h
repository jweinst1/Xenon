#ifndef XENON_OBJECT_H
#define XENON_OBJECT_H



//used for casting
typedef unsigned XenonType;



typedef struct {
    XenonType type;
    int refc;
} XenonObject;



#endif