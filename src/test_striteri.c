#include "libft.h"
#include "mm_testing.h"

static void identity(unsigned int unused, char *c) {
    (void)unused;
    (void)c;
}

static void plus_one(unsigned int unused, char *c) {
    (void)unused;
    *c += 1;
}

static void plus_index(unsigned int i, char *c) {
    *c += i;
}

static UnitTestResult *test_identity() {
    {
        char orig[] = "Hello world";
        char expected[] = "Hello world";
        ft_striteri(orig, identity);
        if (strcmp(orig, expected) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, orig);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_no_include_index() {
    {
        char orig[] = "ABCDEF";
        char expected[] = "BCDEFG";
        ft_striteri(orig, plus_one);
        if (strcmp(orig, expected) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, orig);
        }
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_include_index() {
    {
        char orig[] = "AAAB";
        char expected[] = "ABCE";
        ft_striteri(orig, plus_index);
        if (strcmp(orig, expected) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, orig);
        }
    }

    RETURN_SUCCESS();
}

Summary test_striteri() {
    RUN_UNIT_TESTS(test_identity, test_no_include_index, test_include_index);
}
