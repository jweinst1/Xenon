#include <iostream>
#include "ContextManager.h"

ContextManager::ContextManager() : _state(ParseState_Base)
{
}

void ContextManager::parse(const Token& tk)
{
        switch(tk.type)
        {
        case TokenType_EventStart:
                std::cout << "Event Started, name is:" << tk.event << "\n";
                break;
        case TokenType_EventEnd:
                std::cout << "event ended\n";
                break;
        case TokenType_Number:
                std::cout << "Number found, value is:" << tk.number << "\n";
                break;
        }
}
