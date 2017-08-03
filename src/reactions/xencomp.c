#include "Xenon.h"


//function used to determine equality between objects
int XenComp_eq_object(XenObject* xo1, XenObject* xo2)
{
    if(xo1->type != xo2->type) return 0;
    else switch(xo1->type)
    {
        case XenType_Bool:
            return XenComp_SAME_BOOL(xo1, xo2);
            break;
        case XenType_Char:
            return XenComp_SAME_CHAR(xo1, xo2);
            break;
        case XenType_Int:
            return XenComp_SAME_INT(xo1, xo2);
            break;
        case XenType_String:
            return XenComp_SAME_STR(xo1, xo2);
            break;
        case XenType_None:
            return 1;
            break;
        default:
            return 0;
    }
}