#include "Xenon.h"

//creates new empty string 
XenString* XenString_new_empty(long capacity)
{
    XenString* xs = malloc(sizeof(XenString));
    xs->type = XenType_String;
    xs->capacity = capacity;
    xs->len = 0;
    xs->str = NULL;
    return xs;
}

//creates a new string with a char pointer
XenString* XenString_new(const char* str)
{
    XenString* xs = malloc(sizeof(XenString));
    xs->type = XenType_String;
    xs->len = strlen(str);
    xs->capacity = xs->len * 2;
    xs->str = malloc(xs->capacity);
    return xs;
}