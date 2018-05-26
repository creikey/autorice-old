#ifndef H_COMMANDS_TEST
#define H_COMMANDS_TEST

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
    char *got = get_command_path(command);
    int similarities = 0;
    for (size_t i = 0; i < possibilities_size; i++)
    {
        if (strcmp(possibilities[i], got) == 0)
        {
            similarities += 1;
        }
    }
    str_buff *to_print = new_str_buff();
    append_char(to_print, '`');
    append_str(to_print, got, strlen(got));
    append_str(to_print, "` unrecognized path", strlen("` unrecognized path"));

    ASSERTm(make_n_str(to_print), similarities > 0);
    //ASSERT_STR_EQ(path, got);
    PASS();
}

GREATEST_SUITE(commands_test)
{
    RUN_TEST(path_correct);
}

#endif // H_COMMANDS_TEST