#ifndef XEN_STATEMENT_TOKEN_H
#define XEN_STATEMENT_TOKEN_H

#ifdef __cplusplus
extern "C" {
#endif

//tokens consumed by machine to facilitate computation
//allows them to be freely cast from one to another

#define XenToken_HANDLE XenTokenType type;

typedef struct
{
    XenToken_HANDLE
} XenToken;


#ifdef __cplusplus
}
#endif

#endif