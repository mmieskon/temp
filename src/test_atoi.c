#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_positive() {
    {
        char str[] = "1";
        int ret = ft_atoi(str);
        int expected = 1;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char str[] = "123";
        int ret = ft_atoi(str);
        int expected = 123;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char str[] = "2147483647";
        int ret = ft_atoi(str);
        int expected = 2147483647;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_negative() {
    {
        char str[] = "-1";
        int ret = ft_atoi(str);
        int expected = -1;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char str[] = "-123";
        int ret = ft_atoi(str);
        int expected = -123;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char str[] = "-2147483648";
        int ret = ft_atoi(str);
        int expected = -2147483648;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_zero() {
    {
        char str[] = "0";
        int ret = ft_atoi(str);
        int expected = 0;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char str[] = "-0";
        int ret = ft_atoi(str);
        int expected = 0;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char str[] = "+0";
        int ret = ft_atoi(str);
        int expected = 0;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_leading_whitespace() {
    {
        char str[] = "  \f\f\n\n\r\t\v123";
        int ret = ft_atoi(str);
        int expected = 123;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char str[] = "  \f\f\n\n\r\t\v-123";
        int ret = ft_atoi(str);
        int expected = -123;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_following_characters() {
    {
        char str[] = "1234abcd";
        int ret = ft_atoi(str);
        int expected = 1234;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_other() {
    {
        char str[] = "  \f\f\n\n\r\t\v-2147483648asdfasdf";
        int ret = ft_atoi(str);
        int expected = -2147483648;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_error() {
    {
        char str[] = "asdf";
        int ret = ft_atoi(str);
        int expected = 0;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d (NOTE: Allowed to fail?)",
                         expected, ret);
        }
    }

    {
        char str[] = "--1";
        int ret = ft_atoi(str);
        int expected = 0;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d (NOTE: Allowed to fail?)",
                         expected, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_atoi() {
    RUN_UNIT_TESTS(test_positive, test_negative, test_zero,
                   test_leading_whitespace, test_following_characters,
                   test_other, test_error);
}
