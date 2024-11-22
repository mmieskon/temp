#include "libft.h"
#include "mm_testing.h"

static char identity(unsigned int unused, char c) {
    (void)unused;
    return c;
}

static char plus_one(unsigned int unused, char c) {
    (void)unused;
    return c + 1;
}

static char plus_index(unsigned int i, char c) {
    return c + i;
}

static UnitTestResult *test_identity() {
    {
        char orig[] = "Hello world";
        char expected[] = "Hello world";
        char *ret = ft_strmapi(orig, identity);
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_no_include_index() {
    {
        char orig[] = "ABCDEF";
        char expected[] = "BCDEFG";
        char *ret = ft_strmapi(orig, plus_one);
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_include_index() {
    {
        char orig[] = "AAAB";
        char expected[] = "ABCE";
        char *ret = ft_strmapi(orig, plus_index);
        if (strcmp(ret, expected) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

Summary test_strmapi() {
    RUN_UNIT_TESTS(test_identity, test_no_include_index, test_include_index);
}
