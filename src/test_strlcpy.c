#include "libft.h"
#include "mm_testing.h"
#include <string.h>

static UnitTestResult *test_full_copy() {
    {
#define DST_SIZE 4
        char dst[DST_SIZE] = "ABC";
        char src[] = "abc";
        ft_strlcpy(dst, src, DST_SIZE);
        if (strncmp(dst, src, sizeof(src)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", src, dst);
        }
    }

    {
#undef DST_SIZE
#define DST_SIZE 5
        char dst[DST_SIZE] = "ABC";
        char src[] = "abcd";
        ft_strlcpy(dst, src, DST_SIZE);
        if (strncmp(dst, src, sizeof(src)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", src, dst);
        }
    }

    {
#undef DST_SIZE
#define DST_SIZE 999
        char dst[DST_SIZE] = "ABC";
        char src[] = "ab";
        ft_strlcpy(dst, src, DST_SIZE);
        if (strncmp(dst, src, sizeof(src)) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", src, dst);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_partial_copy() {
    {
        char dst[] = "ABC";
        const int dst_size = sizeof(dst);
        char src[] = "abcdefg";
        char expected[] = "abc";
        ft_strlcpy(dst, src, dst_size);
        if (strncmp(dst, expected, dst_size) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
        }
    }

    {
        char dst[] = "ABCDEFG";
        char src[] = "abcd";
        const int dst_size = 2;
        ft_strlcpy(dst, src, dst_size);
        src[dst_size - 1] = '\0';
        if (strncmp(dst, src, strlen(src) + 1) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", src, dst);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_bufsize_zero() {
    {
        char dst[] = "ABCD";
        char src[] = "abc";

        ft_strlcpy(dst, src, 0);
        if (strncmp(dst, "ABCD", sizeof("ABCD")) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", "ABCD", dst);
        }
    }

    {
        char dst[] = "";
        char src[] = "asdf";

        ft_strlcpy(dst, src, 0);
        if (strncmp(dst, "", sizeof("")) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", "", dst);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_bufsize_one() {
    char dst[] = "ABCD";
    char src[] = "abcd";
    char expected[] = "";

    ft_strlcpy(dst, src, 1);
    if (strncmp(dst, expected, sizeof(expected)) != 0) {
        RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_strlen_zero() {
    char dst[] = "ABCD";
    char src[] = "";
    char expected[] = "";

    const int dst_len = sizeof(dst);
    ft_strlcpy(dst, src, dst_len);

    if (strncmp(dst, expected, sizeof(expected)) != 0) {
        RETURN_ERROR("expected \"%s\", got \"%s\"", expected, dst);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_return_value() {
    const int dst_size = 999;
    char dst[dst_size];
    size_t ret, expected;

    {
        char src[] = "hello";
        expected = strlen(src);
        ret = ft_strlcpy(dst, src, dst_size);
        if (ret != expected) {
            RETURN_ERROR("expected %lu, got %lu", expected, ret);
        }
    }

    {
        char src[] = "";
        expected = strlen(src);
        ret = ft_strlcpy(dst, src, dst_size);
        if (ret != expected) {
            RETURN_ERROR("expected %lu, got %lu", expected, ret);
        }
    }

    {
        char src[] = "jou";
        expected = strlen(src);
        ret = ft_strlcpy(dst, src, 0);
        if (ret != expected) {
            RETURN_ERROR("expected %lu, got %lu", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_strlcpy() {
    RUN_UNIT_TESTS(test_full_copy, test_partial_copy, test_bufsize_zero,
                   test_bufsize_one, test_strlen_zero, test_return_value);
}
