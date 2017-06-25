#include <unordered_map>

#ifndef VARS_HEAD
#define VARS_HEAD



static std::unordered_map<const char*, int> VARS;

extern "C" void VarSet(const char* key, int val);

extern "C" int VarGet(const char* key);

#endif