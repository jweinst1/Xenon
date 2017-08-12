#ifndef XEN_STATEMENT_TOKEN_H
#define XEN_STATEMENT_TOKEN_H

#ifdef __cplusplus
extern "C" {
#endif

//types of xen tokens to be used
typedef enum
{
    XenTokenType_Assign,
    XenTokenType_Map,
    XenTokenType_Filter
} XenTokenType;

//tokens consumed by machine to facilitate computation
//allows them to be freely cast from one to another

#define XenToken_HANDLE XenTokenType type; \
                XenObject* buf;

typedef struct
{
    XenToken_HANDLE
} XenToken;

#define XenToken_GET_TYPE(xt) xt->type


#ifdef __cplusplus
}
#endif

#endif