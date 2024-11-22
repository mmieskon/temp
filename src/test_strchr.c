#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_found_unique() {
    char str[] = "1234abcd@!\n\t";
    int len = sizeof(str) / sizeof(char) - 1;
    char *ret;
    for (int i = 0; i < len; i++) {
        ret = ft_strchr(str, str[i]);
        if (ret == NULL) {
            RETURN_ERROR("expected %p, got NULL", str + i);
        }
        if (ret != str + i) {
            RETURN_ERROR("expected %p, got %p", str + i, ret);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_found_non_unique() {
    char str[] = "1234abcd@!\n\t1234abcd@!\n\t1234abcd@!\n\t";
    int len = sizeof(str) / sizeof(char) - 1;
    int repeat_len = sizeof("1234abcd@!\n\t") / sizeof(char) - 1;
    char *ret;
    for (int i = 0; i < len; i++) {
        ret = ft_strchr(str, str[i]);
        if (ret == NULL) {
            RETURN_ERROR("expected %p, got NULL", str + i);
        }
        if (ret != str + (i % repeat_len)) {
            RETURN_ERROR("expected %p, got %p", str + i, ret);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_found_null_byte() {
    const int len = 10;
    char str[len];
    char *ret, *expected;
    for (int i = 0; i < len; i++) {
        memset(str, 'A', len);
        str[i] = '\0';
        expected = str + i;
        ret = ft_strchr(str, '\0');
        if (ret == NULL) {
            RETURN_ERROR("expected %p, got NULL", expected);
        }
        if (ret != expected) {
            RETURN_ERROR("expected %p, got %p", expected, ret);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_not_found() {
    char str[128];
    char *ret;
    char curr;
    // Store values in reverse to put terminating zero at the end
    for (int i = 0; i < 128; i++) {
        str[i] = 127 - i;
    }
    for (int i = 0; i < 127; i++) {
        curr = str[i];
        str[i] = -1;

        ret = ft_strchr(str, curr);
        if (ret != NULL) {
            RETURN_ERROR("expected NULL, got %p", ret);
        }
        str[i] = curr;
    }
    RETURN_SUCCESS();
}

Summary test_strchr() {
    RUN_UNIT_TESTS(test_found_unique, test_found_non_unique,
                   test_found_null_byte, test_not_found);
}
