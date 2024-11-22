NAME		:= a.out

BUILDDIR	:= build
SRCDIR		:= src
INCLUDE		:= include

SRCS		:= $(wildcard $(SRCDIR)/*.c)
OBJS		:= $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= clang
CFLAGS		:= -Wall -Wextra
CPPFLAGS	:= -I$(INCLUDE) -MMD -MP

LIBFTDIR=..

all: $(BUILDDIR)/$(NAME)

$(BUILDDIR)/$(NAME): $(OBJS) $(LIBFTDIR)/libft.a
	$(CC) $^ -o $(BUILDDIR)/$(NAME) $(LIBFTDIR)/libft.a

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)

re:
	$(MAKE) clean
	$(MAKE) all

$(LIBFTDIR)/libft.a:
	cd .. && $(MAKE) all

.PHONY: all clean re libft

-include $(DEPS)
