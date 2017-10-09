#include <iostream>
#include "ContextManager.h"

ContextManager::ContextManager() : _lastEvent(XenEventType_null),
        _curEvent(XenEventType_null)
{
}

void ContextManager::parse(const Token& tk)
{
        switch(tk.type)
        {
        case TokenType_EventStart:
                break;
        case TokenType_EventEnd:
                std::cout << "event ended\n";
                break;
        case TokenType_Number:
                std::cout << "Number found, value is:" << tk.number << "\n";
                break;
        }
}
