#include "vars.h"

extern "C" void VarSet(const char* key, int val)
{
    VARS.insert({key, val});
}

extern "C" int VarGet(const char* key)
{
    auto got = VARS.find(key);
    if(got != VARS.end()) return got->second;
    else return 0;
}