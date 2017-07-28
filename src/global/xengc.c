#include "Xenon.h"

void XenGc_del_one(XenObject* xo)
{
    switch(xo->type)
    {
        case XenType_Int:
            break;
        default:
            free(xo);
    }
}

void XenGc_del(XenObject* xo)
{
    
}