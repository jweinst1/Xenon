#ifndef XEN_MACHINE_H
#define XEN_MACHINE_H

#ifdef __cplusplus
extern "C" {
#endif

//macro that determines if the static main instance is activated or not
#define XenMachine_INIT_MAIN 1

#define XenMachine_GET_ENV(xem) xem->env

//enum that determines error status for an instance of XenMachine
typedef enum
{
    XenErrStatus_On,
    XenErrStatus_Off
} XenErrStatus;

typedef enum
{
    XenState_Start,
    XenState_GetName,
    XenState_GetInt,
    XenState_Assign
} XenState;

//sturcture for instance of the Xenon Machine
typedef struct
{
    XenEnv* env;
    XenState state;
    XenErrStatus err;
    char errstr[300];
} XenMachine;



//singleton instance/constructor of xenmachine
XenMachine* XenMachine_Main();

XenState XenMachine_Main_state();

//constructs new instances
XenMachine* XenMachine_new();

static inline void 
XenMachine_state_set(XenMachine* xm, XenState state)
{
    xm->state = state;
}

static inline void
XenMachine_Main_state_set(XenState state)
{
    XenMachine_Main()->state = state;
}


#ifdef __cplusplus
}
#endif

#endif