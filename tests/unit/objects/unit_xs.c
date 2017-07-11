#include "Xenon.h"
#include "test_eq.h"

void xs_test_1_append()
{
    XenStream* xs = XenStream_new();
    XenBool* xb1 = XenBool_new(1);
    XenBool* xb2 = XenBool_new(1);
    XenBool* xb3 = XenBool_new(0);
    XenStream_append(xs, (XenObject*)xb1);
    XenStream_append(xs, (XenObject*)xb2);
    XenStream_append(xs, (XenObject*)xb3);
    TEST_IS_EQUAL_S((XenObject*)xb3, xs->back, "test 1 append");
    free(xb1); free(xb2); free(xb3); free(xs);
}


int main()
{
    xs_test_1_append();
    return 0;
}