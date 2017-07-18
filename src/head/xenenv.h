#ifndef XEN_ENV_H
#define XEN_ENV_H

#ifdef __cplusplus
extern "C" {
#endif

//container structure for variable environment
struct XenEnvBox
{
    XenObject* obj;
    struct XenEnvBox* link;
};

typedef struct XenEnvBox XenEnvBox;

#define XenEnvBox_SET_NULL_OL(ec) do {\
                    ec->obj = NULL; \
                    ec->link = NULL;}while(0)
                    
#define XenEnvBox_SET_NULL_O(ec) ec->obj = NULL

#define XenEnvBox_SET_NULL_L(ec) ec->link = NULL

#define XenEnvBox_IS_NULL_O(ec) ec->obj == NULL

#define XenEnvBox_IS_NULL_L(ec) ec->link == NULL

#define XenEnvBox_INIT {NULL, NULL}

void XenEnvBox_del(XenEnvBox* xeb);

#define XenEnv_SIZE 5000

#define XenEnv_LOAD_FACTOR(xenv) xenv->ocount / 5000

typedef struct
{
    XenEnvBox* table;
    int icount; //total items
    int ocount; //buckets occupied
} XenEnv;

XenEnv* XenEnv_new();

//primary hash function for env
unsigned long XenEnv_hash(unsigned char *str);



#ifdef __cplusplus
}
#endif

#endif