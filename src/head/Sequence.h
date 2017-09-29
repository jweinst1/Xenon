#ifndef SEQUENCE_HEADER
#define SEQUENCE_HEADER

#include <iostream>
#include <exception>
#include <string>
#include <cstddef>
#include <algorithm>
#include <cstdarg>

typedef std::size_t size_t;

class SequenceException : public std::exception
{
private:
std::string _msg;
public:
SequenceException(const char* message) : _msg(message)
{
}
~SequenceException(){
}

const char* what() const throw ()
{
        return _msg.c_str();
}
};

template<class T>
class Sequence
{
private:
T* _array;
size_t _size;
public:

Sequence(size_t cap) : _array(new T[cap]), _size(cap)
{
}

Sequence(size_t cap, size_t arg_c, ...) : _array(new T[cap]), _size(cap)
{
        if(arg_c > cap) throw SequenceException("Argument constructor count greater than capacity.");
        va_list args;
        va_start(args, arg_c);
        size_t i;
        for(i=0; i< arg_c; i++)
        {
                _array[i] = va_arg(args, T);
        }
        va_end(args);
}
~Sequence()
{
        delete[] _array;
}
//overloads getitem operator for get and set
T& operator[] (const int index) const
{
        if(index < _size)
        {
                return _array[index];
        }
        else
        {
                throw SequenceException("index larger than size of sequence.");
        }
}

T* begin() const
{
        return _array;
}

T* at(size_t index) const
{
        return _array + index;
}

T* end() const
{
        return _array + _size;
}

size_t size() const
{
        return _size;
}

friend Sequence<T> operator+ (const Sequence<T>& a, const Sequence<T>& b)
{
        Sequence<T> newseq(a._size + b._size);
        std::copy(a.begin(), a.end(), newseq.begin());
        std::copy(b.begin(), b.end(), newseq.at(a._size));
        return newseq;
}

friend Sequence<T>& operator+= (Sequence<T>& a, const Sequence<T>& b)
{
        a._size += b._size;
        std::copy(b.begin(), b.end(), a.at(b._size));
        return *a;
}
};

#endif
