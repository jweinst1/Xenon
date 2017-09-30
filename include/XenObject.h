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

#endif
