#include "../head/xenon_object.h"
#include <string.h>

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

void obj_cons_uint(XenonObject* xbj, const unsigned int value)
{
    xbj->data = allo_uint_s();
    xbj->type = 2;
    *((unsigned int*)xbj->data) = value;
}

void obj_cons_char(XenonObject* xbj, const char value)
{
    xbj->data = allo_char_s();
    xbj->type = 3;
    *((char*)xbj->data) = value;
}

//constrcuts a string or multiple chars of a known length
void obj_cons_str(XenonObject* xbj, const char* value, const int length)
{
    xbj->data = allo_char_m(length);
    xbj->type = 3;
    strcpy(((char*)xbj->data), value);
}