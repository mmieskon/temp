#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_uppercase() {
    int ret, expected;
    for (int i = 0; i < ('Z' - 'A' + 1); i++) {
        ret = ft_tolower('A' + i);
        expected = 'a' + i;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_non_uppercase1() {
    int ret, expected;
    for (int c = 0; c < 65; c++) {
        ret = ft_tolower(c);
        expected = c;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_non_uppercase2() {
    int ret, expected;
    for (int c = 91; c <= 255; c++) {
        ret = ft_tolower(c);
        expected = c;
        if (ret != expected) {
            RETURN_ERROR("expected %d, got %d", expected, ret);
        }
    }

    RETURN_SUCCESS();
}

Summary test_tolower() {
    RUN_UNIT_TESTS(test_uppercase, test_non_uppercase1, test_non_uppercase2);
}
