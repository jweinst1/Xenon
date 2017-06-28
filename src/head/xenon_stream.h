#ifndef XENON_STREAM_H
#define XENON_STREAM_H

//standard size stream block
struct XenonStream
{
    void* data[10];
    int len[10];
    unsigned short type[10];
    struct XenonStream* next;
};

//typedef for easier type naming
typedef struct XenonStream XenonStream;



//larger sized data blocks
struct XenonStreamLg
{
    void* data[50];
    int len[50];
    unsigned short type[50];
    struct XenonStreamLg* next;
};

//typedef for easier type naming
typedef struct XenonStreamLg XenonStreamLg;

#endif