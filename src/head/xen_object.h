#ifndef XEN_OBJECT_H
#define XEN_OBJECT_H

//defines the basic XenObject interface structure for streams



#define XenObject_HANDLE unsigned char type; \
        struct XenObject * next; \
        struct XenObject * prev;

struct XenObject
{
    XenObject_HANDLE
};

typedef struct XenObject XenObject;






#define XenObject_GETTYPE(xo) xo->type

#define XenObject_SETTYPE(xo, t) xo->type = t

#define XenObject_SAMETYPE(xo1, xo2) xo1->type == xo2->type

#define XenObject_CASTOBJ(xo) (XenObject*)xo

#define XenObject_CONNECT_NEXT(xo1, xo2) do { \
                    xo1->next = xo2; \
                    xo2->prev = xo1; } while(0)
                    
#define XenObject_CONNECT_PREV(xo1, xo2) do { \
                    xo1->prev = xo2; \
                    xo2->next = xo1; } while(0)


#endif