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

//gets and remove object at back end
XenObject* XenStream_pop(XenStream* xs)
{
    if(XenStream_IS_EMPTY(xs)) return NULL;
    
    XenObject* xopop = xs->back;
    if(XenStream_IS_SINGLET(xs))
    {
        XenStream_SET_FB_NULL(xs);
        return xopop;
    }
    else
    {
        xs->back = xs->back->prev;
        return xopop;
    }
    
}

//gets and remove object at front end
XenObject* XenStream_shift(XenStream* xs)
{
    if(XenStream_IS_EMPTY(xs)) return NULL;
    
    XenObject* xopop = xs->front;
    if(XenStream_IS_SINGLET(xs))
    {
        XenStream_SET_FB_NULL(xs);
        return xopop;
    }
    else
    {
        xs->back = xs->front->next;
        return xopop;
    } 
}