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

//appends one string object to another
void XenString_append(XenString* xs1, XenString* xs2)
{
    long newsize = xs1->len + xs2->len;
    //this will always add more than enough space than needed
    if(newsize > xs1->capacity) XenString_expand(xs1, newsize);
    strcat(xs1->str, xs2->str);
}