#ifndef XEN_MACHINE_H
#define XEN_MACHINE_H

#ifdef __cplusplus
extern "C" {
#endif


typedef enum
{
    XenState_Start,
    XenState_GetName,
    XenState_GetInt
} XenState;

//sturcture for instance of the Xenon Machine
typedef struct
{
    XenEnv* env;
    XenState state;
    XenErrStatus err;
    char errstr[300];
} XenMachine;

//global instance of the xenmachine
static XenMachine XenMachine_MAIN = {XenEnv_new(), XenState_Start, XenErrStatus_Off};

//singleton instance of xenmachine
static inline XenMachine*
XenMachine_main()
{
    return &XenMachine_MAIN;
}

static inline void
XenMachine_main_set(XenState state)
{
    XenMachine_MAIN.state = state;
}

#ifdef __cplusplus
}
#endif

#endif