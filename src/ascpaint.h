#ifndef H_ASCPAINT
#define H_ASCPAINT

typedef struct term_size
{
    int c;
    int r;
} term_size;

extern term_size _cur_term_size;

term_size get_term_size();

void asc_paint_str(const char *to_print);

void init_ascpaint();

void clear_screen();

void center_text(const char *to_center);

#endif // H_ASCPAINT