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

        };
        Token(double value);

        Token(XenEventType value);

        Token(TokenType value);
};

class Tokenizer
{
private:
TokzState _state;

public:
Tokenizer ();
~Tokenizer ();






};

#endif
