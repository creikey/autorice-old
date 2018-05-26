#ifndef H_TESTS_TEST
#define H_TESTS_TEST

#include "strbuff.test.h"
#include "commands.test.h"

extern SUITE(strbuff_test);
extern SUITE(commands_test);

#define RUN_ALL_SUITS() \
    RUN_SUITE(strbuff_test); \
    RUN_SUITE(commands_test);

#endif // H_TESTS_TEST