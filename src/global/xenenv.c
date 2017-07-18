#include "Xenon.h"

XenEnv* XenEnv_new()
{
    XenEnv* env = malloc(sizeof(XenEnv));
    env->ocount = 0;
    env->icount = 0;
    env->table = malloc(sizeof(XenEnvBox) * XenEnv_SIZE);
    return env;
}

//warning, does not delete object pointer
void XenEnvBox_del(XenEnvBox* xeb)
{
    if(XenEnvBox_IS_NULL_L(xeb))free(xeb->link);
    free(xeb);
}

unsigned long XenEnv_hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;    
}