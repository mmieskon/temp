#include "libft.h"
#include "mm_testing.h"
#include <string.h>

static UnitTestResult *test_empty() {
    char str[] = "";
    if (ft_strlen(str) != 0) {
        RETURN_ERROR("empty string should have a length of 0");
    }
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_empty() {
    const int MAX_TESTED_LEN = 50;
    char str[MAX_TESTED_LEN + 1];
    size_t ret;
    for (size_t i = 1; i < MAX_TESTED_LEN; i++) {
        memset(str, '\0', MAX_TESTED_LEN + 1);
        for (size_t j = 0; j < i; j++) {
            str[j] = 'A';
        }

        ret = ft_strlen(str);
        if (ret != i) {
            RETURN_ERROR("expected string length of %d, got %d", i, ret);
        }
    }
    RETURN_SUCCESS();
}

Summary test_strlen() {
    RUN_UNIT_TESTS(test_empty, test_non_empty);
}
