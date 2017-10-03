#ifndef XENCHAR_BUF_HEADER
#define XENCHAR_BUF_HEADER

#include <cstddef>
#include <algorithm>

#define CHARBUF_DEF_CAP 100

//utility class for reading chars from code or lines of input
class CharBuf
{
private:
char* _buf;
size_t _cap;
size_t _len;

void reSize();

public:
CharBuf();
~CharBuf()
{
        delete[] _buf;
}

size_t getLength()
{
        return _len;
}

size_t getCapacity()
{
        return _cap;
}

char* data()
{
        return _buf;
}

inline void append(char ch)
{
        _buf[_len] = ch;
        _buf[++_len] = '\0';
        if(_len == _cap) reSize();
}
void reserve(size_t newSize);

};


#endif
