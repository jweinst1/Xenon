#include <iostream>
#include <exception>
#include <string>
#include <cstddef>
#include <algorithm>

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
Sequence(size_t size) : _array(new T[size]), _size(size)
{
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
