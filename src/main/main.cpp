#include <iostream>
#include <vector>
#include <string>
#include "../head/main.h"
#include "../head/tokenizer.h"

int main(){
    std::cout << message <<std::endl;
    std::vector<std::string> j = Tokenizer::tokenize("hello sir");
    std::cout << j[0] << std::endl;
    return 0;
}