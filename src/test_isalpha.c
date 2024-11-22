#include "libft.h"
#include "libft_tests.h"
#include "mm_testing.h"

#include <limits.h>

static UnitTestResult *test_lowercase() {
    for (int c = 'a'; c <= 'z'; c++) {
        if (!ft_isalpha(c)) {
            RETURN_ERROR("character '%c' should be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_uppercase() {
    for (int c = 'A'; c <= 'Z'; c++) {
        if (!ft_isalpha(c)) {
            RETURN_ERROR("character '%c' should be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_alpha1() {
    for (int c = 0; c <= 64; c++) {
        if (ft_isalpha(c)) {
            RETURN_ERROR("ascii code %d should not be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_alpha2() {
    for (int c = 91; c <= 96; c++) {
        if (ft_isalpha(c)) {
            RETURN_ERROR("ascii code %d should not be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_alpha3() {
    for (int c = 123; c <= 255; c++) {
        if (ft_isalpha(c)) {
            RETURN_ERROR("ascii code %d should not be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

Summary test_isalpha() {
    RUN_UNIT_TESTS(test_uppercase, test_lowercase, test_non_alpha1,
                   test_non_alpha2, test_non_alpha3);
}
