#ifndef H_COMMANDS
#define H_COMMANDS

#define WHICH_PATH "/usr/bin/which"

#include <stdbool.h>

#include "strbuff.h"

typedef struct command_output
{
    str_buff *output;
    int err_code;
    bool finished;
    FILE *command_fp;
} command_output;

void init_commands();

str_buff *get_command_path(const char *command_name);

str_buff *get_absolute_path(const char *in_path);

command_output *open_command(const char *absolute_command_path);

#endif