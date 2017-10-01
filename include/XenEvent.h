#ifndef XENON_EVENT_HEADER
#define XENON_EVENT_HEADER

enum XenEventType
{
        XenEventType_In,
        XenEventType_Out,
        XenEventType_Add
};

class XenEvent : public XenObject
{
private:
XenEventType _type;
Sequence<XenObject> _args;
public:
static XenEventType strToEvType(const char* token);
};

#endif //XENON_EVENT_HEADER
