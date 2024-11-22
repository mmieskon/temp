#include "libft.h"
#include "mm_testing.h"
#include <string.h>

static UnitTestResult *test_found_unique() {
    const char big[] = "ABCabc123'!@\n\t";
    const int big_len = (sizeof(big) / sizeof(char)) - 1;
    char little[big_len];
    char *ret, *expected;
    for (int i = 0; i < big_len; i++) {
        for (int curr_len = 1; curr_len <= big_len - i; curr_len++) {
            for (int j = 0; j < curr_len; j++) {
                little[j] = (big + i)[j];
            }
            little[curr_len] = '\0';

            ret = ft_strnstr(big, little, big_len);
            expected = (char *)(big + i);
            if (ret != expected) {
                RETURN_ERROR("expected %p, got %p", expected, ret);
            }
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_found_non_unique() {
    const char big[] = "ABCabc123'!@\n\tABCabc123'!@\n\tABCabc123'!@\n\t";
    const int big_len = (sizeof(big) / sizeof(char)) - 1;
    const int unique_len = (sizeof("ABCabc123'!@\n\t") / sizeof(char)) - 1;
    char little[unique_len];
    char *ret, *expected;
    for (int i = 0; i < unique_len; i++) {
        for (int curr_len = 1; curr_len <= unique_len - i; curr_len++) {
            for (int j = 0; j < curr_len; j++) {
                little[j] = (big + i)[j];
            }
            little[curr_len] = '\0';

            ret = ft_strnstr(big, little, big_len);
            expected = (char *)(big + i);
            if (ret != expected) {
                RETURN_ERROR("expected %p, got %p", expected, ret);
            }
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_not_found() {
    const char big[] = "ABCDEFGB";
    const int big_len = strlen(big);
    char *ret, *expected;
    expected = NULL;

    ret = ft_strnstr(big, "AA", big_len);
    if (ret != expected) {
        RETURN_ERROR("expected %p, got %p", expected, ret);
    }

    ret = ft_strnstr(big, "BB", big_len);
    if (ret != expected) {
        RETURN_ERROR("expected %p, got %p", expected, ret);
    }

    ret = ft_strnstr(big, "1", big_len);
    if (ret != expected) {
        RETURN_ERROR("expected %p, got %p", expected, ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_empty() {
    char *ret, *expected;
    {
        const char big[] = "Hello";
        const char little[] = "";

        expected = (char *)big;
        ret = ft_strnstr(big, little, 999);
        if (ret != expected) {
            RETURN_ERROR("expected %p, got %p", expected, ret);
        }
    }

    {
        const char big[] = "";
        const char little[] = "";

        expected = (char *)big;
        ret = ft_strnstr(big, little, 999);
        if (ret != expected) {
            RETURN_ERROR("expected %p, got %p", expected, ret);
        }
    }

    {
        const char big[] = "";
        const char little[] = "hello";

        expected = NULL;
        ret = ft_strnstr(big, little, 999);
        if (ret != expected) {
            RETURN_ERROR("expected %p, got %p", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_len() {
    char *ret, *expected;

    {
        const char big[] = "Hello world";
        const char little[] = "ello";

        expected = (char *)(big + 1);
        ret = ft_strnstr(big, little, 5);
        if (ret != expected) {
            RETURN_ERROR("expected %p, got %p", expected, ret);
        }
    }

    {
        const char big[] = "Hello world";
        const char little[] = "ello";

        expected = NULL;
        ret = ft_strnstr(big, little, 4);
        if (ret != expected) {
            RETURN_ERROR("expected %p, got %p", expected, ret);
        }
    }

    {
        const char big[] = "Hello world";
        const char little[] = "";

        expected = (char *)big;
        ret = ft_strnstr(big, little, 0);
        if (ret != expected) {
            RETURN_ERROR("expected %p, got %p", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_strnstr() {
    RUN_UNIT_TESTS(test_found_unique, test_found_non_unique, test_not_found,
                   test_empty, test_len);
}
