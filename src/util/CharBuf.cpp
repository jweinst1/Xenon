#include "CharBuf.h"

CharBuf::CharBuf() : _buf(new char[CHARBUF_DEF_CAP]),
        _cap(CHARBUF_DEF_CAP),
        _len(0)
{
        *_buf = '\0';
}

void CharBuf::reSize()
{
        char* newBuf = new char[(_cap *= 2)];
        std::copy(_buf, _buf + _len, newBuf);
        std::swap(_buf, newBuf);
        delete[] newBuf;
}

void CharBuf::reserve(size_t newSize)
{
        if(newSize > _cap)
        {
                char* newBuf = new char[(_cap = newSize)];
                std::copy(_buf, _buf + _len, newBuf);
                std::swap(_buf, newBuf);
                delete[] newBuf;
        }
}
