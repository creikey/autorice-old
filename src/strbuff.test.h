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

TEST str_append_work(void)
{
    str_buff *test_buff = new_str_buff();
    const char *to_append = "test ING";
    append_str(test_buff, to_append, strlen(to_append));
    ASSERT_STR_EQ(to_append, test_buff->data);
    del_str_buff(test_buff);
    PASS();
}

TEST file_get_line_work(void)
{
    const char *to_write = "to WRTI to file\n";
    str_buff *expected = new_str_buff();
    append_str(expected, to_write, strlen(to_write));
    expected->data[expected->cur_size - 1] = '\0';
    FILE *fp = fopen("tmp.txt", "w");
    ASSERTm("Could not open tmp.txt for writing", fp);
    fputs(to_write, fp);
    fclose(fp);
    fp = fopen("tmp.txt", "r");
    ASSERTm("Could not open tmp.txt for reading", fp);
    str_buff *got = new_str_buff();
    get_line(got, fp);
    ASSERT_STR_EQ(expected->data, got->data);
    del_str_buff(got);
    del_str_buff(expected);
    ASSERTm("Could not delete file tmp.txt", remove("tmp.txt") == 0);
    PASS();
}

TEST pointer_switching(void)
{
    const char *to_test = "fdsjfsdl t TEsj ss\n\nsdfj";
    str_buff *test_buff = new_str_buff();
    append_str(test_buff, to_test, strlen(to_test));
    char *tmp = test_buff->data;
    free(test_buff);
    ASSERT_STR_EQ(to_test, tmp);
    free(tmp);
    PASS();
}

TEST append_string_no_size(void)
{
    const char * to_test = "fdfdsklfj @JL#!!";
    str_buff * test_buff = new_str_buff();
    append_str_ns(test_buff, to_test);
    ASSERT_STR_EQ(to_test, test_buff->data);
    del_str_buff(test_buff);
    PASS();
}

GREATEST_SUITE(strbuff_test)
{
    RUN_TEST(append_should_work);
    RUN_TEST(str_append_work);
    RUN_TEST(file_get_line_work);
    RUN_TEST(pointer_switching);
    RUN_TEST(append_string_no_size);
}

#endif // H_STRBUFF_TEST