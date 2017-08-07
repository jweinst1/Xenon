#include "Xenon.h"

//name is capitalized for singleton constructor
XenMachine* XenMachine_Main()
{
    static XenMachine XenMachine_MAIN = {};
    static int init = 0;
    if(init)
    {
        return &XenMachine_MAIN;
    }
    else
    {
        XenMachine_MAIN.env = XenEnv_new();
        XenMachine_MAIN.state = XenState_Start;
        XenMachine_MAIN.err = XenErrStatus_Off;
        init = 1;
        return &XenMachine_MAIN;
    }
}

//gets state of main machine
XenState XenMachine_Main_state()
{
    return XenMachine_Main()->state;
}

//constructor for new, heap allocated machine instances
XenMachine* XenMachine_new()
{
    XenMachine* xem = malloc(sizeof(XenMachine));
    xem->env = XenEnv_new();
    xem->state = XenState_Start;
    xem->err = XenErrStatus_Off;
    return xem;
}