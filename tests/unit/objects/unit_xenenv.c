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


int main()
{
    xenenv_test_1_insert_find();
    return 0;
}