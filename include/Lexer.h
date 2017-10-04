#ifndef XENON_LEXER_HEADER
#define XENON_LEXER_HEADER

/*Lexer header***
 * Classifies tokens and stores all enum types related to parsing and lexing
 */

enum XenEventType
{
        XenEventType_In,
        XenEventType_Out,
        XenEventType_Add
};


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

class Lexer {

public:
static double oneDigit(const char* ch);
static XenEventType eventType(const char* token);
};





#endif
