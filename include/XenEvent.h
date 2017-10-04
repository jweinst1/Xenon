#ifndef XENON_EVENT_HEADER
#define XENON_EVENT_HEADER

#include "EnumTypes.h"
#include "Sequence.h"
#include "XenObject.h"

class XenEvent : public XenObject
{
private:
XenEventType _type;
Sequence<XenObject> _args;
public:

};

#endif //XENON_EVENT_HEADER
