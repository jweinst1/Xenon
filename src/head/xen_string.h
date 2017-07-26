#ifndef XEN_STRING_H
#define XEN_STRING_H

//string object header

#ifdef __cplusplus
extern "C" {
#endif

typdef struct {
    XenObject_HANDLE
    char* str;
    long len;
    long capacity;
} XenString;

#ifdef __cplusplus
}
#endif

#endif