#ifndef XEN_OBJECT_H
#define XEN_OBJECT_H



//defines the basic XenObject base class for streams
//All objects in Xenon must inherit from this class



class XenObject
{
private:
    XenType type;
    XenObject* next;
    XenObject* prev;
    
public:
    XenType getType()
    {
        return type;
    }
    
    void setType(XenType type)
    {
        type = type;
    }
    
    XenObject* getNext()
    {
        return next;
    }
    
    void setNext(XenObject* xo)
    {
        next = xo;
    }
    
    XenObject* getPrev()
    {
        return prev;
    }
    
    void setPrev(XenObject* xo)
    {
        prev = xo;
    }
    
    bool nextIsNull()
    {
        return next == NULL;
    }
    
    bool prevIsNull()
    {
        return prev == NULL;
    }
    
    bool isSinglet()
    {
        return prev == NULL && next == NULL;
    }
    
    inline void connectNext(XenObject* xo)
    {
        next = xo; 
        xo->prev = this;
    }
    
    inline void connectPrev(XenObject* xo)
    {
        prev = xo; 
        xo->next = this;
    }
    
    inline static void connect(XenObject* xo1, XenObject* xo2)
    {
        xo1->next = xo2;
        xo2->prev = xo1;
    }
    //chain methods
    inline XenObject* linkNext(XenObject* xo)
    {
        next = xo; 
        xo->prev = this;
        return xo;
    }
    
    inline XenObject* linkPrev(XenObject* xo)
    {
        prev = xo; 
        xo->next = this;
        return xo;
    }
    
    //gets reference to pointer
    static XenObject& getRef(XenObject* xo)
    {
        return *xo;
    }
    
    static bool samePnt(XenObject* xo1, XenObject* xo2)
    {
        return xo1 == xo2;
    }
    
public:
//iterator methods
    XenObject* getFront();
    XenObject* getBack();
    
    void append(XenObject* xo);
    void put(XenObject* xo);
    XenObject* at(int index);
    
    int length();
};



/*
//advances pointer to back of stream
#define XenObject_ADV_BACK(xo) while(xo->next != NULL) xo = xo->next

//advances pointer to front of stream
#define XenObject_ADV_FRONT(xo) while(xo->prev != NULL) xo = xo->prev

//moves n times toward the front
#define XenObject_ADVN_FRONT(xo, n) while(n--) xo = xo->prev

//moves n times toward the back
#define XenObject_ADVN_BACK(xo, n) while(n--) xo = xo->next

//moves n times but will not move onto null
#define XenObject_ADVN_SAFE_FRONT(xo, n) while(n-- && xo->prev != NULL) xo = xo->prev

//moves n times but not onto null
#define XenObject_ADVN_SAFE_BACK(xo, n) while(n-- && xo->next != NULL) xo = xo->next

#define XenObject_APPEND(xo1, xo2) do { \
     while(xo1->next != NULL) xo1 = xo1->next; \
     xo1->next = xo2; \
     xo2->prev = xo1; \
    }while(0)
    
#define XenObject_PUT(xo1, xo2) do { \
     while(xo1->prev != NULL) xo1 = xo1->prev; \
     xo1->prev = xo2; \
     xo2->next = xo1; \
    }while(0)
*/




#endif