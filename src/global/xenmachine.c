#include "Xenon.h"

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
