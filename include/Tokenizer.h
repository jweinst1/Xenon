#ifndef XENON_TOKENIZER_HEADER
#define XENON_TOKENIZER_HEADER

class TokenSets
{
public:
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
Tokenizer (arguments);
virtual ~Tokenizer ();
};

#endif
