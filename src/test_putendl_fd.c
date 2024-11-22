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

    char input[] = "Hello world";
    char expected[] = "Hello world\n";
    ft_putendl_fd(input, fd);

    rewind(tmp);
    read(fd, buf, 80);
    if (strcmp(buf, expected) != 0) {
        RETURN_ERROR("expected \"%s\", got \"%s\\n\"", input, buf);
    }

    fclose(tmp);
    RETURN_SUCCESS();
}

Summary test_putendl_fd() {
    RUN_UNIT_TESTS(test_tmpfile);
}
