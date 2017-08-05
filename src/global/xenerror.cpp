#include "xenerror.h"

extern "C" {
    
    
void XenError(const char* message)
{
    throw message;
}
        

}