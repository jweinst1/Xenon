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
    //env needed
    XenState state;
} XenMachine;

#ifdef __cplusplus
}
#endif

#endif