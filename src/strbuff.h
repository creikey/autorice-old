#ifndef H_STRBUFF
#define H_STRBUFF

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

#endif // H_STRBUFF