#ifndef XEN_STREAM_MANAGER_H
#define XEN_STREAM_MANAGER_H

//this class manages XenObjects to provide more collection like functions 

class XenStreamManager
{
private:
    XenObject* frontStream;
    XenObject* backStream;
public:
    XenStreamManager();
    
    XenObject* getFrontStream()
    {
        return frontStream;
    }
    
    XenObject* getBackStream()
    {
        return backStream;
    }
    
    void setStream(XenObject* xo)
    {
        frontStream = xo;
        backStream = xo->getBack();
    }
    
    bool streamIsNull()
    {
        return frontStream == NULL && backStream == NULL;
    }
    
    inline void appendObject(XenObject* xo)
    {
        backStream->connectNext(xo);
        backStream = backStream->getNext();
    }
public:
    int length();
};

#endif