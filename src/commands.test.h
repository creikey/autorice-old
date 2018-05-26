#ifndef H_COMMANDS_TEST
#define H_COMMANDS_TEST

#include "greatest.h"
#include "commands.h"

TEST path_correct(void)
{
    const char * command = "echo";
    const char * path = "/bin/echo";
    char * got = get_command_path(command);
    ASSERT_STR_EQ(path, got);
    PASS();
}

GREATEST_SUITE(commands_test)
{
    RUN_TEST(path_correct);
}

#endif // H_COMMANDS_TEST