#include <iostream>
#include <exception>
#include <string>

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
int _size;
public:
Sequence(int size) : _array(new T[size]), _size(size)
{
}
~Sequence()
{
        delete[] _array;
}
//overloads getitem operator for get and set
T& operator[] (const int index)
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

T* begin()
{
        return _array;
}

T* end()
{
        return _array + _size;
}
};
