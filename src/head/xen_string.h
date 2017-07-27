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

//macro for append function, works the same
#define XenString_APPEND(xs1, xs2) do { \
    if((xs1->len + xs2->len) > xs1->capacity) XenString_expand(xs1, (xs1->len + xs2->len)); \
    strcat(xs1->str, xs2->str); \
    xs1->len = newsize; }while(0)

XenString* XenString_new_empty(long capacity);

XenString* XenString_new(const char* str);

static inline void 
XenString_expand(XenString* xs, const long size)
{
    xs->capacity += size;
    xs->str = realloc(xs->str, xs->capacity);
}

void XenString_append(XenString* xs1, XenString* xs2);


#ifdef __cplusplus
}
#endif

#endif