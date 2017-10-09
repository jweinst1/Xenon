#ifndef XENON_CONTEXT_HEADER
#define XENON_CONTEXT_HEADER

#include <map>
#include "XenObject.h"

class XenContext
{
private:
XenObject _variable;
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

XenObject& getVariable()
{
        return _variable;
}
};

#endif
