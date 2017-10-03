#ifndef XEN_SMPOINTER_HEADER
#define XEN_SMPOINTER_HEADER

//util smart pointer class
template<typename T>
class SmPointer
{
private:
T* _data;
public:
SmPointer(T* pntr) : _data(pntr)
{
}
~SmPointer()
{
        delete _data;
}

T& operator* ()
{
        return *_data;
}

T* operator-> ()
{
        return _data;
}

T* data()
{
        return _data;
}

};

#endif
