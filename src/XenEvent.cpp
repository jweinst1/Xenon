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
        default:
                throw "foo";
        }
}
