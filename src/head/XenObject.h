#ifndef XENON_OBJECT_HEADER
#define XENON_OBJECT_HEADER

//enum type for XenObject only
enum XenType
{
        XenType_Number
};

//highest level class that all other values/objects inherit from in Xenon
class XenObject
{
public:
XenType getType()
{
        return _type;
}

void setType(XenType type)
{
        _type = type;
}
private:
XenType _type;
};

#endif
