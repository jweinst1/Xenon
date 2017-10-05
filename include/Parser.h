#ifndef XENON_PARSER_HEADER
#define XENON_PARSER_HEADER

#include "Token.h"
#include "EnumTypes.h"

class Parser
{
private:
ParseState _state;

public:
Parser();
void parse(const Token& tk);
};

#endif
