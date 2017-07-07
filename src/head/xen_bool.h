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

#define XenBool_FLIP(xb) xb->state == 0 ? xb->state = 1: xb->state = 0

#define XenBool_AND(xb1, xb2) (xb1->state) && (xb2->state)

#define XenBool_OR(xb1, xb2) (xb1->state) || (xb2->state)

#define XenBool_NOT(xb) !(xb->state)

#endif