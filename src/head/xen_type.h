#ifndef XEN_TYPE_H
#define XEN_TYPE_H

//xentypes keep track of Object types over raw integers

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    XenType_Bool,
    XenType_Char,
    XenType_Reaction,
    XenType_Int,
    XenType_String
} XenType;

#define XenType_TO_INT(xtyp) (int)xtyp

#define XenType_TO_BYTE(xtyp) (unsigned char)xtyp

#ifdef __cplusplus
}
#endif

#endif