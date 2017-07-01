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
    XenonStream_s* xss = (XenonStream_s*)malloc(sizeof(XenonStream_s));
    xss->next = NULL;
    return xss;
}

//frees one instance of xss
inline void xss_free_s(XenonStream_s* xss)
{
    free(xss);
}

//pushes back one stream_s value
inline XenonStream_s* xss_push(XenonStream_s* xss)
{
    XenonStream_s* newxss = xss_allo_s();
    newxss->next = xss;
    return newxss;
}

//connects 2 single streams
inline void xss_connect(XenonStream_s* xss1, XenonStream_s* xss2)
{
    xss1->next = xss2;
}

//gets type
inline unsigned char xss_type(XenonStream_s* xss)
{
    return xss->type;
}

inline int xss_next_null(XenonStream_s* xss)
{
    return xss->next == NULL;
}

/*SET GET functions*/

inline void xss_set_char(XenonStream_s* xss, const char ch)
{
    xss->type = 0;
    xss->data.i8 = ch;
}



#endif