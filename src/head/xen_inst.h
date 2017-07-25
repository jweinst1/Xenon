#ifndef XEN_INST_H
#define XEN_INST_H

//handles fundamental operations during reactions

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    XenInst_Add,
    XenInst_Sub,
    XenInst_Mul,
    XenInst_Div,
    XenInst_Rem,
    XenInst_Abs,
    XenInst_Inc,
    XenInst_Dec
} XenInst;

#define XenInst_TO_INT(xins) (int)xins

#define XenInst_TO_BYTE(xins) (unsigned char)xins


#ifdef __cplusplus
}
#endif

#endif