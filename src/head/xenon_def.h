//file for declaring xenon values
#ifndef XENON_DEF_H
#define XENON_DEF_H

//dynamic formulated union
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

typedef struct
{
    unsigned char types[10];
    XenonValue data[10];
} XenonStream_d;

typedef struct
{
    unsigned char types[50];
    XenonValue data[50];
} XenonStream_dl;


//typed integer stream
typedef struct
{
    int data[10];
} XenonStream_i;


#endif