#include <cstdlib>
#include "Tokenizer.h"
#include "Lexer.h"
#include "XenError.h"



Tokenizer::Tokenizer(Parser* prs) : _state(TokzState_Base),
        _prevState(TokzState_Base),
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
                                        _state = TokzState_Event;
                                }
                                else throw XenError("Incorrect Event Name at: %d, eventisNull: %d", *cPnt, _curEvent == XenEventType_null);
                        }
                        else if(*cPnt == '#')
                        {
                                _state = TokzState_Comment;
                                _prevState = TokzState_Base;
                                cPnt++;
                        }
                        else if(Lexer::isNotWSpace(cPnt)) throw XenError("Incorrect Char: %c, eventisNull: %d", *cPnt, _curEvent == XenEventType_null);
                        else cPnt++;
                        break;
                case TokzState_Event:
                        if(*cPnt == '|')
                        {
                                Token::endMake(&_inst);
                                _parser->parse(_inst);
                                _state = TokzState_Base;
                                cPnt++;
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
                                else throw XenError("Invalid Number Seq at: %d", *cPnt);
                        }
                        else if(*cPnt == '#')
                        {
                                _state = TokzState_Comment;
                                _prevState = TokzState_Event;
                                cPnt++;
                        }
                        else cPnt++;
                        break;
                case TokzState_Comment:
                        if(*cPnt == '\n')
                        {
                                _state = _prevState;
                                cPnt++;
                        }
                        else cPnt++;
                        break;
                }
        }
}
