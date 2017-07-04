#ifndef XEN_OBJECT_H
#define XEN_OBJECT_H

//defines the basic XenObject interface structure for streams



#define XenObject_HANDLE unsigned char type;

typedef struct
{
    XenObject_HANDLE
} XenObject;


#define XenObject_GETTYPE(xo) xo->type

#define XenObject_SETTYPE(xo, t) xo->type = t

#define XenObject_SAMETYPE(xo1, xo2) xo1->type == xo2->type

#define XenObject_CASTOBJ(xo) (XenObject*)xo


#endif