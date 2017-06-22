#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

namespace Tokenizer
{
    //gives code to determine tokenizer state
    void classifyChar(const char* inputc, int* code);
    
    std::vector<std::string> tokenize(const char * input);
}

#endif