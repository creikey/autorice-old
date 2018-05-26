#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "commands.h"
#include "custassert.h"
#include "strbuff.h"

void init_commands()
{
    printf("Initializing commands...");
    FILE *whis_fp = NULL;
    whis_fp = fopen(WHICH_PATH, "r");
    S_ASSERT(whis_fp, "Could not find `which` binary");
    fclose(whis_fp);
}

char *get_command_path(const char *command_name)
{
    FILE *fp = NULL;
    str_buff *to_run = new_str_buff();
    str_buff *to_return = new_str_buff();
    append_str(to_run, WHICH_PATH, strlen(WHICH_PATH));
    append_char(to_run, ' ');
    append_str(to_run, command_name, strlen(command_name));

    printf("Finding command %s...", command_name);
    fp = popen(to_run->data, "r");
    str_buff *to_error = new_str_buff();
    append_str(to_error, "Popen returned null when opening the command ", strlen("Popen returned null when opening the command "));
    append_str(to_error, to_run->data, strlen(to_run->data));
    S_ASSERT(fp, to_error->data);

    get_line(to_return, fp);

    del_str_buff(to_error);
    del_str_buff(to_run);
    pclose(fp);
    return make_n_str(to_return);
}

