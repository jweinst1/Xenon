#ifndef XEN_OPERATION_H
#define XEN_OPERATION_H

//operation file 
/**
 * Operations are also XenObjects, and allows them to be reordered and changed at runtime
 * This is so reactions that form other reactions etc and be made
 */

#ifdef __cplusplus
extern "C" {
#endif

#define XenOperation_HANDLE XenInst instruction; \
                      XenObject* operands; \
                      int op_count;


typedef struct
{
    XenObject_HANDLE
    XenOperation_HANDLE
} XenOperation;

#define XenOperation_MARK_TYPE(xop) xop->type = 3



#ifdef __cplusplus
}
#endif

#endif