#include "libft.h"
#include "mm_testing.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static UnitTestResult *test_tmpfile() {
    FILE *tmp = tmpfile();
    int fd = fileno(tmp);
    char buf[80];
    memset(buf, '\0', 80);

    char expected[] = "Hello world";
    ft_putstr_fd(expected, fd);

    rewind(tmp);
    read(fd, buf, 80);
    if (strcmp(buf, expected) != 0) {
        RETURN_ERROR("expected \"%s\", got \"%s\"", expected, buf);
    }

    fclose(tmp);
    RETURN_SUCCESS();
}

Summary test_putstr_fd() {
    RUN_UNIT_TESTS(test_tmpfile);
}
