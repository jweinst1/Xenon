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

//frees and sets to null.
inline void xss_freen_s(XenonStream_s* xss)
{
    free(xss);
    xss = NULL;
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

//bools

inline int xss_next_null(XenonStream_s* xss)
{
    return xss->next == NULL;
}

inline int xss_check_type(XenonStream_s* xss, unsigned char ch)
{
    return xss->type == ch;
}

/*SET GET functions*/

//sets type
inline void xss_set_type(XenonStream_s* xss, unsigned char ch)
{
    xss->type = ch;
}

inline void xss_set_i8(XenonStream_s* xss, const char ch)
{
    xss->type = 0;
    xss->data.i8 = ch;
}

inline void xss_set_i16(XenonStream_s* xss, const short ch)
{
    xss->type = 1;
    xss->data.i16 = ch;
}

inline void xss_set_i32(XenonStream_s* xss, const int ch)
{
    xss->type = 2;
    xss->data.i32 = ch;
}

inline void xss_set_i64(XenonStream_s* xss, const long ch)
{
    xss->type = 3;
    xss->data.i64 = ch;
}

inline void xss_set_u8(XenonStream_s* xss, unsigned char ch)
{
    xss->type = 4;
    xss->data.u8 = ch;
}

inline void xss_set_u16(XenonStream_s* xss, unsigned short ch)
{
    xss->type = 5;
    xss->data.u16 = ch;
}

inline void xss_set_u32(XenonStream_s* xss, unsigned int ch)
{
    xss->type = 6;
    xss->data.u32 = ch;
}

inline void xss_set_u64(XenonStream_s* xss, unsigned long ch)
{
    xss->type = 7;
    xss->data.u64 = ch;
}

inline void xss_set_d(XenonStream_s* xss, const double ch)
{
    xss->type = 8;
    xss->data.d = ch;
}

inline void xss_set_f(XenonStream_s* xss, const float ch)
{
    xss->type = 9;
    xss->data.f = ch;
}

inline char xss_get_i8(XenonStream_s* xss)
{
    return xss->data.i8;
}

inline short xss_get_i16(XenonStream_s* xss)
{
    return xss->data.i16;
}

inline int xss_get_i32(XenonStream_s* xss)
{
    return xss->data.i32;
}

inline long xss_get_i64(XenonStream_s* xss)
{
    return xss->data.i64;
}

inline unsigned char xss_get_u8(XenonStream_s* xss)
{
    return xss->data.u8;
}

inline unsigned short xss_get_u16(XenonStream_s* xss)
{
    return xss->data.u16;
}

inline unsigned int xss_get_u32(XenonStream_s* xss)
{
    return xss->data.u32;
}

inline unsigned long xss_get_u64(XenonStream_s* xss)
{
    return xss->data.u64;
}

inline float xss_get_f(XenonStream_s* xss)
{
    return xss->data.f;
}

inline double xss_get_d(XenonStream_s* xss)
{
    return xss->data.d;
}

//comparisons

inline int xss_eq_type(XenonStream_s* xss1, XenonStream_s* xss2)
{
    return xss1->type == xss2->type;
}


#endif