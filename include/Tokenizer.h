#ifndef XENON_TOKENIZER_HEADER
#define XENON_TOKENIZER_HEADER

//state tracking for tokenizer
enum TokzState
{
        TokzState_Base,
        TokzState_Comment,
        TokzState_EventName,
        TokzState_Number
};

class Tokenizer
{
private:
TokzState _state;
EventBuilder _eventBld;

public:
Tokenizer ();
~Tokenizer ();




};

#endif
