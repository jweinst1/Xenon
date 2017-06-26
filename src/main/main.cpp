#include <iostream>

#include "../head/tokenstate.h"

int main(){
    const char code[] = "hello";
    bool g = false;
    bool * gpt = &g;
    tokenState(code, gpt);
    std::cout << *gpt << std::endl;
    return 0;
}