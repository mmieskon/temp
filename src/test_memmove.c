#include "libft.h"
#include "mm_testing.h"
#include <string.h>

static UnitTestResult *test_non_overlapping() {
    {
        char dst[] = "AAAAAxx";
        char src[] = "BBBBB";
        int dst_len = 7;
        int src_len = 5;
        ft_memmove(dst, src, src_len);
        for (int i = 0; i < src_len; i++) {
            if (dst[i] != 'B') {
                RETURN_ERROR("expected 'B', got '%c'", dst[i]);
            }
        }
        for (int i = src_len; i < dst_len; i++) {
            if (dst[i] != 'x') {
                RETURN_ERROR("expected 'x', got '%c'", dst[i]);
            }
        }
    }

    {
        char dst[] = "AAAAAAAAAAxx";
        char src[] = "0123456789";
        int dst_len = 12;
        int src_len = 10;
        ft_memmove(dst, src, src_len);
        char expected;
        for (int i = 0; i < src_len; i++) {
            expected = '0' + i;
            if (dst[i] != expected) {
                RETURN_ERROR("expected '%c', got '%c'", expected, dst[i]);
            }
        }
        for (int i = src_len; i < dst_len; i++) {
            if (dst[i] != 'x') {
                RETURN_ERROR("expected 'x', got '%c'", dst[i]);
            }
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_overlapping() {
    {
        char arr[] = "ABCDEFxx";
        char *dst = arr + 2;
        char *src = arr;
        ft_memmove(dst, src, 4);
        if (memcmp(arr, "ABABCDxx", 8) != 0) {
            RETURN_ERROR("unexpected result");
        }
    }

    {
        char arr[] = "ABCDEFxx";
        char *dst = arr;
        char *src = arr + 2;
        ft_memmove(dst, src, 4);
        if (memcmp(arr, "CDEFEFxx", 8) != 0) {
            RETURN_ERROR("unexpected result");
        }
    }

    {
        char arr[] = "ABCDEFxx";
        char *dst = arr;
        char *src = arr;
        ft_memmove(dst, src, 6);
        if (memcmp(arr, "ABCDEFxx", 8) != 0) {
            RETURN_ERROR("unexpected result");
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_return_value() {
    char dst[] = "AAAAAxx";
    char src[] = "BBBBB";
    char *expected, *ret;
    int src_len = 5;
    ret = ft_memmove(dst, src, src_len);
    expected = dst;
    if (ret != expected) {
        RETURN_ERROR("expected %p, got %p", expected, ret);
    }

    RETURN_SUCCESS();
}

Summary test_memmove() {
    RUN_UNIT_TESTS(test_non_overlapping, test_overlapping, test_return_value);
}
