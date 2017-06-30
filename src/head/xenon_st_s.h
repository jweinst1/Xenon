#ifndef XENON_STREAM_SMALL_H
#define XENON_STREAM_SMALL_H

#include <stdlib.h>

//small stream implementation
//only contains single slot of data

struct XenonStream_s
{
    union
    {
        char i8;
        short i16;
        int i32;
        long i64;
        float f;
        double d;
        
        unsigned char u8;
        unsigned short u16;
        unsigned int u32;
        unsigned long u64;    
    } data;
    unsigned char type;
    struct XenonStream_s* next;
};

typedef struct  XenonStream_s XenonStream_s;

//allocates on instance of xss
inline XenonStream_s* xss_allo_s()
{
    return (XenonStream_s*)malloc(sizeof(XenonStream_s));
}

//frees one instance of xss
inline void xss_free_s(XenonStream_s* xss)
{
    free(xss);
}

#endif