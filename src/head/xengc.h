#ifndef XEN_GARBAGE_COLLECTION_H
#define XEN_GARBAGE_COLLECTION_H

//gc manager for Xenon

#ifdef __cplusplus
extern "C" {
#endif

void XenGc_del_reaction(XenReaction* xrx);

void XenGc_del_string(XenString* xs);

void XenGc_del_one(XenObject* xo);

void XenGc_del(XenObject* xo);

#ifdef __cplusplus
}
#endif

#endif