#include "Xenon.h"
#include "test_eq.h"

void xb_test_1_new()
{
    XenBool* xbp = XenBool_new(1);
    TEST_IS_TRUE_S(XenBool_IS_TRUE(xbp), "test 1 new");
    free(xbp);
}

void xb_test_2_and()
{
    XenBool* xbp1 = XenBool_new(1);
    XenBool* xbp2 = XenBool_new(1);
    TEST_IS_TRUE_S(XenBool_AND(xbp1, xbp2), "test 2 and");
}

void xb_test_3_or()
{
    XenBool* xbp1 = XenBool_new(1);
    XenBool* xbp2 = XenBool_new(0);
    TEST_IS_TRUE_S(XenBool_OR(xbp1, xbp2), "test 3 or");
}

void xb_test_4_free()
{
    XenBool* xb1 = XenBool_new(1);
    free(xb1);
    TEST_IS_TRUE_S(1, "test 4 free");
}


int main()
{
    xb_test_1_new();
    xb_test_2_and();
    xb_test_3_or();
    xb_test_4_free();
    return 0;
}