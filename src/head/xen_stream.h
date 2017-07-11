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

#define XenStream_PUT(xs, xo) do { \
                   XenObject_CONNECT_PREV(xs->front, xo); \
                   xs->front = xo; }while(0)
                   
#define XenStream_APPEND(xs, xo) do { \
                   XenObject_CONNECT_NEXT(xs->back, xo); \
                   xs->back = xo; }while(0)


#ifdef __cplusplus
}
#endif

#endif
