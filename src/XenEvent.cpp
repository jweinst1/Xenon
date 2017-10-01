#include "Xenon.h"

XenEventType XenEvent::strToEvType(const char* token)
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
