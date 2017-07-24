#include "Xenon.h"

//reaction function file

XenReaction* XenReaction_new(XenInst ins, XenObject* args, int arg_count, XenReaction* path)
{
    XenReaction* rx = malloc(sizeof(XenReaction));
    XenReaction_MARK_TYPE(rx);
    rx->instruction = ins;
    rx->args = args;
    rx->arg_count = arg_count;
    rx->path = path;
    return rx;
}

void XenReaction_del(XenReaction* xrx)
{
    if(xrx->path != NULL) XenReaction_del(xrx->path);
    while(xrx->arg_count--) XenObject_del(XenReaction_GET_ARG(xrx, xrx->arg_count));
    free(xrx);
}

//main function that runs reactions against streams
void XenReaction_react(XenReaction* xrx, XenObject* xo)
{
    XenReaction* currRx;
    while(xo != NULL)
    {
        currRx = xrx;
        while(currRx != NULL)
        {
            switch(currRx->instruction)
            {
                case XenInst_Add:
                    XenInt_GET_INT(xo) += XenInt_GET_INT(XenReaction_GET_ARG(xrx, 0));
                    break;
                case XenInst_Sub:
                    XenInt_GET_INT(xo) -= XenInt_GET_INT(XenReaction_GET_ARG(xrx, 0));
                    break;
                case XenInst_Mul:
                    XenInt_GET_INT(xo) *= XenInt_GET_INT(XenReaction_GET_ARG(xrx, 0));
                    break;
                case XenInst_Div:
                    XenInt_GET_INT(xo) /= XenInt_GET_INT(XenReaction_GET_ARG(xrx, 0));
                    break;
                case XenInst_Rem:
                    XenInt_GET_INT(xo) %= XenInt_GET_INT(XenReaction_GET_ARG(xrx, 0));
                    break;
                case XenInst_Abs:
                    XenInt_GET_INT(xo) = abs(XenInt_GET_INT(xo));
                    break;
            }
            currRx = currRx->path;
        }
        xo = xo->next;
    }
}