#ifndef XEN_INT_H
#define XEN_INT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    XenObject_HANDLE
    long value;
} XenInt;

#define XenInt_GET_VAL(xi) xi->value

#define XenInt_SET_VAL(xi, v) xi->value = v

#define XenInt_ABS(xi) abs(xi->value)

#define XenInt_INC_POST(xi) xi->value++

#define XenInt_INC_PRE(xi) ++(xi->value)

#define XenInt_DEC_POST(xi) xi->value--

#define XenInt_DEC_PRE(xi) --(xi->value)

#ifdef __cplusplus
}
#endif

#endif