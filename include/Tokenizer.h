#ifndef XENON_TOKENIZER_HEADER
#define XENON_TOKENIZER_HEADER

#include "EnumTypes.h"
#include "ContextManager.h"


class Tokenizer
{
private:
TokzState _state;
TokzState _prevState;
ContextManager* _ContextManager;
XenEventType _curEvent;
double _number;
Token _inst;


public:
Tokenizer (ContextManager* prs);


void tokenize(char* code);




};

#endif
