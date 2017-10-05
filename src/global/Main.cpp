#include "Lexer.h"
#include "CharSet.h"
#include "Token.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        std::cout << TokenSets::whiteSpace.containsAll("      \t\n");
        Token h = Token::make(6);
        std::cout << "\n" << h.number;
        return 0;
}
