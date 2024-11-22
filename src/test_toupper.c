#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_lowercase() {
    int ret, expected;
    for (int i = 0; i < ('z' - 'a' + 1); i++) {
        ret = ft_toupper('a' + i);
        expected = 'A' + i;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_non_lowercase1() {
    int ret, expected;
    for (int c = 0; c < 97; c++) {
        ret = ft_toupper(c);
        expected = c;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_non_lowercase2() {
    int ret, expected;
    for (int c = 123; c <= 255; c++) {
        ret = ft_toupper(c);
        expected = c;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_toupper() {
    RUN_UNIT_TESTS(test_lowercase, test_non_lowercase1, test_non_lowercase2);
}
