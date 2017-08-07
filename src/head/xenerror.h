#ifndef XEN_ERROR_H
#define XEN_ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

//file that contains implementation of the xenon error system


static inline void
XenError_on(XenMachine* xem)
{
    xem->err = XenErrStatus_On;
}

static inline void
XenError_off(XenMachine* xem)
{
    xem->err = XenErrStatus_Off;
}

static inline void
XenError_write(XenMachine* xem, char* mes)
{
    strcpy(xem->errstr, mes);
}

//reads error message into buffer, from XenMachine
static inline void
XenError_read(XenMachine* xem, char* buf)
{
    strcpy(buf, xem->errstr);
}

//prints the current error message
static inline void
XenError_print(XenMachine* xem)
{
    puts(xem->errstr);
}

//sets the error message to nothing
static inline void
XenError_reset(XenMachine* xem)
{
    xem->errstr[0] = '\0';
}

#ifdef __cplusplus
}
#endif


#endif