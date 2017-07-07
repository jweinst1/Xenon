#include "xen_object.h"


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