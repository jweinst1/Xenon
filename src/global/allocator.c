#include "../head/allocator.h"

//basic allocation functions

void* allo_of_block(size_t block, int amount)
{
    return malloc(block * amount);
}

void* allo_of_code(char code, int amount)
{
    switch(code)
    {
        case 'c': return malloc(sizeof(char) * amount);
        case 'i': return malloc(sizeof(int) * amount);
        default: return NULL;
    }
}

void* allo_of_size(size_t block)
{
    return malloc(block);
}

//specialized allocators
//_s is a single spaces
//_m is multiple spaces or [array]

int* allo_int_s()
{
    return (int*)malloc(4);
}

int* allo_int_m(int amount)
{
    return (int*)malloc(4 * amount);
}

char* allo_char_s()
{
    return (char*)malloc(1);
}

char* allo_char_m(int amount)
{
    return (char*)malloc(1*amount);
}

//basic deallocation

void allo_delete(void* pnt)
{
    free(pnt);
}