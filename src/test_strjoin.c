#include "libft.h"
#include "mm_testing.h"
#include <string.h>

static UnitTestResult *test_full_full() {
    {
        char s1[] = "Hello ";
        char s2[] = "world";
        char expected[] = "Hello world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strjoin(s1, s2);
        if (strncmp(ret, expected, expected_len + 1) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_full_empty() {
    {
        char s1[] = "Hello";
        char s2[] = "";
        char expected[] = "Hello";
        size_t expected_len = strlen(expected);
        char *ret = ft_strjoin(s1, s2);
        if (strncmp(ret, expected, expected_len + 1) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_empty_full() {
    {
        char s1[] = "";
        char s2[] = "world";
        char expected[] = "world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strjoin(s1, s2);
        if (strncmp(ret, expected, expected_len + 1) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_empty_empty() {
    {
        char s1[] = "";
        char s2[] = "";
        char expected[] = "";
        size_t expected_len = strlen(expected);
        char *ret = ft_strjoin(s1, s2);
        if (strncmp(ret, expected, expected_len + 1) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

Summary test_strjoin() {
    RUN_UNIT_TESTS(test_full_full, test_full_empty, test_empty_full,
                   test_empty_empty);
}
