#include "Xenon.h"


XenStream* XenStream_new()
{
    XenStream* xsn = malloc(sizeof(XenStream));
    XenStream_SET_FB_NULL(xsn);
    return xsn;
}


void XenStream_put(XenStream* xs, XenObject* xo)
{
    if(XenStream_IS_EMPTY(xs))
    {
        xs->front = xo;
        xs->back = xo;
    }
    else
    {
        XenObject_CONNECT_PREV(xs->front, xo);
        xs->front = xo;
    }
}

void XenStream_append(XenStream* xs, XenObject* xo)
{
    if(XenStream_IS_EMPTY(xs))
    {
        xs->front = xo;
        xs->back = xo;
    }
    else
    {
        XenObject_CONNECT_NEXT(xs->back, xo);
        xs->back = xo;
    }    
}

void XenStream_set(XenStream* xs, XenObject* xo)
{
    xs->front = XenObject_get_front(xo);
    xs->back = XenObject_get_back(xo);
}