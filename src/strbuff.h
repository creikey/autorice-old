#ifndef H_STRBUFF
#define H_STRBUFF

#include <stdio.h>
#include <stddef.h>

typedef struct str_buff
{
    size_t max_size;
    size_t cur_size;
    char *data;
} str_buff;

str_buff *new_str_buff();

void del_str_buff(str_buff *in_buff);

void append_char(str_buff *in_buff, char in_char);

void append_str(str_buff *in_buff, const char *in_str, size_t in_size);

void get_line(str_buff *in_buff, FILE *fp);

char * make_n_str(str_buff * in_buff);

#endif // H_STRBUFF