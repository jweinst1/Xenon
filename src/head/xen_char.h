#ifndef XEN_CHAR_H
#define XEN_CHAR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    XenObject_HANDLE
    char value;
} XenChar;

#define XenChar_IS_DIGIT(xc) isdigit(xc->value)

#define XenChar_IS_ALPHA(xc) isalpha(xc->value)

#define XenChar_IS_SPACE(xc) isspace(xc->value)

#define XenChar_MARK_TYPE(xc) xc->type = XenType_Char

#define XenChar_GET_CHAR(xo) ((XenChar*)xo)->value

#define XenChar_GET_UCHAR(xc) (unsigned char)(xc->value)

#define XenChar_SET_CHAR(xc, ch) xc->value = ch

#define XenChar_GET_INT(xc) (int)(xc->value)

#define XenChar_SAME_CHAR(xc1, xc2) (xc1->value) == (xc2->value)

//makes new xenchar object
XenChar* XenChar_new(char ch);

int XenChar_make_int(XenChar* xc);


#ifdef __cplusplus
}
#endif

#endif
