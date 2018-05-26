#ifndef H_TESTS_TEST
#define H_TESTS_TEST

#include "strbuff.test.h"

extern SUITE(strbuff_test);

#define RUN_ALL_SUITS() \
    RUN_SUITE(strbuff_test);

#endif // H_TESTS_TEST