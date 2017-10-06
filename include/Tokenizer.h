#ifndef XENON_TOKENIZER_HEADER
#define XENON_TOKENIZER_HEADER

#include "EnumTypes.h"
#include "Parser.h"


class Tokenizer
{
private:
TokzState _state;
Parser* _parser;
XenEventType _curEvent;
double _number;
Token _inst;


public:
Tokenizer (Parser* prs);
~Tokenizer ();

void tokenize(char* code);




};

#endif
