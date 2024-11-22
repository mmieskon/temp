#include "libft.h"
#include "mm_testing.h"
#include <string.h>

static UnitTestResult *test_trim_char() {
    {
        char str[] = "   Hello world   ";
        char set[] = " ";
        char expected[] = "Hello world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strtrim(str, set);
        if (strncmp(expected, ret, expected_len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    {
        char str[] = "Hello world   ";
        char set[] = " ";
        char expected[] = "Hello world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strtrim(str, set);
        if (strncmp(expected, ret, expected_len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    {
        char str[] = " Hello world";
        char set[] = " ";
        char expected[] = "Hello world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strtrim(str, set);
        if (strncmp(expected, ret, expected_len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_trim_set() {
    {
        char str[] = " \tHello world\t   \n";
        char set[] = " \t\n";
        char expected[] = "Hello world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strtrim(str, set);
        if (strncmp(expected, ret, expected_len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    {
        char str[] = "Hello world\t   \n";
        char set[] = " \t\n";
        char expected[] = "Hello world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strtrim(str, set);
        if (strncmp(expected, ret, expected_len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            // TODO: Error message looks weird, seems like there is a problem
            //       with the testing framework where the length of the string
            //       gets counted wrong if it contains backslashes
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    {
        char str[] = "\n\n\tHello world";
        char set[] = " \t\n";
        char expected[] = "Hello world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strtrim(str, set);
        if (strncmp(expected, ret, expected_len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

// static UnitTestResult *test_trim_all() {
//     {
//         char str[] = "Hello world";
//         char set[] = "Hello world";
//         char *ret = ft_strtrim(str, set);
//         if (ret != NULL) {
//             RETURN_ERROR("expected NULL (NOTE: Could also return a pointer "
//                          "with allocated size of 0)");
//         }
//     }
// 
//     RETURN_SUCCESS();
// }

// static UnitTestResult *test_empty_string() {
//     {
//         char str[] = "";
//         char set[] = " \t\n";
//         char *ret = ft_strtrim(str, set);
//         if (ret != NULL) {
//             RETURN_ERROR("expected NULL (NOTE: Could also return a pointer "
//                          "with allocated size of 0)");
//         }
//     }
// 
//     RETURN_SUCCESS();
// }

static UnitTestResult *test_empty_set() {
    {
        char str[] = "Hello world";
        char set[] = "";
        char expected[] = "Hello world";
        size_t expected_len = strlen(expected);
        char *ret = ft_strtrim(str, set);
        if (strncmp(expected, ret, expected_len + 1) != 0) {
            // TODO: Leaks memory here if test failed
            RETURN_ERROR("expected \"%s\", got \"%s\"", expected, ret);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

// TODO: What to do with `test_trim_all` and `test_empty_string`
Summary test_strtrim() {
    RUN_UNIT_TESTS(test_trim_char, test_trim_set, /* test_trim_all, */
                   /* test_empty_string, */ test_empty_set);
}
