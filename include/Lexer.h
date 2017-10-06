#ifndef XENON_LEXER_HEADER
#define XENON_LEXER_HEADER

#include <cstddef>
#include <cstdlib>

#include "EnumTypes.h"
#include "CharSet.h"
#include "XenError.h"

/*Lexer header***
 * Classifies tokens
 */


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
static CharSet numberStart;
};



class Lexer {

public:
static double oneDigit(const char* ch);
static void eventType(char* token, XenEventType* eType, char** nextChar);

static inline bool isNumberStart(const char* ch)
{
        return TokenSets::numberStart.contains(*ch);
}

static inline bool isEventStart(const char* ch)
{
        return TokenSets::eventName.contains(*ch);
}

//tests if a token is a singular zero.
static inline bool isZero(const char* ch)
{
        return *ch == '0' && TokenSets::whiteSpace.contains(ch[1]);
}
};





#endif
