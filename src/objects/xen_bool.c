#include "xen_bool.h"

XenBool* XenBool_new(unsigned char s)
{
    XenBool* newbool = malloc(sizeof(XenBool));
    newbool->next = NULL;
    newbool->next = NULL;
    XenBool_MARK_TYPE(newbool);
    return newbool;
}

int XenBool_get_int(XenBool* xb)
{
    return (xb->state) ? 1 : 0;
}