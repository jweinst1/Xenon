#include "Tokenizer.h"
#include "Lexer.h"


Tokenizer::Tokenizer(Parser* prs) : _state(TokzState_Base), _parser(prs)
{

}

void Tokenizer::tokenize(char* code)
{
        char* cPnt = code;
        XenEventType* tokenEvent = nullptr;
        while (*cPnt)
        {
                switch(_state)
                {
                case TokzState_Base:
                        if(TokenSets::eventName.contains(*cPnt))
                        {
                                Lexer::eventType(cPnt, tokenEvent, &cPnt);
                                if(tokenEvent)
                                {

                                }
                        }
                        else if(*cPnt == '#')
                        {
                                _state = TokzState_Comment;
                                cPnt++;
                        }
                case TokzState_Comment:
                        if(*cPnt == '\n')
                        {
                                _state = TokzState_Base;
                                cPnt++;
                        }
                }
        }
}
