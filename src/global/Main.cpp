#include "Lexer.h"
#include "CharSet.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        std::cout << TokenSets::whiteSpace.containsAll("      \t\n");
        std::cout << "f";
        return 0;
}
