#include "Xenon.h"
#include "test_eq.h"




//unit tests for xenon object

void xo_test_1_settype()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject_SET_TYPE(one, 5);
    TEST_IS_EQUAL_S(XenObject_GET_TYPE(one), 5, "1 settype");
    free(one);
}

void xo_test_2_sametype()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = malloc(sizeof(XenObject));
    XenObject_SET_TYPE(one, 5);
    XenObject_SET_TYPE(two, 5);
    TEST_IS_TRUE_S(XenObject_SAME_TYPE(one, two), "2 sametype");
    free(one); free(two);
}

void xo_test_3_connectnext()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = malloc(sizeof(XenObject));
    XenObject_CONNECT_NEXT(one, two);
    TEST_IS_TRUE_S(XenObject_SAME_PNT(two, one->next), "3 connect next");
    free(one); free(two);
}

void xo_test_4_insertnext()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = malloc(sizeof(XenObject));
    XenObject* three = malloc(sizeof(XenObject));
    XenObject_CONNECT_NEXT(one, two);
    XenObject_insert_next(one, three);
    TEST_IS_TRUE_S(XenObject_SAME_PNT(three, one->next), "4 insertnext");
    free(one); free(two); free(three);
}

void xo_test_5_length()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = (XenObject*)malloc(sizeof(XenObject));
    XenObject* three = (XenObject*)malloc(sizeof(XenObject));
    XenObject* four = (XenObject*)malloc(sizeof(XenObject));
    XenObject_SET_NP_NULL(one);
    XenObject_SET_NP_NULL(two);
    XenObject_SET_NP_NULL(three);
    XenObject_SET_NP_NULL(four);
    XenObject_APPEND(one, two);
    XenObject_APPEND(one, three);
    XenObject_APPEND(one, four);
    XenObject_ADV_FRONT(one);
    TEST_IS_EQUAL_S(XenObject_length(one), 4, "5 length");
    free(one); free(two); free(three); free(four);
}

void xo_test_6_append()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = malloc(sizeof(XenObject));
    XenObject* three = malloc(sizeof(XenObject));
    XenObject_SET_NP_NULL(one);
    XenObject_SET_NP_NULL(two);
    XenObject_SET_NP_NULL(three);
    XenObject_append(one, two);
    XenObject_append(one, three);
    XenObject_ADV_BACK(one);
    TEST_IS_TRUE_S(XenObject_SAME_PNT(one, three), "6 append");
}

void xo_test_7_getback()
{
    XenObject* one = malloc(sizeof(XenObject));
    XenObject* two = malloc(sizeof(XenObject));
    XenObject* three = malloc(sizeof(XenObject));
    XenObject_SET_NP_NULL(one);
    XenObject_SET_NP_NULL(two);
    XenObject_SET_NP_NULL(three);
    XenObject_append(one, two);
    XenObject_append(one, three);
    XenObject* other = XenObject_get_back(one);
    TEST_IS_TRUE_S(XenObject_SAME_PNT(other, three), "7 getback");
}



int main(){
    xo_test_1_settype();
    xo_test_2_sametype();
    xo_test_3_connectnext();
    xo_test_4_insertnext();
    xo_test_5_length();
    xo_test_6_append();
    xo_test_7_getback();
    return 0;
}