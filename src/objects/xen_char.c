#include "Xenon.h"

XenChar* XenChar_new(char ch)
{
    XenChar* newchar = malloc(sizeof(XenChar));
    newchar->next = NULL;
    newchar->next = NULL;
    XenChar_MARK_TYPE(newchar);
    newchar->value = ch;
    return newchar;
}

int XenChar_make_int(XenChar* xc)
{
    switch(xc->value)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default:  return 0;
    }
 
}