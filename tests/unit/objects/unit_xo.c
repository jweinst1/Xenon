#include "xen_object.h"
#include "test_eq.h"


//unit tests for xenon object

void xo_test_1_settype()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject_SET_TYPE(one, 5);
    TEST_IS_EQUAL_N(XenObject_GET_TYPE(one), 5, 1);
    free(one);
}

void xo_test_2_sametype()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = malloc(sizeof(XenObject));
    XenObject_SET_TYPE(one, 5);
    XenObject_SET_TYPE(two, 5);
    TEST_IS_TRUE_N(XenObject_SAME_TYPE(one, two), 2);
    free(one); free(two);
}

void xo_test_3_connectnext()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = malloc(sizeof(XenObject));
    XenObject_CONNECT_NEXT(one, two);
    TEST_IS_TRUE_N(XenObject_SAME_PNT(two, one->next), 3);
    free(one); free(two);
}

void xo_test_4_insertnext()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = malloc(sizeof(XenObject));
    XenObject* three = malloc(sizeof(XenObject));
    XenObject_CONNECT_NEXT(one, two);
    XenObject_insert_next(one, three);
    TEST_IS_TRUE_N(XenObject_SAME_PNT(three, one->next), 4);
    free(one); free(two); free(three);
}