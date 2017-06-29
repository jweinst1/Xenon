#include <stdio.h>
#include "../src/head/allocator.h"

int main()
{
    int i;
    for(i=0;i<1000;i++) printf("static cache is open: %d\n", allo_stat_xs_d_c(1));
    return 0;
}