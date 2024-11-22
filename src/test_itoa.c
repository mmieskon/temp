#include "libft.h"
#include "mm_testing.h"
#include <limits.h>

static UnitTestResult *test_positive() {
    {
        int i = 5;
        char *ret = ft_itoa(i);
        char expected[] = "5";
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected %s, got %s", expected, ret);
        }
        free(ret);
    }

    {
        int i = 12345;
        char *ret = ft_itoa(i);
        char expected[] = "12345";
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected %s, got %s", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_negative() {
    {
        int i = -5;
        char *ret = ft_itoa(i);
        char expected[] = "-5";
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected %s, got %s", expected, ret);
        }
        free(ret);
    }

    {
        int i = -12345;
        char *ret = ft_itoa(i);
        char expected[] = "-12345";
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected %s, got %s", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_zero() {
    {
        int i = 0;
        char *ret = ft_itoa(i);
        char expected[] = "0";
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected %s, got %s", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_limits() {
    {
        int i = 2147483647;
        char *ret = ft_itoa(i);
        char expected[] = "2147483647";
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected %s, got %s", expected, ret);
        }
        free(ret);
    }

    {
        int i = -2147483648;
        char *ret = ft_itoa(i);
        char expected[] = "-2147483648";
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected %s, got %s", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

Summary test_itoa() {
    RUN_UNIT_TESTS(test_positive, test_negative, test_zero, test_limits);
}
