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

//checks if same instance in stream
int XenObject_contains(XenObject* xo, XenObject* xoitem)
{
    while(xo->next != NULL)
    {
        if(xoitem == xo) return 1;
        xo = xo->next;
    }
    return 0;
}

//removes and returns front most object
XenObject* XenObject_pop(XenObject* xo)
{
    if(XenObject_IS_SING(xo)) return xo;
    else
    {
        if(!(XenObject_IS_FRONT(xo))) XenObject_ADV_FRONT(xo);
        xo->next->prev = NULL;
        XenObject* popped = xo;
        popped->next = NULL;
        return popped;
    }
}

void XenObject_del(XenObject* xo)
{
    switch(xo->type) 
    {
        case XenType_Bool:
            free((XenBool*)xo);
            break;
        case XenType_Char:
            free((XenChar*)xo);
            break;
        case XenType_Int:
            free((XenInt*)xo);
            break;
        default: free(xo);
    }
}