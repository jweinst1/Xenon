#include "Xenon.h"

//reaction function file

XenReaction* XenReaction_new(XenInst ins, XenObject* args, int arg_count, XenReaction* path)
{
    XenReaction* rx = malloc(sizeof(XenReaction));
    XenReaction_MARK_TYPE(rx);
    rx->ins = ins;
    rx->args = args;
    rx->arg_count = arg_count;
    rx->path = path;
    return rx;
}

void XenReaction_del(XenReaction* xrx)
{
    if(xrx->path != NULL) XenReaction_del(xrx->path);
    while(arg_count--) XenObject_del((xrx->args + arg_count));
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
                
            }
            currRx = currRx->path;
        }
        xo = xo->next;
    }
}