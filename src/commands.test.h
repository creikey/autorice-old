#ifndef H_COMMANDS_TEST
#define H_COMMANDS_TEST

#include <stdlib.h>
#include <linux/limits.h>

#include "greatest.h"
#include "strbuff.h"
#include "commands.h"

TEST path_correct(void)
{
    const char *command = "echo";
    const char *possibilities[] = {
        "/bin/echo",
        "/usr/bin/echo"};
    size_t possibilities_size = 2;
    str_buff *got = get_command_path(command);
    int similarities = 0;
    for (size_t i = 0; i < possibilities_size; i++)
    {
        if (strcmp(possibilities[i], got->data) == 0)
        {
            similarities += 1;
        }
    }
    str_buff *to_print = new_str_buff();
    append_char(to_print, '`');
    append_str(to_print, got->data, strlen(got->data));
    append_str(to_print, "` unrecognized path", strlen("` unrecognized path"));

    ASSERTm(to_print->data, similarities > 0);
    del_str_buff(to_print);
    del_str_buff(got);
    PASS();
}

TEST absolute_path_correct(void)
{
    // Create the file to check
    const char *file_name = "testing.txt";
    const char *file_data = "test";
    FILE *fp = fopen(file_name, "w");
    fputs(file_data, fp);
    fclose(fp);
    // Get the expected path
    char expected_path[PATH_MAX + 1];
    char * exp_path_ptr = NULL;
    exp_path_ptr = realpath(file_name, expected_path);
    ASSERTm(exp_path_ptr, "realpath returned null");
    // Use premade function to get path
    str_buff *got_path = get_absolute_path(file_name);
    // Compare the two
    ASSERT_STR_EQ(exp_path_ptr, got_path->data);
    del_str_buff(got_path);
    str_buff * to_print = new_str_buff();
    append_str_ns(to_print, "Could not delete file ");
    append_str_ns(to_print, file_name);
    ASSERTm(to_print->data, remove(file_name) == 0);
    del_str_buff(to_print);
    PASS();
}

GREATEST_SUITE(commands_test)
{
    RUN_TEST(path_correct);
    RUN_TEST(absolute_path_correct);
}

#endif // H_COMMANDS_TEST