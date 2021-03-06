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

#define XoConsToken_DEREF_DATA(xoct, ty) *(ty*)xoct->data

#define XoConsToken_INDEX_DEREF(xoct, ty, ind) ((ty*)xoct->data)[ind]

#define XoConsToken_DEREF_AND_SET(xoct, ty, val) *(ty*)xoct->data = val

#define XoConsToken_DATA_ALLO_SIZE(xoct, size) xoct->data = malloc(size)

#define XoConsToken_DATA_ALLO_TYPE(xoct, ty) xoct->data = malloc(sizeof(ty))

#define XoConsToken_FREE_DATA(xoct) free(xoct->data)

#define XoConsToken_NEW malloc(sizeof(XoConsToken))

//deletes cons token through macro
#define XoConsToken_DELETE(xoct) do { \
                         free(xoct->data); \
                         free(xoct); \
                         xoct = NULL;}while(0)
                         

XoConsToken* XoConsToken_from_void(XenType type, void* data);

XoConsToken* XoConsToken_from_bool(const unsigned char state);

XoConsToken* XoConsToken_from_char(const char ch);

XenObject* XoConsToken_cons_obj(XoConsToken* xoct);






#ifdef __cplusplus
}
#endif

#endif