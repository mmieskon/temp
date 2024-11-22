#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_digit() {
    for (int c = '0'; c <= '9'; c++) {
        if (!ft_isdigit(c)) {
            RETURN_ERROR("character '%c' should be digit", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_lowercase() {
    for (int c = 'a'; c <= 'z'; c++) {
        if (!ft_isalnum(c)) {
            RETURN_ERROR("character '%c' should be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_uppercase() {
    for (int c = 'A'; c <= 'Z'; c++) {
        if (!ft_isalnum(c)) {
            RETURN_ERROR("character '%c' should be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_alnum1() {
    for (int c = 0; c <= 47; c++) {
        if (ft_isalnum(c)) {
            RETURN_ERROR("ascii code %d should not be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_alnum2() {
    for (int c = 58; c <= 64; c++) {
        if (ft_isalnum(c)) {
            RETURN_ERROR("ascii code %d should not be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_alnum3() {
    for (int c = 91; c <= 96; c++) {
        if (ft_isalnum(c)) {
            RETURN_ERROR("ascii code %d should not be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_alnum4() {
    for (int c = 123; c <= 255; c++) {
        if (ft_isalnum(c)) {
            RETURN_ERROR("ascii code %d should not be alpha", c);
        }
    }
    RETURN_SUCCESS();
}

Summary test_isalnum() {
    RUN_UNIT_TESTS(test_digit, test_lowercase, test_uppercase, test_non_alnum1,
                   test_non_alnum2, test_non_alnum3, test_non_alnum4);
}
