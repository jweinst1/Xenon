#include "Xenon.h"


//compares a single reaction step to another
int XenComp_eq_rx(XenReaction* xrx1, XenReaction* xrx2)
{
    if(xrx1->arg_count != xrx2->arg_count || xrx1->instruction != xrx2->instruction)
        return 0;
    else
    {
        int i;
        for(i=0 ; i<xrx1->arg_count ; i++)
        {
            if(!XenComp_eq_object(XenReaction_GET_ARG(xrx1, i), XenReaction_GET_ARG(xrx2, i)))
                return 0;
        }
        return 1;
    }
}


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