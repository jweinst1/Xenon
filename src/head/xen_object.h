#ifndef XEN_OBJECT_H
#define XEN_OBJECT_H



//defines the basic XenObject interface class for streams



#define XenObject_HANDLE XenType type; \
        XenObject * next; \
        XenObject * prev;

class XenObject
{
public:
    XenObject_HANDLE
public:
    XenType getType();
    void setType(XenType type);
    XenObject* getNext();
    XenObject* getPrev();
};



#define XenObject_SET_NP_NULL(xo) do { \
                   xo->next = NULL; \
                   xo->prev = NULL;} while(0)
                   
#define XenObject_SET_N_NULL(xo) xo->next = NULL

#define XenObject_SET_P_NULL(xo) xo->prev = NULL

#define XenObject_IS_TYPE(xo, ty), xo->type == ty

#define XenObject_GET_TYPE(xo) xo->type

#define XenObject_SET_TYPE(xo, t) xo->type = t

#define XenObject_SAME_TYPE(xo1, xo2) xo1->type == xo2->type

#define XenObject_SAME_PNT(xo1, xo2) xo1 == xo2 

#define XenObject_CAST(xo) (XenObject*)xo

#define XenObject_CONNECT_NEXT(xo1, xo2) do { \
                    xo1->next = xo2; \
                    xo2->prev = xo1; } while(0)
                    
#define XenObject_CONNECT_PREV(xo1, xo2) do { \
                    xo1->prev = xo2; \
                    xo2->next = xo1; } while(0)
                    
#define XenObject_HAS_NEXT(xo) xo->next == NULL

#define XenObject_HAS_PREV(xo) xo->prev == NULL

#define XenObject_GET_NEXT(xo) xo->next

#define XenObject_GET_PREV(xo) xo->prev

#define XenObject_GET_NEXT_NEXT(xo) xo->next->next

#define XenObject_GET_PREV_PREV(xo) xo->prev->prev

#define XenObject_IS_END(xo) xo->next == NULL || xo->prev == NULL

#define XenObject_IS_SING(xo) xo->next == NULL && xo->prev == NULL

#define XenObject_IS_FRONT(xo) xo->prev == NULL

#define XenObject_IS_BACK(xo) xo->next == NULL

//advances pointer to back of stream
#define XenObject_ADV_BACK(xo) while(xo->next != NULL) xo = xo->next

//advances pointer to front of stream
#define XenObject_ADV_FRONT(xo) while(xo->prev != NULL) xo = xo->prev

//moves n times toward the front
#define XenObject_ADVN_FRONT(xo, n) while(n--) xo = xo->prev

//moves n times toward the back
#define XenObject_ADVN_BACK(xo, n) while(n--) xo = xo->next

//moves n times but will not move onto null
#define XenObject_ADVN_SAFE_FRONT(xo, n) while(n-- && xo->prev != NULL) xo = xo->prev

//moves n times but not onto null
#define XenObject_ADVN_SAFE_BACK(xo, n) while(n-- && xo->next != NULL) xo = xo->next

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


//functions

//gets new xo with no type
XenObject* XenObject_new();

void XenObject_append(XenObject* xo1, XenObject* xo2);

void XenObject_put(XenObject* xo1, XenObject* xo2);

//assumes xo1 is at back and appends, return xo2
static inline XenObject*
XenObject_append_auto(XenObject* xo1, XenObject* xo2)
{
    xo1->next = xo2;
    xo2->prev = xo1;
    return xo2;
}

//used for successive puts
static inline XenObject*
XenObject_put_auto(XenObject* xo1, XenObject* xo2)
{
    xo1->prev = xo2;
    xo2->next = xo1;
    return xo1;
}

static inline XenObject*
XenObject_get_back(XenObject* xo)
{
    XenObject_ADV_BACK(xo);
    return xo;
}

static inline XenObject*
XenObject_get_front(XenObject* xo)
{
    XenObject_ADV_FRONT(xo);
    return xo;
}

void XenObject_insert_next(XenObject* xo1, XenObject* xo2);

int XenObject_length(XenObject* xo);

int XenObject_contains(XenObject* xo, XenObject* xoitem);

XenObject* XenObject_pop(XenObject* xo);

XenObject* XenObject_remove(XenObject* xo);




#endif