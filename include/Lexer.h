#ifndef XENON_LEXER_HEADER
#define XENON_LEXER_HEADER


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





#endif
