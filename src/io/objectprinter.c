#include "Xenon.h"

//handles a single reaction at a time
void ObjectPrinter_print_srx(XenReaction* xrx)
{
    switch(xrx->instruction)
    {
        case XenInst_Add:
            break;
        case XenInst_Sub:
            break;
        case XenInst_Mul:
            break;
        case XenInst_Div:
            break;
        case XenInst_Rem:
            break;
        case XenInst_Abs:
            break;
        case XenInst_Inc:
            break;
        case XenInst_Dec:
            break;
        case XenInst_End:
            break;
    }    
}

//function that prints reactions to stdout
void ObjectPrinter_print_rx(XenObject* xo)
{
    XenReaction* xrx = (XenReaction*)xo;
    printf("{");
    
    while(xrx->path != NULL)
    {
        ObjectPrinter_print_srx(xrx);
        printf(" -> ");
        xrx = xrx->path;
    }
    ObjectPrinter_print_srx(xrx);
    printf("}");
}

//prints a single object node
void ObjectPrinter_print_s(XenObject* xo)
{
    switch(xo->type)
    {
        case XenType_Int:
            ObjectPrinter_PRINT_LONG(XenInt_GET_INT(xo));
            break;
        case XenType_Char:
            putchar(XenChar_GET_CHAR(xo));
            break;
        case XenType_Bool:
            ObjectPrinter_PRINT_BOOL(XenBool_GET_BOOL(xo));
            break;
        case XenType_None:
            puts("None");
            break;
        case XenType_String:
            puts(XenString_GET_STR(xo));
            break;
        case XenType_Reaction:
            ObjectPrinter_print_rx(xo);
            break;
    }   
}

//function that prints streams to stdout
void ObjectPrinter_print(XenObject* xo)
{
    printf("[");
    while(xo->next != NULL)
    {
        ObjectPrinter_print_s(xo);
        printf(", ");
        xo = xo->next;
    }
    ObjectPrinter_print_s(xo); //prints last object
    printf("]\n");
}