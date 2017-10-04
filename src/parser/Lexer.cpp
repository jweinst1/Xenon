#include "Lexer.h"
#include "CharSet.h"

CharSet TokenSets::whiteSpace = " \n\t\r\v\f";

CharSet TokenSets::digits = "0123456789";

CharSet TokenSets::alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::alphaNumeric = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::symbols = "_+-*/%~!@$^&<>=?";

CharSet TokenSets::eventName = "_+-*/%~!@$^&<>=?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::numbers = "-0123456789.";


//converts single digit character to double in O(1)
double Lexer::oneDigit(const char* ch)
{
        switch(*ch)
        {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default:
                throw XenError("Invalid number digit: %c", *ch);
        }
}

XenEventType Lexer::eventType(const char* token)
{
        switch(token[0])
        {
        case '+':
                return XenEventType_Add;
        case 'i':
                switch(token[1])
                {
                case 'n':
                        return XenEventType_In;
                default:
                        throw "doo";
                }
        case 'o':
                switch(token[1])
                {
                case 'u':
                        switch(token[2])
                        {
                        case 't':
                                return XenEventType_Out;
                        default:
                                throw "aoo";
                        }
                default:
                        throw "foo";
                }
        default:
                throw "foo";
        }
}
