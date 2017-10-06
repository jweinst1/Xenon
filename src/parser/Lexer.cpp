#include "Lexer.h"
#include "CharSet.h"

CharSet TokenSets::whiteSpace = " \n\t\r\v\f";

CharSet TokenSets::digits = "0123456789";

CharSet TokenSets::alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::alphaNumeric = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::symbols = "_+-*/%~!@$^&<>=?";

CharSet TokenSets::eventName = "_+-*/%~!@$^&<>=?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

CharSet TokenSets::numbers = "0123456789.";

CharSet TokenSets::numberStart = "-0123456789";


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

//parses event name using static jump table structure.
void Lexer::eventType(char* token, XenEventType* eType, char** nextChar)
{
        switch(token[0])
        {
        case '+':
                switch(token[1])
                {
                case '+':
                        *eType = XenEventType_Inc;
                        *nextChar = token + 2;
                        return;
                default: break;
                }
                *eType = XenEventType_Add;
                *nextChar = token + 1;
                break;
        case '-':
                switch(token[1])
                {
                case '-':
                        *eType = XenEventType_Dec;
                        *nextChar = token + 2;
                        break;
                default: break;
                }
                *eType = XenEventType_Sub;
                *nextChar = token + 1;
                break;
        case '*':
                *eType = XenEventType_Mul;
                *nextChar = token + 1;
                break;
        case '/':
                *eType = XenEventType_Div;
                *nextChar = token + 1;
                break;
        case 'i':
                switch(token[1])
                {
                case 'n':
                        *nextChar = token + 2;
                        *eType = XenEventType_In;
                        break;
                default:
                        *eType = XenEventType_null;
                }
                break;
        case 'o':
                switch(token[1])
                {
                case 'u':
                        switch(token[2])
                        {
                        case 't':
                                *nextChar = token + 3;
                                *eType = XenEventType_Out;
                                break;
                        default:
                                *eType = XenEventType_null;
                        }
                        break;
                default:
                        *eType = XenEventType_null;
                }
                break;
        default:
                *eType = XenEventType_null;
        }
}
