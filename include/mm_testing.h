#pragma once

#include "mm_string.h"
#include <stdbool.h>

typedef struct {
    String test_name;
    bool success;
    String err_msg;
    int line;
} UnitTestResult;

typedef struct {
    int success_count;
    int total_count;
} Summary;

// Creates a heap allocated pointer to a test result
UnitTestResult *test_result_new(const char *name, int line, bool success,
                                const char *err_msg, ...);

// Consumes all the passed heap allocated pointers and frees them
Summary run_unit_tests(const char *test_name, UnitTestResult *(*unit_tests[])(),
                       int len);
void run_tests(Summary (*tests[])(), int len);

#define RETURN_SUCCESS() return test_result_new(__func__, __LINE__, true, "")
#define RETURN_ERROR(msg, ...)                                                 \
    return test_result_new(__func__, __LINE__, false, msg, ##__VA_ARGS__);
#define RUN_UNIT_TESTS(...)                                                    \
    UnitTestResult *(*tests[])() = {__VA_ARGS__};                              \
    return run_unit_tests(__func__, tests, sizeof(tests) / sizeof(tests[0]));
#define RUN_TESTS(...)                                                         \
    Summary (*tests[])() = {__VA_ARGS__};                                      \
    run_tests(tests, sizeof(tests) / sizeof(tests[0]));
