#include "Xenon.h"
#include "test_eq.h"

//reaction unit tests

void xrx_test_1_add()
{
    XenReaction* rx1 = XenReaction_new(XenInst_Add, XenInt_new_obj(5), 1, XenReaction_new(XenInst_Add, XenInt_new_obj(5), 1, NULL));
    XenObject* xo = XenObject_put_auto(XenInt_new_obj(3), XenObject_put_auto(XenInt_new_obj(2), XenInt_new_obj(6)));
    XenReaction_react(rx1, xo);
    TEST_IS_EQUAL_S(XenInt_GET_INT(xo), 13, "xrx test 1 add");
}

void xs_test_2_put()
{
    
}

void xs_test_3_set()
{
    
}


int main()
{
    xrx_test_1_add();
    return 0;
}