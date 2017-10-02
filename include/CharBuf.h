#ifndef XENCHAR_BUF_HEADER
#define XENCHAR_BUF_HEADER

#define CHARBUF_DEF_CAP 500

//utility class for reading chars from code or lines of input
class CharBuf
{
private:
char* _buf;
size_t _cap;
size_t _len;

public:
CharBuf();
~CharBuf()
{
        delete[] _buf;
}
};


#endif
