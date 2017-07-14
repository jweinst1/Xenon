#ifndef XEN_REACTION_H
#define XEN_REACTION_H

//reaction file 
/**
 * Reactions are also XenObjects, and allows them to be reordered and changed at runtime
 * This is so reactions that form other reactions etc and be made
 */

#ifdef __cplusplus
extern "C" {
#endif

#define XenReaction_HANDLE XenObject* args;\
                    XenInst instruction; \
                    struct XenReaction* path; \
                    int arg_count;


struct XenReaction
{
    XenObject_HANDLE
    XenReaction_HANDLE
};

typedef struct XenReaction XenReaction;

#define XenReaction_MARK_TYPE(xrx) xrx->type = 3

#define XenReaction_GET_ARGC(xrx) xrx->arg_count

#define XenReaction_CONNECT(xrx1, xrx2) xrx1->path = xrx2

#define XenReaction_GET_ARG(xrx, ind) xrx->args[ind]

#define XenReaction_SET_INST(xrx, ins) xrx->instruction = ins

#ifdef __cplusplus
}
#endif

#endif