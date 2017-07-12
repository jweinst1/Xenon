#ifndef XEN_OBJECT_H
#define XEN_OBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

//defines the basic XenObject interface structure for streams



#define XenObject_HANDLE unsigned char type; \
        struct XenObject * next; \
        struct XenObject * prev;

struct XenObject
{
    XenObject_HANDLE
};

typedef struct XenObject XenObject;



#define XenObject_SET_NP_NULL(xo) do { \
                   xo->next = NULL; \
                   xo->prev = NULL;} while(0)
                   
#define XenObject_SET_N_NULL(xo) xo->next = NULL

#define XenObject_SET_P_NULL(xo) xo->prev = NULL

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

void XenObject_insert_next(XenObject* xo1, XenObject* xo2);

int XenObject_length(XenObject* xo);


static inline void 
XenObject_append(XenObject* xo1, XenObject* xo2)
{
    XenObject_ADV_BACK(xo1);
    xo1->next = xo2;
    xo2->prev = xo1;
}

void XenObject_put(XenObject* xo1, XenObject* xo2);

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

#ifdef __cplusplus
}
#endif


#endif