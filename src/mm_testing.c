#include "mm_testing.h"
#include "mm_string.h"
#include <stdarg.h>
#include <stdlib.h>

#define COLOR_RED "\e[31m"
#define COLOR_GREEN "\e[32m"
#define COLOR_YELLOW "\e[33m"
#define COLOR_RESET "\e[0m"

typedef struct {
    UnitTestResult **data;
    int len;
    int cap;
} VecTestResult;

UnitTestResult *test_result_new(const char *name, int line, bool success,
                                const char *err_msg, ...) {
    UnitTestResult *ret = malloc(1 * sizeof(UnitTestResult));
    ret->test_name = string_from_cstr(name);
    ret->success = success;
    ret->line = line;

    char buf[1000]; // TODO: How to not fix the max size of error message?
    va_list args;
    va_start(args, err_msg);
    vsprintf(buf, err_msg, args);
    va_end(args);

    ret->err_msg = string_from_cstr(buf);
    return ret;
}

static void test_result_drop(UnitTestResult *test_result) {
    string_drop(&test_result->test_name);
    string_drop(&test_result->err_msg);
    free(test_result);
}

static VecTestResult vec_test_result_new() {
    VecTestResult ret;
    ret.len = 0;
    ret.cap = 1;
    ret.data = malloc(ret.cap * sizeof(UnitTestResult));
    return ret;
}

static void vec_test_result_drop(VecTestResult *results) {
    for (int i = 0; i < results->len; i++) {
        test_result_drop(results->data[i]);
    }
    free(results->data);
}

static void vec_test_result_push(VecTestResult *self, UnitTestResult *result) {
    if (self->len == self->cap) {
        self->cap *= 2;
        self->data = realloc(self->data, self->cap * sizeof(UnitTestResult));
    }
    self->data[self->len] = result;
    self->len++;
}

Summary run_unit_tests(const char *test_name, UnitTestResult *(*tests[])(),
                       int len) {
    Summary ret;
    VecTestResult results = vec_test_result_new();
    UnitTestResult *result;
    for (int i = 0; i < len; i++) {
        result = tests[i]();
        vec_test_result_push(&results, result);
    }

    int longest_name = 0;
    int curr;
    for (int i = 0; i < results.len; i++) {
        curr = strlen(results.data[i]->test_name.data);
        if (curr > longest_name) {
            longest_name = curr;
        }
    }

    int space_count;
    printf("%s:\n", test_name);
    for (int i = 0; i < results.len; i++) {
        char *name = results.data[i]->test_name.data;
        bool success = results.data[i]->success;
        char *err_msg = results.data[i]->err_msg.data;
        int line = results.data[i]->line;

        curr = strlen(name);
        space_count = longest_name + 5 - curr;

        printf("    %s: ", name);
        if (success) {
            printf("%*sOk%s\n", space_count, COLOR_GREEN, COLOR_RESET);
        } else {
            printf("%*sErr%s", space_count, COLOR_RED, COLOR_RESET);
            if (strlen(err_msg) != 0) {
                printf(": %s %s[line: %d]%s", err_msg, COLOR_YELLOW, line,
                       COLOR_RESET);
            }
            printf("\n");
        }
    };
    printf("\n");
    ret.total_count = results.len;
    ret.success_count = 0;
    for (int i = 0; i < results.len; i++) {
        if (results.data[i]->success) {
            ret.success_count++;
        }
    }
    vec_test_result_drop(&results);
    return ret;
}

void run_tests(Summary (*tests[])(), int len) {
    Summary summary;
    int combined_success_count = 0;
    int combined_total_count = 0;
    for (int i = 0; i < len; i++) {
        summary = tests[i]();
        combined_success_count += summary.success_count;
        combined_total_count += summary.total_count;
    }
    printf("================\n");
    printf("Summary: ");
    if (combined_success_count == combined_total_count) {
        printf("%sPass%s, (%d/%d) unit tests passed!\n", COLOR_GREEN,
               COLOR_RESET, combined_success_count, combined_total_count);
    } else {
        printf("%sFail%s, (%d/%d) unit tests passed!\n", COLOR_RED, COLOR_RESET,
               combined_success_count, combined_total_count);
    }
    printf("\n");
}
