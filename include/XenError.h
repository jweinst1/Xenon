#ifndef XENON_ERROR_HEADER
#define XENON_ERROR_HEADER

#include <cstdarg>
#include <cstdio>
#include <exception>

enum XenErrType
{
        XenErrType_EventName
};

class XenError : public std::exception
{
private:
char _msg[300];
public:
XenError(const char* message, ...);

const char* what() const throw ()
{
        return _msg;
}
};

#endif
