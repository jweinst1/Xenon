#ifndef XEN_NONE_H
#define XEN_NONE_H

/*
The none object is used as a xenon type to represent no type, safer than using NULL
*/

#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
    XenObject_HANDLE
} XenNone;

#define XenNone_MARK_TYPE(xn) xn->type = XenType_None

#define XenNone_IS_NONE(xn) xn->type == XenType_None

static inline XenNone*
XenNone_new()
{
    XenNone* xn = malloc(sizeof(XenNone));
    XenNone_MARK_TYPE(xn);
    return xn;
}

#ifdef __cplusplus
}
#endif

#endif