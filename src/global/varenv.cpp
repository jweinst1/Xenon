#include "../head/varenv.h"

//sets a new variable
extern "C" void GVarsSet(const char* key, void* val)
{
     GLOBAL_VARS.insert({key, val});
}

extern "C" void* GVarGet(const char* key)
{
    auto got = GLOBAL_VARS.find(key);
    if(got != GLOBAL_VARS.end()) return got->second;
    //needs exception thrown
}

extern "C" int GVarsContains(const char* key)
{
    return GLOBAL_VARS.find(key) != GLOBAL_VARS.end();
}

extern "C" void GVarsDelete(const char* key)
{
    GLOBAL_VARS.erase(key);
}