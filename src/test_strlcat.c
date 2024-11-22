#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_full_cat() {
    {
        char dst[7] = "ABC";
        char src[] = "abc";
        char expected[] = "ABCabc";
        int combined_len = strlen(dst) + strlen(src) + 1;

        ft_strlcat(dst, src, combined_len);
        if (strncmp(dst, expected, sizeof(expected)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
        }
    }

    {
        char dst[7] = "ABC";
        char src[] = "abc";
        char expected[] = "ABCabc";

        ft_strlcat(dst, src, 999);
        if (strncmp(dst, expected, sizeof(expected)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_partial_cat() {
    {
        char dst[7] = "ABC";
        char src[] = "abc";
        char expected[] = "ABCa";
        int combined_len = strlen(dst) + strlen(src) + 1;

        ft_strlcat(dst, src, combined_len - 2);
        if (strncmp(dst, expected, sizeof(expected)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
        }
    }

    {
        char dst[8] = "ABCD";
        char src[] = "abc";
        char expected[] = "ABCDab";
        int combined_len = strlen(dst) + strlen(src) + 1;

        ft_strlcat(dst, src, combined_len - 1);
        if (strncmp(dst, expected, sizeof(expected)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_bufsize_zero() {
    char dst[] = "ABC";
    char src[] = "abc";
    char expected[] = "ABC";

    ft_strlcat(dst, src, 0);
    if (strncmp(dst, expected, sizeof(expected)) != 0) {
        RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_bufsize_one() {
    {
        char dst[] = "ABC";
        char src[] = "abc";
        char expected[] = "ABC";

        ft_strlcat(dst, src, 1);
        if (strncmp(dst, expected, sizeof(expected)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
        }
    }

    {
        char dst[] = "";
        char src[] = "abc";
        char expected[] = "";

        ft_strlcat(dst, src, 1);
        if (strncmp(dst, expected, sizeof(expected)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_strlen_zero() {
    char dst[] = "ABC";
    char src[] = "";
    char expected[] = "ABC";

    ft_strlcat(dst, src, 999);
    if (strncmp(dst, expected, sizeof(expected)) != 0) {
        RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_return_value() {
    {
        char dst[999] = "ABC";
        char src[] = "abc";

        size_t expected = strlen(dst) + strlen(src);
        size_t ret = ft_strlcat(dst, src, 999);
        if (ret != expected) {
            RETURN_ERROR("expected %lu, got %lu", expected, ret);
        }
    }

    {
        char dst[999] = "ABC";
        char src[] = "abcde";

        size_t expected = strlen(dst) + strlen(src);
        size_t ret = ft_strlcat(dst, src, 999);
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_strlcat() {
    RUN_UNIT_TESTS(test_full_cat, test_partial_cat, test_bufsize_zero,
                   test_bufsize_one, test_strlen_zero, test_return_value);
}
