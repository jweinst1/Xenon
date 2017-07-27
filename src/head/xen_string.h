#ifndef XEN_STRING_H
#define XEN_STRING_H

//string object header

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    XenObject_HANDLE
    char* str;
    long len;
    long capacity;
} XenString;

#define XenString_GET_STR(xo) ((XenString*)xo)->str

#define XenString_GET_LEN(xs) xs->len

#define XenString_IS_FULL(xs) xs->len == xs->capacity

XenString* XenString_new_empty(long capacity);

XenString* XenString_new(const char* str);

static inline void 
XenString_expand(XenString* xs, const long size)
{
    xs->capacity += size;
    xs->str = realloc(xs->str, xs->capacity);
}

#ifdef __cplusplus
}
#endif

#endif