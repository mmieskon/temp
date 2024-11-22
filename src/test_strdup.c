#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_empty() {
    char expected[] = "";
    char *ret = ft_strdup(expected);
    if (strcmp(expected, ret) != 0) {
        // TODO: Memory leak if test failed
        RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
    }
    free(ret);
    RETURN_SUCCESS();
}

static UnitTestResult *test_non_empty() {
    char expected[] = "Hello world";
    char *ret = ft_strdup(expected);
    if (strcmp(expected, ret) != 0) {
        // TODO: Memory leak if test failed
        RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
    }
    free(ret);
    RETURN_SUCCESS();
}

Summary test_strdup() {
    RUN_UNIT_TESTS(test_empty, test_non_empty);
}
