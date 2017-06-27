#include <stdio.h>
#include <stdlib.h>

//c example for object stream

//used for casting
typedef unsigned XenonType;



typedef struct {
    XenonType type;
} XenonObject;

typedef struct {
    XenonType type;
    int val;
} XenonInt;

typedef struct {
    XenonObject* data[50];
    int length;
} XenonStream;

static XenonStream* DICT[100];

//constructs a new stream
XenonStream* new_Stream()
{
    XenonStream* stream = (XenonStream*)malloc(sizeof(XenonStream*));
    stream->length = 50;
    return stream;
}

void del_Stream(XenonStream*xs)
{
    XenonObject** pnt = xs->data;
    //frees first element
    free((void*)*pnt);
    free((void*)xs);
}

//uses compound literal
XenonInt* const_int(int val)
{
    XenonInt* newi = (XenonInt*)malloc(sizeof(XenonInt*));
    newi->type = 0;
    newi->val = val;
    return newi;
}



//places an int in the stream
void place_Int(XenonStream* xs, int index, int val)
{
    xs->data[index] = (XenonObject*)const_int(val);
}

//gets the int at some index
int get_Int(XenonStream* xs, int index)
{
    return ((XenonInt*)xs->data[index])->val;
}




int main()
{
    XenonStream* strm = new_Stream();
    place_Int(strm, 0, 55);
    printf("The int is placed with val: %d\n", get_Int(strm, 0));
    del_Stream(strm);
    return 0;
}