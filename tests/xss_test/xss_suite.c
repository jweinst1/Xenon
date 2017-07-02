#include "stdio.h"
#include "xenon_st_s.h"

void xss_test_1()
{
    XenonStream_s* x = xss_allo_s();
    xss_free_s(x);
    x == NULL ? printf("TEST xss_test_1 PASSED") : printf("TEST xss_test_1 FAILED");
}
