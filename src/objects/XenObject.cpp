#include "Xenon.h"

XenObject* XenObject::getFront()
{
    XenObject* xenPnt = this;
    while(!xenPnt->prevIsNull()) xenPnt = xenPnt->getPrev();
    return xenPnt;    
}

XenObject* XenObject::getBack()
{
    XenObject* xenPnt = this;
    while(!xenPnt->nextIsNull()) xenPnt = xenPnt->getNext();
    return xenPnt;
}

void XenObject::append(XenObject* xo)
{
    if(nextIsNull()) connectNext(xo);
    else
    {
        getBack()->connectNext(xo);
    }
}

void XenObject::put(XenObject* xo)
{
    if(prevIsNull()) connectPrev(xo);
    else
    {
        getFront()->connectPrev(xo);
    }   
}


int XenObject::length()
{
    int i = 1;
    XenObject* xoPnt = this;
    while((xoPnt = xoPnt->getNext())) i++;
    return i;
}

//gets an object at some index in the stream
//if index is larger than length, simply returns the last object
XenObject* XenObject::at(int index)
{
    XenObject* xenPnt = this;
    while(index--)
    {
        if(xenPnt->nextIsNull()) return xenPnt;
        xenPnt = xenPnt->getNext();
        
    }
    return xenPnt;
}