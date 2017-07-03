#include "stdio.h"
#include "xenon_st_s.h"

void xss_test_1()
{
    XenonStream_s* x = xss_allo_s();
    xss_set_i32(x, 3);
    x->data.i32 == 3 ? printf("TEST xss_test_1 PASSED\n") : printf("TEST xss_test_1 FAILED\n");
}
