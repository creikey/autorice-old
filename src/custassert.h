#ifndef H_CUSTASSERT
#define H_CUSTASSERT

#include <assert.h>
#include <stdbool.h>

extern bool print_logs;

#define S_ASSERT(x, y) \
    x ? _s_success() : _s_fail(y);
#define S_LOG(...)           \
    if (print_logs)          \
    {                        \
        printf(__VA_ARGS__); \
    }

int _s_fail(const char *fail_explanation);

int _s_success();

#endif // H_CUSTASSERT