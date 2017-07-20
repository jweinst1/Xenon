#include "Xenon.h"

//used for creating new xo with no type
XenObject* XenObject_new()
{
    XenObject* xo = malloc(sizeof(XenObject));
    xo->next = NULL;
    xo->prev = NULL;
    return xo;
}

void XenObject_insert_next(XenObject* xo1, XenObject* xo2)
{
    if(xo1->next != NULL)
    {
        XenObject* temp = xo1->next;
        xo1->next = xo2;
        XenObject_ADV_BACK(xo2);
        xo2->next = temp;
        temp->prev = xo2;
    }
    else
    {
        xo1->next = xo2;
        xo2->prev = xo1;
    }
}

int XenObject_length(XenObject* xo)
{
    int i = 1;
    while(xo->next != NULL) {i++; xo = xo->next;}
    return i;
}

//function version so as not to consume pointer
void XenObject_put(XenObject* xo1, XenObject* xo2)
{
    XenObject_ADV_FRONT(xo1);
    xo2->next = xo1;
    xo1->prev = xo2;
}

//appends to stream
void XenObject_append(XenObject* xo1, XenObject* xo2)
{
    XenObject_ADV_BACK(xo1);
    xo1->next = xo2;
    xo2->prev = xo1;
}

void XenObject_del(XenObject* xo)
{
    switch(xo->type) 
    {
        case XenType_Bool:
            free((XenBool*)xo);
        case XenType_Char:
            free((XenChar*)xo);
        default: free(xo);
    }
}