#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_printable() {
    for (int c = 32; c <= 126; c++) {
        if (!ft_isprint(c)) {
            RETURN_ERROR("character '%c' should be printable", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_printable1() {
    for (int c = 0; c <= 31; c++) {
        if (ft_isprint(c)) {
            RETURN_ERROR("value %d should not be printable", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_printable2() {
    for (int c = 127; c <= 255; c++) {
        if (ft_isprint(c)) {
            RETURN_ERROR("value %d should not be printable", c);
        }
    }
    RETURN_SUCCESS();
}

Summary test_isprint() {
    RUN_UNIT_TESTS(test_printable, test_non_printable1, test_non_printable2);
}
