#include "Xenon.h"

XenInt* XenInt_new(long value)
{
    XenInt* xi = malloc(sizeof(XenInt));
    XenInt_MARK_TYPE(xi);
    xi->value = value;
    return xi;
}