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
                    
#define XenObject_HAS_NEXT(xo) xo->next == NULL

#define XenObject_HAS_PREV(xo) xo->prev == NULL

#define XenObject_IS_END(xo) xo->next == NULL || xo->prev == NULL

//advances pointer to back of stream
#define XenObject_ADV_BACK(xo) while(xo->next != NULL) xo = xo->next

//advances pointer to front of stream
#define XenObject_ADV_FRONT(xo) while(xo->prev != NULL) xo = xo->prev

#define XenObject_APPEND(xo1, xo2) do { \
     while(xo1->next != NULL) xo1 = xo1->next; \
     xo1->next = xo2; \
     xo2->prev = xo1; \
    }while(0)
    
#define XenObject_PUT(xo1, xo2) do { \
     while(xo1->prev != NULL) xo1 = xo1->prev; \
     xo1->prev = xo2; \
     xo2->next = xo1; \
    }while(0)


#endif