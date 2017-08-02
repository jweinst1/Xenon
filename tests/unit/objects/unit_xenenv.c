#include "Xenon.h"
#include "test_eq.h"

//reaction unit tests

void xenenv_test_1_insert_find()
{
    XenEnv* xe = XenEnv_new();
    XenObject* xo = (XenObject*)XenBool_new(1);
    char* k = "hello sir";
    XenEnv_insert(xe,"hello sir",xo);
    TEST_IS_EQUAL_S(XenEnv_find(xe, k), xo, "test 1 xenenv insert find");
}

void xenenv_test_2_insert_del()
{
    XenEnv* xe = XenEnv_new();
    XenObject* xo = (XenObject*)XenBool_new(1);
    char* k = "hello sir";
    XenEnv_insert(xe,"hello sir",xo);
    XenEnv_del(xe, "hello sir");
    XenObject* x = XenEnv_find(xe, k);
    TEST_IS_EQUAL_S(x->type, XenType_None, "test 2 xenenv insert del");   
}


int main()
{
    xenenv_test_1_insert_find();
    xenenv_test_2_insert_del();
    return 0;
}