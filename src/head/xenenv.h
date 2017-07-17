#ifndef XEN_ENV_H
#define XEN_ENV_H

#ifdef __cplusplus
extern "C" {
#endif

//container structure for variable environment
struct EnvContainer
{
    XenObject* obj;
    struct EnvContainer* link;
};

typedef struct EnvContainer EnvContainer;

#define EnvContainer_SET_NULL_OL(ec) do {\
                    ec->obj = NULL; \
                    ec->link = NULL;}while(0)
                    
#define EnvContainer_SET_NULL_O(ec) ec->obj = NULL

#define EnvContainer_SET_NULL_L(ec) ec->link = NULL

#define EnvContainer_IS_NULL_O(ec) ec->obj == NULL

#define EnvContainer_IS_NULL_L(ec) ec->link == NULL

#define EnvContainer_INIT {NULL, NULL}

typedef struct
{
    EnvContainer* table;
    long osize;
} XenEnv;



#ifdef __cplusplus
}
#endif

#endif