#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_nonzero_len() {
    {
        char buf[] = "ABCDEF";
        ft_bzero(buf, 1);
        if (memcmp(buf, "\0BCDEF", sizeof("ABCDEF")) != 0) {
            RETURN_ERROR("unexpected output");
        }
    }

    {
        char buf[] = "ABCDEF";
        ft_bzero(buf, 2);
        if (memcmp(buf, "\0\0CDEF", sizeof("ABCDEF")) != 0) {
            RETURN_ERROR("unexpected output");
        }
    }

    {
        char buf[] = "ABCDEF";
        ft_bzero(buf, 6);
        if (memcmp(buf, "\0\0\0\0\0\0", sizeof("ABCDEF")) != 0) {
            RETURN_ERROR("unexpected output");
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_zero_len() {
    {
        char buf[] = "ABCDEF";
        ft_bzero(buf, 0);
        if (memcmp(buf, "ABCDEF", sizeof("ABCDEF")) != 0) {
            RETURN_ERROR("unexpected output");
        }
    }

    RETURN_SUCCESS();
}

Summary test_bzero() {
    RUN_UNIT_TESTS(test_nonzero_len, test_zero_len);
}
