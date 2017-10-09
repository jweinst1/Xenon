#ifndef XENON_CONTEXT_MANAGER_HEADER
#define XENON_CONTEXT_MANAGER_HEADER

#include <algorithm>
#include "EnumTypes.h"
#include "Token.h"
#include "XenContext.h"

class ContextManager
{
private:
XenContext _context;
XenEventType _lastEvent;
XenEventType _curEvent;





public:
ContextManager();
void parse(const Token& tk);

XenEventType& getCurEvent()
{
        return _curEvent;
}

XenEventType& getLastEvent()
{
        return _lastEvent;
}

inline void changeEvent(XenEventType eType)
{
        std::swap(_curEvent, _lastEvent);
        _curEvent = eType;
}


};

#endif
