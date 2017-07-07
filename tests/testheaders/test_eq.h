#ifndef TEST_EQ_H
#define TEST_EQ_H

#include "stdio.h"
#include "stdlib.h"

#define TEST_IS_TRUE_N(arg, n) arg ? printf("TEST PASSED %d \n", n) : printf("TEST FAILED %d \n", n)

#define TEST_IS_EQUAL(arg1, arg2) arg1 == arg2 ? printf("TEST PASSED\n") : printf("TEST FAILED\n")

#define TEST_IS_EQUAL_N(arg1, arg2, n) arg1 == arg2 ? printf("TEST PASSED %d \n", n) : printf("TEST FAILED %d \n", n)

#define TEST_IS_EQUAL_S(arg1, arg2, s) arg1 == arg2 ? printf("TEST PASSED %s \n", s) : printf("TEST FAILED %s \n", s)

#endif