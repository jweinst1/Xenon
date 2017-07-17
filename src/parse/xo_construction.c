#include "Xenon.h"

XoConsToken* XoConsToken_from_void(XenType type, void* data)
{
    XoConsToken* xct = malloc(sizeof(XoConsToken));
    xct->type = type;
    xct->data = data;
    return xct;
}

XoConsToken* XoConsToken_from_bool(const unsigned char state)
{
    XoConsToken* xct = malloc(sizeof(XoConsToken));
    xct->type = XenType_Bool;
    xct->data = XoConsToken_DATA_ALLO_TYPE(xct, unsigned char);
    XoConsToken_DEREF_AND_SET(xct, unsigned char, state);
    return xct;
}

XoConsToken* XoConsToken_from_char(const char ch)
{
    XoConsToken* xct = malloc(sizeof(XoConsToken));
    xct->type = XenType_Char;
    xct->data = XoConsToken_DATA_ALLO_TYPE(xct, char);
    XoConsToken_DEREF_AND_SET(xct, char, ch);
    return xct;    
}

//main function that turns cons tokens into objects
XenObject* XoConsToken_cons_obj(XoConsToken* xoct)
{
    switch(XoConsToken_GET_TYPE(xoct))
    {
        case XenType_Bool:
            return (XenObject*)XenBool_new(XoConsToken_DEREF_DATA(xoct, unsigned char));
            break;
        case XenType_Char:
            return (XenObject*)XenChar_new(XoConsToken_DEREF_DATA(xoct, char));
            break;
    }
    XoConsToken_DELETE(xoct);
}