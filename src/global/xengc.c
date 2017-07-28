#include "Xenon.h"

//deletes a reaction and all of it's child path
void XenGc_del_reaction(XenReaction* xrx)
{
    while(xrx != NULL)
    {
        while(xrx->arg_count--) XenGc_del(XenReaction_GET_ARG(xrx, xrx->arg_count));
        free(xrx);
        xrx = xrx->path;
    }
}

//deletes one string object and it's char* ptr
void XenGc_del_string(XenString* xs)
{
    free(xs->str);
    free(xs);
}

//deletes one general XenObject*
void XenGc_del_one(XenObject* xo)
{
    switch(xo->type)
    {
        case XenType_Reaction:
            XenGc_del_reaction((XenReaction*)xo);
            break;
        case XenType_String:
            XenGc_del_string((XenString*)xo);
            break;
        default:
            free(xo);
    }
}

//fully deletes one xenobject*
void XenGc_del(XenObject* xo)
{
    while(xo != NULL)
    {
        XenGc_del_one(xo);
        xo = xo->next;
    }
}