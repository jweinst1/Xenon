#ifndef EVENT_PARSER_HEADER
#define EVENT_PARSER_HEADER

#include <cstdlib>

//contains sets of tokens used to parse event
class EventTokens
{
public:
static CharSet digits;
static CharSet alpha;
static CharSet alphaNumeric;
static CharSet symbols;
static CharSet eventName;
static CharSet numbers;
};

#endif
