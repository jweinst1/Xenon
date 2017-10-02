#include "CharSet.h"

CharSet::CharSet(const char* chlst)
{
        while(*chlst)
        {
                _chars[(unsigned char)*chlst++] = true;
        }
}

bool CharSet::containsAll(const char* chlst)
{
        while(*chlst)
        {
                if(!contains(*chlst++)) return false;
        }
        return true;
}
