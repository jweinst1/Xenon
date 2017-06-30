//file for declaring xenon values
#ifndef XENON_DEF_H
#define XENON_DEF_H

#include "allocator.h"

//dynamic formulated union for different types of integers
typedef union
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
} XenonValue;

//dynamic based stream

struct XenonStream_d
{
    unsigned char type[10];
    XenonValue data[10];
    struct XenonStream_d* next;
};

typedef struct XenonStream_d XenonStream_d;

//larger sized block for bigger data streams
struct XenonStream_dl
{
    unsigned char type[50];
    XenonValue data[50];
    struct XenonStream_dl* next;
};

typedef struct XenonStream_dl XenonStream_dl;


//single data block for small operations
struct XenonStream_ds
{
    unsigned char type;
    XenonValue data;
    struct XenonStream_ds* next;
};

typedef struct XenonStream_ds XenonStream_ds;




//typed string stream block
struct XenonStream_s
{
    char data[20];
    struct XenonStream_s* next;
};

typedef struct XenonStream_s XenonStream_s;


#endif