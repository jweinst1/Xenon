#include "../head/xenon_object.h"

/*
* Main file for implementation of the base xenonobject and constructors of basic C types
*/

void obj_del(XenonObject* xbj)
{
    if(!(xbj->type == 0))
    {
        free(xbj->data);
        xbj->data = NULL;
        xbj->type = 0;
    }
}

//constructor functions

void obj_cons_null(XenonObject* xbj)
{
    xbj->data = NULL;
    xbj->type = 0;
}

void obj_cons_int(XenonObject* xbj, const int value)
{
    xbj->data = allo_int_s();
    xbj->type = 1;
    *((int*)xbj->data) = value;
}

void obj_cons_char(XenonObject* xbj, const char value)
{
    xbj->data = allo_char_s();
    xbj->type = 3;
    *((char*)xbj->data) = value;
}