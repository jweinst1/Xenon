#include <stdio.h>
#include "../src/head/xenon_st_s.h"

int main()
{
    XenonStream_s* g = xss_allo_s();
    g->type = 3;
    printf("the type is %d", g->type);
    return 0;
}