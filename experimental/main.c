#include <stdio.h>
#include "vars.h"

int main(){
    VarSet("hello", 3);
    printf("finished the set\n");
    printf("the value is %d\n", VarGet("hello"));
    return 0;
}