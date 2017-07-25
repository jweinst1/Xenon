#include "Xenon.h"

//function that prints streams to stdout
void ObjectPrinter_print(XenObject* xo)
{
    printf("[");
    while(xo != NULL)
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
            case XenType_Reaction:
                break;
        }
        xo = xo->next;
    }
    printf("]\n");
}