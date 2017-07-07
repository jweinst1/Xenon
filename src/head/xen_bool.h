#ifndef XEN_BOOL_H
#define XEN_BOOL_H

//boolean object of xenon language
//type 1

typedef struct
{
    XenObject_HANDLE
    unsigned char state;
} XenBool;

#define XenBool_IS_TRUE(xb) xb->state == 1

#define XenBool_IS_FALSE(xb) xb->state == 0

#endif