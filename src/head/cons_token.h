#ifndef CONS_TOKEN_H
#define CONS_TOKEN_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    XenType type;
    char* data;
} ConsToken;


#ifdef __cplusplus
}
#endif

#endif