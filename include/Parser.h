#ifndef XENON_PARSER_HEADER
#define XENON_PARSER_HEADER

#include <vector>

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

std::vector<CharBuf>& getNodes()
{
        return _nodes;
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

#endif
