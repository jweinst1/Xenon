#ifndef XENON_TOKENIZER_HEADER
#define XENON_TOKENIZER_HEADER

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

class Tokenizer
{
private:
/* data */

public:
Tokenizer ();
virtual ~Tokenizer ();
};

#endif
