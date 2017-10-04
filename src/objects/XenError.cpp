#include "XenError.h"

XenError::XenError(const char* message, ...)
{
        va_list args;
        va_start (args, message);
        std::vsprintf(_msg, message, args);
        va_end (args);
}
