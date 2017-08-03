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
    if(xeb->key == NULL)
    {
        xeb->obj = xo;
        xeb->key = malloc(strlen(key));
        strcpy(xeb->key, key);
    }
    else 
    {
        if(XenEnvBox_KEY_CMP(key, xeb->key))
        {
            xeb->obj = xo;
            return;
        }
        while(xeb->link != NULL)
        {
            xeb = xeb->link;
            //checks if name is reassigned, and changes XenObject pointer
            if(XenEnvBox_KEY_CMP(key, xeb->key))
            {
                xeb->obj = xo;
                return;
            }
        }
        //creates new chain link if space occupied
        xeb->link = XenEnvBox_new(key, xo);
    }
}


//deletes entire xenenvbox
void XenEnvBox_del(XenEnvBox* xeb)
{
    if(xeb->key != NULL) free(xeb->key);
    if(xeb->obj != NULL) XenGc_del(xeb->obj);
    if(xeb->link != NULL) XenEnvBox_del(xeb->link);
    free(xeb);
}

XenEnv* XenEnv_new()
{
    XenEnv* env = malloc(sizeof(XenEnv));
    env->ocount = 0;
    env->icount = 0;
    env->size = XenEnv_SIZE;
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
    XenEnvBox* hashslot = (xe->table) + (XenEnv_hash(key) % xe->size);
    if(XenEnvBox_IS_NULL_O(hashslot)) xe->ocount++;
    XenEnvBox_add_obj(hashslot, key, xo);
    xe->icount++;
    return xo;
}

//finds a variable in the table
XenObject* XenEnv_find(XenEnv* xe, char* key)
{
    XenEnvBox* hashslot = (xe->table) + (XenEnv_hash(key) % xe->size);
    while(hashslot != NULL)
    {
        if(XenEnvBox_KEY_CMP(key, hashslot->key))
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

//deletes a hashslots data and key
void XenEnv_del(XenEnv* xe, char* key)
{
    XenEnvBox* hashslot = (xe->table) + (XenEnv_hash(key) % xe->size);
    if(XenEnvBox_KEY_CMP(key, hashslot->key))
    {
        free(hashslot->key);
        hashslot->key = NULL;
        XenGc_del(hashslot->obj);
        hashslot->obj = NULL;
        xe->ocount--;
        xe->icount--;
    }
    //works off the link incase of downstream chain items
    else while(hashslot->link != NULL)
    {
        if(XenEnvBox_KEY_CMP(key, hashslot->link->key))
        {
            if(hashslot->link->key != NULL) free(hashslot->link->key);
            if(hashslot->link->obj != NULL) XenGc_del(hashslot->link->obj);
            free(hashslot->link);
            xe->icount--;
            hashslot->link = hashslot->link->link;
        }
        hashslot = hashslot->link;
    }
}

//expands the variable table size
void XenEnv_expand(XenEnv* xe)
{
    xe->size += xe->size;
    xe->table = realloc(xe->table, sizeof(XenEnvBox) * xe->size);
}