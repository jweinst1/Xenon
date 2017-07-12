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

#define XenNone_MARK_TYPE(xn) xn->type = 0

#define XenNone_IS_NONE(xn) xn->type == 0

#ifdef __cplusplus
}
#endif

#endif