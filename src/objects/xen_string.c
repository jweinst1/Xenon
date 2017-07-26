#include "Xenon.h"

XenString* XenString_new(long len, long capacity)
{
    XenString* xs = malloc(sizeof(XenString));
    xs->type = XenType_String;
    xs->capacity = capacity;
    return xs;
}