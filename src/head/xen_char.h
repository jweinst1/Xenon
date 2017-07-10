#ifndef XEN_CHAR_H
#define XEN_CHAR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    XenObject_HANDLE
    char value;
} XenChar;

#define XenChar_ISDIGIT(xc) isdigit(xc)

#define XenChar_ISALPHA(xc) isalpha(xc)

#define XenChar_GET_CHAR(xc) xc->value

#define XenChar_GET_INT(xc) (int)(xc->value)

//makes new xenchar object
XenChar* XenChar_new(char ch);

int XenChar_make_int(XenChar* xc);


#ifdef __cplusplus
}
#endif

#endif
