#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_copying() {
    {
        char dst[] = "AAAAAxx";
        char src[] = "BBBBB";
        int dst_len = 7;
        int src_len = 5;
        ft_memcpy(dst, src, src_len);
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
        ft_memcpy(dst, src, src_len);
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

static UnitTestResult *test_return_value() {
    {
        char dst[] = "AAAAA";
        char src[] = "BBBBB";
        int size = 5;
        char *ret = ft_memcpy(dst, src, size);
        if (ret != dst) {
            RETURN_ERROR("expected %p, got %p", dst, ret);
        }
    }

    {
        char dst[] = "";
        char src[] = "";
        int size = 0;
        char *ret = ft_memcpy(dst, src, size);
        if (ret != dst) {
            RETURN_ERROR("expected %p, got %p", dst, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_memcpy() {
    RUN_UNIT_TESTS(test_copying, test_return_value);
}
