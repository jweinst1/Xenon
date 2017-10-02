#ifndef CHAR_SET_HEADER
#define CHAR_SET_HEADER




//class used for quick checking if a char is inside a set of chars
class CharSet
{
private:
bool _chars[256];
public:
CharSet(const char* chlst);

bool contains(char ch)
{
        return _chars[(unsigned char)ch];
}

bool operator[] (char ch)
{
        return _chars[(unsigned char)ch];
}
bool containsAll(const char* chlst);
};

#endif
