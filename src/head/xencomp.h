#ifndef XEN_COMP_H
#define XEN_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

//contains comparison functions for reactions

#define XenComp_SAME_INT(xo1, xo2) ((XenInt*)xo1)->value == ((XenInt*)xo2)->value

#define XenComp_SAME_CHAR(xo1, xo2) ((XenChar*)xo1)->value == ((XenChar*)xo2)->value

#define XenComp_SAME_BOOL(xo1, xo2) ((XenBool*)xo1)->state == ((XenBool*)xo2)->state

#define XenComp_SAME_STR(xo1, xo2) strcmp(((XenString*)xo1)->str, ((XenString*)xo2)->str) == 0

int XenComp_eq_rx(XenReaction* xrx1, XenReaction* xrx2);

int XenComp_eq_object(XenObject* xo1, XenObject* xo2);

#ifdef __cplusplus
}
#endif

#endif