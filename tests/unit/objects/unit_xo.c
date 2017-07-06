#include "../../testheaders/test_eq.h"
#include "xen_object.h"


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