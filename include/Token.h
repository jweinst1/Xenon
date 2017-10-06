#ifndef XENON_TOKEN_HEADER
#define XENON_TOKEN_HEADER

#include "EnumTypes.h"

struct Token
{
        TokenType type;
        union
        {
                XenEventType event;
                double number;

        };
        static inline Token make(double value)
        {
                return {.type = TokenType_Number, .number = value};
        }

        static inline Token make(XenEventType value)
        {
                return {.type = TokenType_EventStart, .event = value};
        }

        static inline void pntMake(Token* tk, double value)
        {
                tk->number = value;
                tk->type = TokenType_Number;
        }

        static inline void pntMake(Token* tk, XenEventType value)
        {
                tk->event = value;
                tk->type = TokenType_EventStart;
        }
};

#endif
