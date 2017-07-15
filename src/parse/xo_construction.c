#include "Xenon.h"

XoConsToken* XoConsToken_from_void(XenType type, void* data)
{
    XoConsToken* xct = malloc(sizeof(XoConsToken));
    xct->type = type;
    xct->data = data;
    return xct;
}

XoConsToken* XoConsToken_from_bool(const int state)
{

}

XoConsToken* XoConsToken_from_char(const char ch)
{
    XoConsToken* xct = malloc(sizeof(XoConsToken));
    xct->type = XenType_Char;
    xct->data = XoConsToken_DATA_ALLO_TYPE(xct, char);
    XoConsToken_DEREF_AND_SET(xct, char, ch);
    return xct;    
}

XenonObject* XoConsToken_cons_obj(XoConsToken* xoct)
{
    
}