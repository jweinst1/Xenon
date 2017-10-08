#ifndef XENON_CONTEXT_MANAGER_HEADER
#define XENON_CONTEXT_MANAGER_HEADER

#include "EnumTypes.h"
#include "Token.h"

class ContextManager
{
private:
ParseState _state;

public:
ContextManager();
void parse(const Token& tk);
};

#endif
