#ifndef XENON_NUMBER_HEADER
#define XENON_NUMBER_HEADER

#include "XenObject.h"

class XenNumber : public XenObject
{
private:
double _value;
public:
XenNumber(double value);

double getValue()
{
        return _value;
}

void setValue(double value)
{
        _value = value;
}

double& getRef()
{
        return _value;
}
};

#endif
