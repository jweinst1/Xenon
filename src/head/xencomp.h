#ifndef XEN_COMP_H
#define XEN_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

//contains comparison functions for reactions

#define XenComp_SAME_INT(xo1, xo2) ((XenInt*)xo1)->value == ((XenInt*)xo2)->value

int XenComp_eq_object(XenObject* xo1, XenObjext* xo2);

#ifdef __cplusplus
}
#endif

#endif