#ifndef XO_CONSTRUCTION_H
#define XO_CONSTRUCTION_H

//structure to deal with construction of XenObjects

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    XenType type;
    void* data;
} XoConsToken;

#define XoConsToken_GET_TYPE(xoct) xoct->type

#define XoConsToken_CAST_TYPE(xoct, ty) (ty*)xoct->data

#define XoConsToken_DEREF_TYPE(xoct, ty) *(ty*)xoct->data

#define XoConsToken_INDEX_DEREF(xoct, ty, ind) ((ty*)xoct->data)[ind]

#define XoConsToken_DEREF_AND_SET(xoct, ty, val) *(ty*)xoct->data = val

#define XoConsToken_DATA_ALLO_SIZE(xoct, size) xoct->data = malloc(size)

#define XoConsToken_DATA_ALLO_TYPE(xoct, ty) xoct->data = malloc(sizeof(ty))

#define XoConsToken_FREE_DATA(xoct) free(xoct->data)

#define XoConsToken_NEW malloc(sizeof(XoConsToken))




#ifdef __cplusplus
}
#endif

#endif