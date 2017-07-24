#include "Xenon.h"

XenInt* XenInt_new(long value)
{
    XenInt* xi = malloc(sizeof(XenInt));
    XenInt_MARK_TYPE(xi);
    xi->value = value;
    return xi;
}

//constructor which casts to xenobject
XenObject* XenInt_new_obj(long value)
{
    XenInt* xi = malloc(sizeof(XenInt));
    XenInt_MARK_TYPE(xi);
    xi->value = value;
    return (XenObject*)xi;   
}