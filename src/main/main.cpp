#include <iostream>

#include "../head/main.h"
#include "../head/tokenstate.h"

int main(){
    std::cout << message <<std::endl;
    const char code[] = "hello";
    bool g = false;
    bool * gpt = &g;
    tokenState(code, gpt);
    std::cout << *gpt << std::endl;
    return 0;
}