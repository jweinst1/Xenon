#include <string>
#include <vector>
#include "../head/tokenizer.h"
#include <cctype>

void Tokenizer::classifyChar(const char* inputc, int* code)
{
    switch(*code)
    {
        case 0:
            if(isspace(*inputc));
            else if(isalpha(*inputc)) *code = 1;
            else if(isdigit(*inputc)) *code = 2;
            else switch(*inputc)
            {
                case '"': *code = 3; break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%': *code = 4; break;
                case '{': *code = 5; break;
                
            }
            break;
    }
}

std::vector<std::string> Tokenizer::tokenize(const char * input)
{
    std::vector<std::string> tokens;
    int mode = 0;
    while(*input)
    {
        switch(mode)
        {
            case 0:
                if(isspace(*input)) input++;
                else if(isalpha(*input))
                {
                    mode = 1;
                    input++;
                }
                else if(isdigit(*input))
                {
                    mode = 2;
                    input++;
                }
                else switch(*input)
                {
                    case '"':
                        mode = 3;
                        input++;
                        break;
                }
                break;
            case 1:
                
                break;
        }
    }
}