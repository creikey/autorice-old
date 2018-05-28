#ifndef H_CUSTASSERT
#define H_CUSTASSERT

#include <assert.h>
#include <stdbool.h>

extern bool print_logs;

#define S_ASSERT(x, y) if(print_logs) { \
assert(_s_assert((void *)x, y)); \
}
#define S_LOG(...) if(print_logs) { \
printf(__VA_ARGS__); \
}

int _s_assert(void *thing, const char *fail_explanation);

#endif // H_CUSTASSERT