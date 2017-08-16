#ifndef XEN_OBJECT_H
#define XEN_OBJECT_H



//defines the basic XenObject base class for streams
//All objects in Xenon must inherit from this class



class XenObject
{
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
public:
//iterator methods
    XenObject* getFront();
    XenObject* getBack();
    
    void append(XenObject* xo);
    void put(XenObject* xo);
    
private:
    XenType type;
    XenObject* next;
    XenObject* prev;
};




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


//functions

//gets new xo with no type
XenObject* XenObject_new();

void XenObject_append(XenObject* xo1, XenObject* xo2);

void XenObject_put(XenObject* xo1, XenObject* xo2);

//assumes xo1 is at back and appends, return xo2
static inline XenObject*
XenObject_append_auto(XenObject* xo1, XenObject* xo2)
{
    xo1->next = xo2;
    xo2->prev = xo1;
    return xo2;
}

//used for successive puts
static inline XenObject*
XenObject_put_auto(XenObject* xo1, XenObject* xo2)
{
    xo1->prev = xo2;
    xo2->next = xo1;
    return xo1;
}

static inline XenObject*
XenObject_get_back(XenObject* xo)
{
    XenObject_ADV_BACK(xo);
    return xo;
}

static inline XenObject*
XenObject_get_front(XenObject* xo)
{
    XenObject_ADV_FRONT(xo);
    return xo;
}

void XenObject_insert_next(XenObject* xo1, XenObject* xo2);

int XenObject_length(XenObject* xo);

int XenObject_contains(XenObject* xo, XenObject* xoitem);

XenObject* XenObject_pop(XenObject* xo);

XenObject* XenObject_remove(XenObject* xo);




#endif