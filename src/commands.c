#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <string.h>

#include "commands.h"
#include "custassert.h"
#include "strbuff.h"

void init_commands()
{
    S_LOG("Initializing commands...");
    FILE *whis_fp = NULL;
    whis_fp = fopen(WHICH_PATH, "r");
    S_ASSERT(whis_fp, "Could not find `which` binary");
    fclose(whis_fp);
}

str_buff *get_command_path(const char *command_name)
{
    FILE *fp = NULL;
    str_buff *to_run = new_str_buff();
    str_buff *to_return = new_str_buff();
    append_str(to_run, WHICH_PATH, strlen(WHICH_PATH));
    append_char(to_run, ' ');
    append_str(to_run, command_name, strlen(command_name));

    fp = popen(to_run->data, "r");
    str_buff *to_error = new_str_buff();
    append_str(to_error, "Popen returned null when opening the command ", strlen("Popen returned null when opening the command "));
    append_str(to_error, to_run->data, strlen(to_run->data));

    get_line(to_return, fp);

    del_str_buff(to_error);
    del_str_buff(to_run);
    pclose(fp);
    return to_return;
}

str_buff *get_absolute_path(const char *in_path)
{
    str_buff *to_return = new_str_buff();
    char actual_path[PATH_MAX + 1];
    char *got = NULL;
    got = realpath(in_path, actual_path);
    append_str(to_return, got, strlen(got));
    return to_return;
}

command_output *open_command(const char *absolute_command_path)
{
    command_output *to_return = malloc(sizeof *to_return);
    to_return->output = new_str_buff();
    to_return->err_code = 0;
    to_return->finished = false;
    to_return->command_fp = popen(absolute_command_path, "r");
    return to_return;
}
