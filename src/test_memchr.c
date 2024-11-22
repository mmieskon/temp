#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_unique() {
    {
        char arr[] = "ABCDEF1234\n\t";
        int len = strlen(arr);
        char *ret, *expected;
        for (int i = 0; i < len; i++) {
            ret = ft_memchr(arr, arr[i], len);
            expected = arr + i;
            if (ret != expected) {
                RETURN_ERROR("expected %p, got %p", expected, ret);
            }
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_non_unique() {
    {
        char arr[] = "ABCDEF1234\n\tABCDEF1234\n\tABCDEF1234\n\t";
        int len = 12;
        char *ret, *expected;
        for (int i = 0; i < len; i++) {
            ret = ft_memchr(arr, arr[i], len);
            expected = arr + i;
            if (ret != expected) {
                RETURN_ERROR("expected %p, got %p", expected, ret);
            }
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_not_found() {
    {
        char arr[] = "0123456789";
        int len = strlen(arr);
        char *ret = ft_memchr(arr, 'A', len);
        if (ret != NULL) {
            RETURN_ERROR("expected NULL, got %p", ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_count() {
    {
        char arr[] = "123456789";
        int len = 5;
        char *ret = ft_memchr(arr, '5', len);
        if (ret == NULL) {
            RETURN_ERROR("did not expect NULL");
        }
    }

    {
        char arr[] = "123456789";
        int len = 4;
        char *ret = ft_memchr(arr, '5', len);
        if (ret != NULL) {
            RETURN_ERROR("expected NULL");
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_only_one_byte() {
    char str[] = "helou";
    char *ret = ft_memchr(str, 0xff68, 5);
    if (ret != str) {
        RETURN_ERROR("function should interpret input value as one byte");
    }

    RETURN_SUCCESS();
}

Summary test_memchr() {
    RUN_UNIT_TESTS(test_unique, test_non_unique, test_not_found, test_count,
                   test_only_one_byte);
}
