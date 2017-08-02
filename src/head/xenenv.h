#ifndef XEN_ENV_H
#define XEN_ENV_H

#ifdef __cplusplus
extern "C" {
#endif

//container structure for variable environment
struct XenEnvBox
{
    char* key;
    XenObject* obj;
    struct XenEnvBox* link;
};

typedef struct XenEnvBox XenEnvBox;

#define XenEnvBox_SET_NULL_OL(xeb) do {\
                    xeb->obj = NULL; \
                    xeb->key = NULL; \
                    xeb->link = NULL;}while(0)
                    
#define XenEnvBox_SET_NULL_O(xeb) xeb->obj = NULL

#define XenEnvBox_SET_NULL_L(xeb) xeb->link = NULL 

#define XenEnvBox_IS_NULL_O(xeb) xeb->obj == NULL

#define XenEnvBox_IS_NULL_L(xeb) xeb->link == NULL

#define XenEnvBox_FIND_EMPTY(xeb) while(xeb->link != NULL) xeb = xeb->link

#define XenEnvBox_KEY_CMP(key, hskey) hskey != NULL && (strcmp(key, hskey) == 0)

XenEnvBox* XenEnvBox_new(char* key, XenObject* xo);

void XenEnvBox_set_null(XenEnvBox* xeb);

void XenEnvBox_add_obj(XenEnvBox* xeb, char* key, XenObject* xo);

void XenEnvBox_del(XenEnvBox* xeb);

#define XenEnv_SIZE 5000

#define XenEnv_LOAD_FACTOR(xenv) xenv->ocount / 5000



typedef struct
{
    XenEnvBox* table;
    int size; //current size
    int icount; //total items
    int ocount; //buckets occupied
} XenEnv;

XenEnv* XenEnv_new();

//primary hash function for env
unsigned long XenEnv_hash(char *str);

XenObject* XenEnv_insert(XenEnv* xe, char* key, XenObject* xo);

XenObject* XenEnv_find(XenEnv* xe, char* key);

void XenEnv_del(XenEnv* xe, char* key);

void XenEnv_expand(XenEnv* xe);



#ifdef __cplusplus
}
#endif

#endif