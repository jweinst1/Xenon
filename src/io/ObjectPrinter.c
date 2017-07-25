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
        }
        xo = xo->next;
    }
    printf("]\n");
}