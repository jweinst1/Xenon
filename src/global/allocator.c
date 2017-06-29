#include "../head/allocator.h"
#include "../head/xenon_def.h"

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

//specialized allocators
//_s is a single spaces
//_m is multiple spaces or [array]

int* allo_int_s()
{
    return (int*)malloc(4);
}

int* allo_int_m(const int amount)
{
    return (int*)malloc(4 * amount);
}

char* allo_char_s()
{
    return (char*)malloc(1);
}

char* allo_char_m(const int amount)
{
    return (char*)malloc(1*amount);
}

unsigned int* allo_uint_s()
{
    return (unsigned int*)malloc(4);
}

unsigned int* allo_uint_m(const int amount)
{
    return (unsigned int*)malloc(4 * amount);
}

short* allo_short_s()
{
    return (short*)malloc(2);
}

short* allo_short_m(const int amount)
{
    return (short*)malloc(2 * amount);
}

bool* allo_bool_s()
{
    return (bool*)malloc(sizeof(bool));
}

bool* allo_bool_m(const int amount)
{
    return (bool*)malloc(sizeof(bool) * amount);
}

//basic deallocation

void allo_delete(void* pnt)
{
    free(pnt);
}