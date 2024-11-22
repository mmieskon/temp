#include "libft.h"
#include "mm_testing.h"

static UnitTestResult *test_full_substring() {
    {
        char orig[] = "Hello world :)";
        char expected[] = "world";
        int len = strlen(expected);
        int start = 6;
        char *new = ft_substr(orig, start, len);
        if (strncmp(expected, new, len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, new);
        }
        free(new);
    }

    {
        char orig[] = "Hello world :)";
        char expected[] = "Hello";
        int len = strlen(expected);
        int start = 0;
        char *new = ft_substr(orig, start, len);
        if (strncmp(expected, new, len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, new);
        }
        free(new);
    }

    {
        char orig[] = "Hello world :)";
        char expected[] = ":)";
        int len = strlen(expected);
        int start = 12;
        char *new = ft_substr(orig, start, len);
        if (strncmp(expected, new, len + 1) != 0) {
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, new);
        }
        free(new);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_partial_substring() {
    {
        char orig[] = "Hello world :)";
        char expected[] = "world :)";
        int len = 999;
        int start = 6;
        char *new = ft_substr(orig, start, len);
        if (strncmp(expected, new, len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, new);
        }
        free(new);
    }

    {
        char orig[] = "Hello world :)";
        char expected[] = "Hello world :)";
        int len = 999;
        int start = 0;
        char *new = ft_substr(orig, start, len);
        if (strncmp(expected, new, len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, new);
        }
        free(new);
    }

    {
        char orig[] = "Hello world :)";
        char expected[] = ":)";
        int len = 999;
        int start = 12;
        char *new = ft_substr(orig, start, len);
        if (strncmp(expected, new, len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, new);
        }
        free(new);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_empty_substring() {
    {
        char orig[] = "Hello world :)";
        char expected[] = "";
        int len = 0;
        int start = 12;
        char *new = ft_substr(orig, start, len);
        if (strncmp(expected, new, len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, new);
        }
        free(new);
    }

    {
        char orig[] = "Hello world :)";
        char expected[] = "";
        int len = 999;
        int start = 14;
        char *new = ft_substr(orig, start, len);
        if (strncmp(expected, new, len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, new);
        }
        free(new);
    }

    RETURN_SUCCESS();
}

Summary test_substr() {
    RUN_UNIT_TESTS(test_full_substring, test_partial_substring,
                   test_empty_substring);
}
