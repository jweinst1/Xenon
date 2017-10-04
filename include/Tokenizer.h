#ifndef XENON_TOKENIZER_HEADER
#define XENON_TOKENIZER_HEADER

#include <vector>

//set of charsets to quickly classify characters with bool membership
class TokenSets
{
public:
static CharSet whiteSpace;
static CharSet digits;
static CharSet alpha;
static CharSet alphaNumeric;
static CharSet symbols;
static CharSet eventName;
static CharSet numbers;
};

//Buffer like class that contains an event type and tokens which
//can be built into an event object
class EventBuilder
{
private:
XenEventType _type;
std::vector<CharBuf> _nodes;
public:
EventBuilder(){
}
~EventBuilder(){
}
XenEventType getType()
{
        return _type;
}

void setType(XenEventType eType)
{
        _type = eType;
}

void pushNode(CharBuf& node)
{
        _nodes.push_back(node);
}

CharBuf& operator[](int index)
{
        return _nodes.at(index);
}

int length()
{
        return _nodes.size();
}

CharBuf& lastNode()
{
        return _nodes.back();
}

//used for tokenization and to prevent re-copying
CharBuf& createAndGetLast()
{
        CharBuf newBuf;
        _nodes.push_back(newBuf);
        return newBuf;
}
};

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
