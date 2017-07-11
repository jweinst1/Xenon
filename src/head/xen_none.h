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

#ifdef __cplusplus
}
#endif

#endif