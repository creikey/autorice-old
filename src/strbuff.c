#include <malloc.h>
#include <string.h>
#include <string.h>

#include "strbuff.h"

str_buff *new_str_buff()
{
    str_buff *to_return = malloc(sizeof *to_return);
    to_return->max_size = 1;
    to_return->cur_size = 0;
    to_return->data = malloc(sizeof *to_return->data * 1);
    return to_return;
}

void del_str_buff(str_buff *in_buff)
{
    free(in_buff->data);
    free(in_buff);
}

void append_char(str_buff *in_buff, char in_char)
{
    if (in_buff->cur_size >= in_buff->max_size)
    {
        in_buff->max_size *= 2;
        char *tmp = in_buff->data;
        in_buff->data = malloc(sizeof *in_buff->data * in_buff->max_size);
        memset(in_buff->data, '\0', in_buff->max_size);
        memcpy(in_buff->data, tmp, in_buff->cur_size);
        free(tmp);
    }
    in_buff->data[in_buff->cur_size] = in_char;
    in_buff->cur_size += 1;
}

void append_str(str_buff *in_buff, const char *in_str, size_t in_size)
{
    for (size_t i = 0; i < in_size; i++)
    {
        append_char(in_buff, in_str[i]);
    }
}

void append_str_ns(str_buff *in_buff, const char *in_str)
{
    append_str(in_buff, in_str, strlen(in_str));
}

void get_line(str_buff *in_buff, FILE *fp)
{
    char cur_char = fgetc(fp);
    while (cur_char != '\n' && cur_char != EOF)
    {
        append_char(in_buff, cur_char);
        cur_char = fgetc(fp);
    }
}

void clear_strbuff(str_buff *in_buff)
{
    in_buff->max_size = 1;
    in_buff->cur_size = 0;
    free(in_buff->data);
    in_buff->data = malloc(sizeof *in_buff->data * in_buff->max_size);
    memset(in_buff->data, '\0', in_buff->max_size);
}