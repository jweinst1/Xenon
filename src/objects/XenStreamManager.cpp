#include "Xenon.h"

XenStreamManager::XenStreamManager()
{
    frontStream = NULL;
    backStream = NULL;
}

int XenStreamManager::length()
{
    int i = 0;
    if(streamIsNull()) return i;
    XenObject* xenPnt = getFrontStream();
    while(xenPnt)
}

