#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_ascii() {
    for (int c = 0; c <= 127; c++) {
        if (!ft_isascii(c)) {
            RETURN_ERROR("value %d should be ascii", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_ascii1() {
    for (int c = -1000; c <= -1; c++) {
        if (ft_isascii(c)) {
            RETURN_ERROR("value %d should not be ascii", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_ascii2() {
    for (int c = 128; c <= 1000; c++) {
        if (ft_isascii(c)) {
            RETURN_ERROR("value %d should not be ascii", c);
        }
    }
    RETURN_SUCCESS();
}

Summary test_isascii() {
    RUN_UNIT_TESTS(test_ascii, test_non_ascii1, test_non_ascii2);
}
