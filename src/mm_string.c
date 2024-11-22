#include "mm_string.h"
#include <stdio.h>
#include <stdlib.h>

String string_from_cstr(const char *str) {
    String ret;
    size_t len = strlen(str);
    ret.len = len;
    ret.cap = len + 1;
    ret.data = malloc(ret.cap * sizeof(char));
    for (int i = 0; i < ret.len; i++) {
        ret.data[i] = str[i];
    }
    ret.data[len] = '\0';
    return ret;
}

void string_drop(String *string) {
    free(string->data);
}
