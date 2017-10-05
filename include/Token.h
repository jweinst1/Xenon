#ifndef XENON_TOKENIZER_HEADER
#define XENON_TOKENIZER_HEADER

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
};

#endif
