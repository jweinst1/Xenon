#ifndef XENON_EVENT_HEADER
#define XENON_EVENT_HEADER

class XenEvent : public XenObject
{
private:
XenEventType _type;
Sequence<XenObject> _args;
public:
static XenEventType strToEvType(const char* token);
};

#endif //XENON_EVENT_HEADER
