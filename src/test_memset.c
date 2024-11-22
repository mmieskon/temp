#include "libft.h"
#include "mm_testing.h"
#include <string.h>

static UnitTestResult *test_setting_values() {
    {
        const int size = 10;
        char arr[size];
        int c = 5;
        ft_memset(arr, c, size);
        for (int i = 0; i < size; i++) {
            if (arr[i] != c) {
                RETURN_ERROR("expected %d, got %d", c, arr[i]);
            }
        }
    }

    {
        const int size = 10;
        char arr[size];
        int c = 0;
        ft_memset(arr, c, size);
        for (int i = 0; i < size; i++) {
            if (arr[i] != c) {
                RETURN_ERROR("expected %d, got %d", c, arr[i]);
            }
        }
    }

    {
        const int size = 10;
        char arr[size];
        int c1 = 1;
        int c2 = 2;
        memset(arr, c2, 10);
        ft_memset(arr, c1, 5);
        for (int i = 0; i < 5; i++) {
            if (arr[i] != c1) {
                RETURN_ERROR("expected %d, got %d", c1, arr[i]);
            }
        }
        for (int i = 5; i < 10; i++) {
            if (arr[i] != c2) {
                RETURN_ERROR("expected %d, got %d", c2, arr[i]);
            }
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_return_value() {
    {
        const int size = 10;
        char arr[size];
        int c = 5;
        char *ret = ft_memset(arr, c, size);
        if (ret != arr) {
            RETURN_ERROR("expected %p, got %p", arr, ret);
        }
    }

    {
        const int size = 0;
        char arr[size];
        int c = 1;
        char *ret = ft_memset(arr, c, size);
        if (ret != arr) {
            RETURN_ERROR("expected %p, got %p", arr, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_memset() {
    RUN_UNIT_TESTS(test_setting_values, test_return_value);
}
