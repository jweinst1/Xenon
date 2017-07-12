#ifndef XEN_STREAM_H
#define XEN_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

//barest requirement for a stream, similar to object handle
#define XenStream_HANDLE XenObject* front; \
                   XenObject* back;

struct XenStream {
    XenStream_HANDLE
};

typedef struct XenStream XenStream;

#define XenStream_SET_FB_NULL(xs) do { \
                   xs->front = NULL; \
                   xs->back = NULL; }while(0)
                   
#define XenStream_IS_SINGLET(xs) xs->front == xs->back

#define XenStream_IS_EMPTY(xs) xs->front == NULL && xs->back == NULL

#define XenStream_ADD_FIRST(xs, xo) do { \
                   xs->front = xo; \
                   xs->back = xo; }while(0)

#define XenStream_PUT(xs, xo) do { \
                   if(XenStream_IS_EMPTY(xs)) XenStream_ADD_FIRST(xs, xo); \
                   else {\
                      XenObject_CONNECT_PREV(xs->front, xo); \
                      xs->front = xo; } \
                }while(0)
                   
#define XenStream_APPEND(xs, xo) do { \
                   if(XenStream_IS_EMPTY(xs)) XenStream_ADD_FIRST(xs, xo); \
                   else {\
                      XenObject_CONNECT_NEXT(xs->back, xo); \
                      xs->back = xo; } \
                }while(0)
 
//versions of put and append which do not check if empty               
#define XenStream_FPUT(xs, xo) do { \
                   XenObject_CONNECT_PREV(xs->front, xo); \
                   xs->front = xo; }while(0)
                   
#define XenStream_FAPPEND(xs, xo) do { \
                   XenObject_CONNECT_NEXT(xs->back, xo); \
                   xs->back = xo; }while(0)
   
XenStream* XenStream_new();   
                
void XenStream_put(XenStream* xs, XenObject* xo);

void XenStream_append(XenStream* xs, XenObject* xo);

XenObject* XenStream_pop(XenStream* xs);

XenObject* XenStream_shift(XenStream* xs);


void XenStream_set(XenStream* xs, XenObject* xo);

#ifdef __cplusplus
}
#endif

#endif
