#ifndef XEN_BOOL_H
#define XEN_BOOL_H

#ifdef __cplusplus
extern "C" {
#endif


//boolean object of xenon language
//type 1



typedef struct
{
    XenObject_HANDLE
    unsigned char state;
} XenBool;

#define XenBool_MARK_TYPE(xb) xb->type = XenType_Bool

#define XenBool_IS_TRUE(xb) xb->state == 1

#define XenBool_IS_FALSE(xb) xb->state == 0

#define XenBool_STATE(xb) xb->state

#define XenBool_FLIP(xb) xb->state == 0 ? xb->state = 1: xb->state = 0

#define XenBool_SET_TRUE(xb) xb->state = 1

#define XenBool_SET_FALSE(xb) xb->state = 0

#define XenBool_AND(xb1, xb2) (xb1->state) && (xb2->state)

#define XenBool_OR(xb1, xb2) (xb1->state) || (xb2->state)

#define XenBool_NOT(xb) !(xb->state)

#define XenBool_IS_BOOL(xb) xb->type == 1

#define XenBool_TO_CINT(xb) (int)xb->state

//functions

XenBool* XenBool_new(unsigned char s);

int XenBool_get_int(XenBool* xb);

int XenBool_and_int(XenBool* xb, const int bl);

int XenBool_or_int(XenBool* xb, const int bl);

//todo ;>> deletion of stream will require different mechanism to work with all types
static inline void
XenBool_del(XenBool* xb)
{
    free(xb);
}

#ifdef __cplusplus
}
#endif

#endif