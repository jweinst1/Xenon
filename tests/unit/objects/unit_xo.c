#include "../../testheaders/test_eq.h"
#include "xen_object.h"


//unit tests for xenon object

void xo_test_settype()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject_SET_TYPE(one, 5);
    TEST_IS_EQUAL_N(XenObject_GET_TYPE(one), 5, 1);
    free(one);
}