#include "Xenon.h"

//gets length of reaction
int XenReaction_len(XenReaction* xrx)
{
    int l = 1;
    while(xrx->path != NULL) l++;
    return l;
}

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
                case XenInst_Inc:
                    XenInt_GET_INT(xo)++;
                    break;
                case XenInst_Dec:
                    XenInt_GET_INT(xo)--;
                    break;
                case XenInst_End: //stops the reaction
                    currRx = NULL;
                    xo = NULL;
                    break;
            }
            currRx = currRx->path;
        }
        xo = xo->next;
    }
}