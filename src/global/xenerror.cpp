#include "xenerror.h"

extern "C" {
    
    
void XenError(const char* message)
{
    try  {throw message;}
    catch(const char* mess)
    {
        return;
    }
}
        
 
}