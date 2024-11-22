#include "libft.h"
#include "libft_tests.h"
#include "mm_testing.h"

static UnitTestResult *test_digit() {
    for (int c = '0'; c <= '9'; c++) {
        if (!ft_isdigit(c)) {
            RETURN_ERROR("character '%c' should be digit", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_digit() {
    for (int c = 0; c <= 47; c++) {
        if (ft_isdigit(c)) {
            RETURN_ERROR("ascii code %d should not be digit", c);
        }
    }
    for (int c = 58; c <= 255; c++) {
        if (ft_isdigit(c)) {
            RETURN_ERROR("ascii code %d should not be digit", c);
        }
    }
    RETURN_SUCCESS();
}

Summary test_isdigit() {
    RUN_UNIT_TESTS(test_digit, test_non_digit);
}
