#include <cstdlib>
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
                                        Token::pntMake(&_inst, _curEvent);
                                        _parser->parse(_inst);
                                }
                        }
                        else if(TokenSets::numberStart.contains(*cPnt))
                        {
                                if(Lexer::isZero(cPnt))
                                {
                                        Token::pntMake(&_inst, 0);
                                        _parser->parse(_inst);
                                }
                                else if((_number = std::strtod(cPnt, &cPnt)))
                                {
                                        Token::pntMake(&_inst, _number);
                                        _parser->parse(_inst);
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
