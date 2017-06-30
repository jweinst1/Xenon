#include "../head/allocator.h"

//keeps track of storage of xs_d
int allo_stat_xs_d_c(int ad)
{
    static int STOR_C = 0;
    STOR_C += ad;
    return STOR_C < 1000;
}


XenonStream_d* allo_stat_xs_d_s()
{
    static XenonStream_d STATIC_STORAGE_D[1000];
    static int STORAGE_CURR = -1;
    allo_stat_xs_d_c(1);
    return STATIC_STORAGE_D + (STORAGE_CURR++);
}

//basic allocation functions

void* allo_of_block(size_t block, const int amount)
{
    return malloc(block * amount);
}

void* allo_of_code(char code, const int amount)
{
    switch(code)
    {
        case 'c': return malloc(sizeof(char) * amount);
        case 'i': return malloc(sizeof(int) * amount);
        case 'u': return malloc(sizeof(unsigned int) * amount);
        case 's': return malloc(sizeof(short) * amount);
        default: return NULL;
    }
}

void* allo_of_size(size_t block)
{
    return malloc(block);
}


//_s is a single spaces
//_m is multiple spaces or [array]

//s means single

XenonStream_d* allo_xs_d_s()
{
    return (XenonStream_d*)malloc(sizeof(XenonStream_d));
}

//single allocation of large stream
XenonStream_dl* allo_xs_dl_s()
{
    return (XenonStream_dl*)malloc(sizeof(XenonStream_dl));
}



//basic deallocation

void allo_delete(void* pnt)
{
    free(pnt);
}

void allo_del_xs_d(XenonStream_d* xs)
{
    free(xs);
}

void allo_del_xs_dl(XenonStream_dl* xs)
{
    free(xs);
}