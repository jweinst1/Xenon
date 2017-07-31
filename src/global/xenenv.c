#include "Xenon.h"



XenEnvBox* XenEnvBox_new(char* key, XenObject* xo)
{
    XenEnvBox* xeb = malloc(sizeof(XenEnvBox));
    xeb->key = malloc(strlen(key));
    strcpy(xeb->key, key);
    xeb->obj = xo;
    xeb->link = NULL; 
    return xeb;
}

//once a hash slot is found, either chains or inserts the pair into this box
void XenEnvBox_add_obj(XenEnvBox* xeb, char* key, XenObject* xo)
{
    if(xeb->obj == NULL)
    {
        xeb->obj = xo;
        xeb->key = key;
    }
    else if(xeb->link == NULL)
    {
        xeb->link = XenEnvBox_new(key, xo);
    }
    else
    {
        while(xeb->link != NULL) xeb = xeb->link;
        xeb->link = XenEnvBox_new(key, xo);
    }
}

//warning, does not delete object pointer, fix needed
void XenEnvBox_del(XenEnvBox* xeb)
{
    if(xeb->key != NULL) free(xeb->key);
    if(xeb->obj != NULL) XenGc_del(xeb->obj);
    if(xeb->link != NULL) XenEnvBox_del(xeb->link);
}

XenEnv* XenEnv_new()
{
    XenEnv* env = malloc(sizeof(XenEnv));
    env->ocount = 0;
    env->icount = 0;
    env->table = malloc(sizeof(XenEnvBox) * XenEnv_SIZE);
    return env;
}

unsigned long
XenEnv_hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;    
}

XenObject* XenEnv_insert(XenEnv* xe, char* key, XenObject* xo)
{
    XenEnvBox* hashslot = (xe->table) + (XenEnv_hash(key) % XenEnv_SIZE);
    XenEnvBox_add_obj(hashslot, key, xo);
    if(XenEnvBox_IS_NULL_O(hashslot)) xe->ocount++;
    xe->icount++;
    return xo;
}

//finds a variable in the table
XenObject* XenEnv_find(XenEnv* xe, char* key)
{
    XenEnvBox* hashslot = (xe->table) + (XenEnv_hash(key) % XenEnv_SIZE);
    while(hashslot != NULL)
    {
        if(strcmp(hashslot->key, key) == 0)
        {
            return hashslot->obj;
        }
        else
        {
            hashslot = hashslot->link;
        }
    }
    //todo: decide if error handling
    return (XenObject*)XenNone_new();
}

//deletes a hashslots data
void XenEnv_del(XenEnv* xe, char* key)
{
    XenEnvBox* hashslot = (xe->table) + (XenEnv_hash(key) % XenEnv_SIZE);
    if(hashslot != NULL)
    {
        if(strcmp(hashslot->key, key) == 0)
        {
            XenEnvBox_del(hashslot);
        }
    }
}