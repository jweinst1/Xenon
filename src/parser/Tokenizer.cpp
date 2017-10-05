#include "Tokenizer.h"

Token::Token(double value) : type(TokenType_Number), number(value)
{

}

Token::Token(XenEventType value) : type(TokenType_EventStart), event(value)
{

}

Token::Token(TokenType value) : type(value)
{

}
