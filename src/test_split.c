#include "libft.h"
#include "mm_testing.h"

static size_t word_count(char **arr) {
    int ret = 0;
    while (arr[ret] != NULL) {
        ret++;
    }
    return ret;
}

static UnitTestResult *test_trim_none() {
    {
        char orig[] = "Hello world, hello worlds";
        char expected[][80] = {
            "Hello",
            "world,",
            "hello",
            "worlds",
        };
        size_t expected_len = sizeof(expected) / sizeof(expected[0]);
        char **ret = ft_split(orig, ' ');
        size_t w_count = word_count(ret);
        if (w_count != expected_len) {
            RETURN_ERROR("expected word count of %d, got %d", expected_len,
                         w_count);
        }
        for (size_t i = 0; i < w_count; i++) {
            if (strncmp(ret[i], expected[i], 80) != 0) {
                RETURN_ERROR("expected \"%s\", got \"%s\"", expected[i],
                             ret[i]);
            }
        }

        for (size_t i = 0; i < w_count; i++) {
            free(ret[i]);
        }
        free(ret);
    }

    {
        char orig[] = "Hello   world,  hello      worlds";
        char expected[][80] = {
            "Hello",
            "world,",
            "hello",
            "worlds",
        };
        size_t expected_len = sizeof(expected) / sizeof(expected[0]);
        char **ret = ft_split(orig, ' ');
        size_t w_count = word_count(ret);
        if (w_count != expected_len) {
            RETURN_ERROR("expected word count of %d, got %d", expected_len,
                         w_count);
        }
        for (size_t i = 0; i < w_count; i++) {
            if (strncmp(ret[i], expected[i], 80) != 0) {
                RETURN_ERROR("expected \"%s\", got \"%s\"", expected[i],
                             ret[i]);
            }
        }

        for (size_t i = 0; i < w_count; i++) {
            free(ret[i]);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_trim_front() {
    {
        char orig[] = "    Hello world,   hello worlds";
        char expected[][80] = {
            "Hello",
            "world,",
            "hello",
            "worlds",
        };
        size_t expected_len = sizeof(expected) / sizeof(expected[0]);
        char **ret = ft_split(orig, ' ');
        size_t w_count = word_count(ret);
        if (w_count != expected_len) {
            RETURN_ERROR("expected word count of %d, got %d", expected_len,
                         w_count);
        }
        for (size_t i = 0; i < w_count; i++) {
            if (strncmp(ret[i], expected[i], 80) != 0) {
                RETURN_ERROR("expected \"%s\", got \"%s\"", expected[i],
                             ret[i]);
            }
        }

        for (size_t i = 0; i < w_count; i++) {
            free(ret[i]);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_trim_back() {
    {
        char orig[] = "Hello world,   hello worlds  ";
        char expected[][80] = {
            "Hello",
            "world,",
            "hello",
            "worlds",
        };
        size_t expected_len = sizeof(expected) / sizeof(expected[0]);
        char **ret = ft_split(orig, ' ');
        size_t w_count = word_count(ret);
        if (w_count != expected_len) {
            RETURN_ERROR("expected word count of %d, got %d", expected_len,
                         w_count);
        }
        for (size_t i = 0; i < w_count; i++) {
            if (strncmp(ret[i], expected[i], 80) != 0) {
                RETURN_ERROR("expected \"%s\", got \"%s\"", expected[i],
                             ret[i]);
            }
        }

        for (size_t i = 0; i < w_count; i++) {
            free(ret[i]);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_trim_both() {
    {
        char orig[] = "    Hello world,   hello worlds  ";
        char expected[][80] = {
            "Hello",
            "world,",
            "hello",
            "worlds",
        };
        size_t expected_len = sizeof(expected) / sizeof(expected[0]);
        char **ret = ft_split(orig, ' ');
        size_t w_count = word_count(ret);
        if (w_count != expected_len) {
            RETURN_ERROR("expected word count of %d, got %d", expected_len,
                         w_count);
        }
        for (size_t i = 0; i < w_count; i++) {
            if (strncmp(ret[i], expected[i], 80) != 0) {
                RETURN_ERROR("expected \"%s\", got \"%s\"", expected[i],
                             ret[i]);
            }
        }

        for (size_t i = 0; i < w_count; i++) {
            free(ret[i]);
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

static UnitTestResult *test_empty() {
    {
        char orig[] = "";
        char **ret = ft_split(orig, ' ');
        if (ret[0] != NULL) {
            RETURN_ERROR("expected array with single element containing NULL");
        }
        free(ret);
    }

    {
        char orig[] = "     ";
        char **ret = ft_split(orig, ' ');
        if (ret[0] != NULL) {
            RETURN_ERROR("expected array with single element containing NULL");
        }
        free(ret);
    }

    RETURN_SUCCESS();
}

Summary test_split() {
    RUN_UNIT_TESTS(test_trim_none, test_trim_front, test_trim_back,
                   test_trim_both, test_empty);
}
