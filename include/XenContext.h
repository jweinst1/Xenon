#ifndef XENON_CONTEXT_HEADER
#define XENON_CONTEXT_HEADER

//this file contains a context class to facilitate reaction streams

#include "XenObject.h"

class XenContext
{
public:

XenContext()
{
}
~XenContext()
{
}

void setVariable(const XenObject& xo)
{
        _variable = xo;
}
private:
XenObject _variable;
};

#endif
