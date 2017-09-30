#ifndef XENON_CONTEXT_HEADER
#define XENON_CONTEXT_HEADER

//this file contains a context class to facilitate reaction streams

class XenContext
{
public:
enum State   //will be used when labels are added.
{
        Singular
};

XenContext();
~XenContext();
private:
XenObject variable;
};

#endif
