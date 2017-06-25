#ifndef XENON_OBJECT_H
#define XENON_OBJECT_H

extern "C" {

//used for casting
typedef unsigned char XenonType;

//alternate name for C-level casting
typedef void* XenonValue;

typedef struct {
    XenonType type;
    XenonValue val;
} XenonObject;

}

#endif