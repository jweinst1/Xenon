#include <iostream>
#include <string>

#include "Lexer.h"
#include "CharSet.h"
#include "Tokenizer.h"


int main(int argc, char const *argv[]) {
        Parser machine;
        Tokenizer toks(&machine);
        std::string code = "in #hello sir\n 5 | ++ 5| out 3";
        code += '|';
        toks.tokenize(const_cast<char*>(code.c_str()));
        return 0;
}
