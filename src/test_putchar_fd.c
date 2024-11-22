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

    ft_putchar_fd('a', fd);

    rewind(tmp);
    read(fd, buf, 80);
    if (strcmp(buf, "a") != 0) {
        RETURN_ERROR("expected \"a\", got \"%s\"", buf);
    }

    fclose(tmp);
    RETURN_SUCCESS();
}

Summary test_putchar_fd() {
    RUN_UNIT_TESTS(test_tmpfile);
}
