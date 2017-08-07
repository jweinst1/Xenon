#ifndef XEN_ERROR_H
#define XEN_ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

//file that contains implementation of the xenon error system

//enum that determines error status for an instance of XenMachine
typedef enum
{
    XenErrStatus_On,
    XenErrStatus_Off
} XenErrStatus;

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
XenError_read(XenMachine* xem, char* mes)
{
    strcpy(buf, xem->errstr);
}

//prints the current error message
static inline void
XenError_print(XenMachine* xem)
{
    puts(xem->errstr);
}

#ifdef __cplusplus
}
#endif


#endif