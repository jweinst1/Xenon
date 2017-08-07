#ifndef XEN_ERROR_H
#define XEN_ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

//file that contains implementation of the xenon error system

//contains the state of error status
static int XenError_STATUS = 0;

//a global variable which contains an error message
static char XenError_MESSAGE[250];

static inline void
XenError_on()
{
    XenError_STATUS = 1;
}

static inline void
XenError_off()
{
    XenError_STATUS = 0;
}

static inline void
XenError_write(char* mes)
{
    strcpy(XenError_MESSAGE, mes);
}

//reads error message into buffer
static inline void
XenError_read(char* buf)
{
    strcpy(buf, XenError_MESSAGE);
}

//prints the current error message
static inline void
XenError_print()
{
    puts(XenError_MESSAGE);
}

#ifdef __cplusplus
}
#endif


#endif