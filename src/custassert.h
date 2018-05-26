#ifndef H_CUSTASSERT
#define H_CUSTASSERT

#include <assert.h>

#define S_ASSERT(x, y) assert(_s_assert((void *)x, y))

int _s_assert(void *thing, const char *fail_explanation);

#endif // H_CUSTASSERT