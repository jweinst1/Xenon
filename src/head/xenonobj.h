#ifndef XENON_OBJECT_H
#define XENON_OBJECT_H

extern "C" {

//used for casting
typedef unsigned char XenonType;



typedef struct {
    XenonType type;
} XenonObject;

}

#endif