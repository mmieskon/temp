#include "libft.h"
#include "mm_testing.h"
#include <stdint.h>
#include <string.h>

static UnitTestResult *test_alloc_init() {
    const size_t nmemb = 3;
    const size_t size = 8;
    char *ret = ft_calloc(nmemb, size);
    for (size_t i = 0; i < nmemb * size; i++) {
        if (ret[i] != 0) {
            // TODO: Leaking memory here
            RETURN_ERROR("calloc should initialize array to zeros");
        }
    }
    free(ret);
    RETURN_SUCCESS();
}

static UnitTestResult *test_overflow() {
    const size_t nmemb = 4294967296;
    const size_t size = 4294967296;
    void *ret = ft_calloc(nmemb, size);
    if (ret != NULL) {
        // TODO: Might leak memory here
        RETURN_ERROR("calloc should return NULL if nmemb*size would overflow");
    }
    RETURN_SUCCESS();
}

Summary test_calloc() {
    RUN_UNIT_TESTS(test_alloc_init, test_overflow);
}
