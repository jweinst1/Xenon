#ifndef XENON_TOKENIZER_HEADER
#define XENON_TOKENIZER_HEADER

#include "EnumTypes.h"

struct Token
{
        TokenType type;
        union
        {
                XenEventType event;
                double number;

        }
        Token(double value) : type(TokenType_Number), number(value)
        {

        }
};

class Tokenizer
{
private:
TokzState _state;
EventBuilder _eventBld;

public:
Tokenizer ();
~Tokenizer ();




};

#endif
