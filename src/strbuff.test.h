#ifndef H_STRBUFF_TEST
#define H_STRBUFF_TEST

#include "greatest.h"
#include "strbuff.h"

TEST append_should_work(void)
{
    str_buff *test_buff = new_str_buff();
    append_char(test_buff, 'a');
    append_char(test_buff, 'b');
    append_char(test_buff, 'c');
    ASSERT_STR_EQ("abc", test_buff->data);
    del_str_buff(test_buff);
    PASS();
}

GREATEST_SUITE(strbuff_test)
{
    RUN_TEST(append_should_work);
}

#endif // H_STRBUFF_TEST