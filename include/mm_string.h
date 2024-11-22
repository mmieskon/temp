#pragma once

#include <stdio.h>
#include <string.h>

// `char *data` is null-terminated
// `len` does not count the null-terminating character
// `cap` is always at least `len + 1`
typedef struct {
    char *data;
    int len;
    int cap;
} String;

String string_from_cstr(const char *str);
void string_drop(String *string);
