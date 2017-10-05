#include "Tokenizer.h"


Tokenizer::Tokenizer(Parser* prs) : _state(TokzState_Base), _parser(prs)
{

}

void Tokenizer::tokenize(char* code)
{
        char* cPnt = code;
        switch(_state)
        {
        case TokzState_Base:
                if(*cPnt == '#') _state = TokzState_Comment;
        }
}
