#ifndef XEN_STREAM_MANAGER_H
#define XEN_STREAM_MANAGER_H

//this class manages XenObjects to provide more collection like functions 

class XenStreamManager
{
public:
    XenStreamManager();
private:
    XenObject* stream;
};

#endif