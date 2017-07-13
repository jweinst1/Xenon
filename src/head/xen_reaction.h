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



#ifdef __cplusplus
}
#endif

#endif