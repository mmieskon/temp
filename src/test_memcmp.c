#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_equal() {
    {
        char s1[] = "Hello world";
        char s2[] = "Hello world";
        int len = strlen(s1);
        int ret = ft_memcmp(s1, s2, len);
        int expected = 0;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char s1[] = "Hello worldXXX";
        char s2[] = "Hello worldYYY";
        int len = 11;
        int ret = ft_memcmp(s1, s2, len);
        int expected = 0;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    {
        char s1[] = "A";
        char s2[] = "B";
        int len = 0;
        int ret = ft_memcmp(s1, s2, len);
        int expected = 0;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_less() {
    {
        char s1[] = "A";
        char s2[] = "B";
        int len = 1;
        int ret = ft_memcmp(s1, s2, len);
        if (!(ret < 0)) {
            RETURN_ERROR("expected return value to be less than zero, got %d",
                         ret);
        }
    }

    {
        char s1[] = "ABBA";
        char s2[] = "ABBB";
        int len = strlen(s1);
        int ret = ft_memcmp(s1, s2, len);
        if (!(ret < 0)) {
            RETURN_ERROR("expected return value to be less than zero, got %d",
                         ret);
        }
    }

    {
        char s1[] = "ABBA";
        char s2[] = "ABBO";
        int len = strlen(s1);
        int ret = ft_memcmp(s1, s2, len);
        if (!(ret < 0)) {
            RETURN_ERROR("expected return value to be less than zero, got %d",
                         ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_greater() {
    {
        char s1[] = "B";
        char s2[] = "A";
        int len = strlen(s1);
        int ret = ft_memcmp(s1, s2, len);
        if (!(ret > 0)) {
            RETURN_ERROR(
                "expected return value to be greater than zero, got %d", ret);
        }
    }

    {
        char s1[] = "ABBB";
        char s2[] = "ABBA";
        int len = strlen(s1);
        int ret = ft_memcmp(s1, s2, len);
        if (!(ret > 0)) {
            RETURN_ERROR(
                "expected return value to be greater than zero, got %d", ret);
        }
    }

    {
        char s1[] = "ABBO";
        char s2[] = "ABBA";
        int len = strlen(s1);
        int ret = ft_memcmp(s1, s2, len);
        if (!(ret > 0)) {
            RETURN_ERROR(
                "expected return value to be greater than zero, got %d", ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_not_strncmp() {
    {
        char s1[] = "\0ABBA";
        char s2[] = "\0ABBB";
        int len = 5;
        int ret = ft_memcmp(s1, s2, len);
        if (!(ret < 0)) {
            RETURN_ERROR("expected return value to be less than zero, got %d",
                         ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_exact_retval() {
    {
        char s1[] = "A";
        char s2[] = "O";
        int len = 1;
        int ret = ft_memcmp(s1, s2, len);
        int expected = 'A' - 'O';
        if (ret != expected) {
            RETURN_ERROR(
                "expected %d, got %d (NOTE: Manual only talks about return "
                "values being less than, equal to or greater than zero)",
                expected, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_memcmp() {
    RUN_UNIT_TESTS(test_equal, test_less, test_greater, test_not_strncmp,
                   test_exact_retval);
}
