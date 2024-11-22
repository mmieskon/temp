#include "libft_tests.h"
#include "mm_testing.h"

// TODO: Testing library leaks memory
// TODO: If `RETURN_ERROR` macro includes escape characters, the length
//       of the string does not get counted properly (the escape backslash is
//       not counted in string length). This leads to undefined behavior

int main() {
    RUN_TESTS(test_isalpha, test_isdigit, test_isalnum, test_isascii,
              test_isprint, test_strlen, test_strchr, test_strrchr,
              test_strnstr, test_strlcpy, test_strlcat, test_atoi, test_toupper,
              test_tolower, test_bzero, test_memset, test_memcpy, test_memmove,
              test_memchr, test_memcmp, test_calloc, test_strdup,

              test_substr, test_strjoin, test_strtrim, test_split, test_itoa,
              test_strmapi, test_striteri, test_putchar_fd, test_putstr_fd,
              test_putendl_fd, test_putnbr_fd);
}
