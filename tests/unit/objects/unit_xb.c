#include "Xenon.h"
#include "test_eq.h"

void xb_test_1_new()
{
    XenBool* xbp = XenBool_new(1);
    TEST_IS_TRUE_S(XenBool_IS_FALSE(xbp), "test 1 new");
    free(xbp);
}


int main()
{
    xb_test_1_new();
    return 0;
}