#ifndef XENON_OBJECT_HEADER
#define XENON_OBJECT_HEADER

#include "EnumTypes.h"

//highest level class that all other values/objects inherit from in Xenon
class XenObject
{
private:
XenType _type;
public:
XenType getType() const
{
        return _type;
}

void setType(XenType type)
{
        _type = type;
}

bool sameTypeAs(const XenObject& other)
{
        return _type == other.getType();
}
};

//represents the null type
class XenNull : public XenObject
{
public:
XenNull()
{
        setType(XenType_Null);
}
};

#endif
