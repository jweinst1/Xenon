

#ifndef VAR_ENV_H
#define VAR_ENV_H
#include <unordered_map>
//global env
static std::unordered_map<const char*, void*> GLOBAL_VARS;

extern "C" {
    void GVarsSet(const char* key, void* val);
    void* GVarsGet(const char* key);
    int GVarsContains(const char* key);
    void GVarsDelete(const char* key);
}





#endif