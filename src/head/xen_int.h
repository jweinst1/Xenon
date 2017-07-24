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

#define XenInt_MARK_TYPE(xi) xi->type = XenType_Int

//macro for getting int and casting from xenobject
#define XenInt_GET_INT(xo) ((XenInt*)xo)->value

#define XenInt_IS_INT(xo) xo->type == XenType_Int

#define XenInt_ABS(xi) abs(xi->value)

#define XenInt_INC_POST(xi) xi->value++

#define XenInt_INC_PRE(xi) ++(xi->value)

#define XenInt_DEC_POST(xi) xi->value--

#define XenInt_DEC_PRE(xi) --(xi->value)

#define XenInt_ADD_OBJ(xi1, xi2) xi1->value += xi2->value

#define XenInt_ADD_INT(xi, i) xi->value += i

#define XenInt_SUB_OBJ(xi1, xi2) xi1->value -= xi2->value

#define XenInt_SUB_INT(xi, i) xi->value -= i

XenInt* XenInt_new(long value);

#ifdef __cplusplus
}
#endif

#endif