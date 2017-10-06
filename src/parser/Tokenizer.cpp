#include "Tokenizer.h"
#include "Lexer.h"


Tokenizer::Tokenizer(Parser* prs) : _state(TokzState_Base),
        _parser(prs),
        _curEvent(XenEventType_null)
{

}

void Tokenizer::tokenize(char* code)
{
        char* cPnt = code;
        while (*cPnt)
        {
                switch(_state)
                {
                case TokzState_Base:
                        if(TokenSets::eventName.contains(*cPnt))
                        {
                                Lexer::eventType(cPnt, &_curEvent, &cPnt);
                                if(_curEvent)
                                {
                                        //_parser->parse()
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
