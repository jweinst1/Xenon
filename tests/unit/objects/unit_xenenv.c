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

void xenenv_test_3_stress_insert_find()
{
    XenEnv* xe = XenEnv_new();
    XenObject* xo = (XenObject*)XenBool_new(1);
    char* k = "hello sir";
    XenEnv_insert(xe,"hello sir",xo);
    XenEnv_insert(xe,"hello dddir",xo);
    XenEnv_insert(xe,"hehhhhho sir",xo);
    XenEnv_insert(xe,"hell3333o sir",xo);
    XenEnv_insert(xe,"apple",xo);
    XenEnv_insert(xe,"hefffdddddsir",xo);
    XenEnv_insert(xe,"hesahghadgfhgir",xo);
    XenEnv_insert(xe,"bansbans",xo);
    XenEnv_insert(xe,"bans",xo);
    XenEnv_insert(xe,"bagggs",xo);
    XenObject* x = XenEnv_find(xe, k);
    TEST_IS_EQUAL_S(x, xo, "test 3 xenenv stress insert find");
    printf("The occupied and item count are: %d, %d\n", xe->ocount, xe->icount);
}

void xenenv_test_4_re_insert()
{
    XenEnv* xe = XenEnv_new();
    XenObject* xo = (XenObject*)XenBool_new(1);
    XenObject* xo2 = (XenObject*)XenBool_new(0);
    XenEnv_insert(xe,"hello sir",xo);
    XenEnv_insert(xe,"hello sir",xo2);
    TEST_IS_EQUAL_S(XenEnv_find(xe, "hello sir"), xo2, "test4 xenenv reinsert");
}


int main()
{
    xenenv_test_1_insert_find();
    xenenv_test_2_insert_del();
    xenenv_test_3_stress_insert_find();
    xenenv_test_4_re_insert();
    return 0;
}