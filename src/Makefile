NAME=s21_string

CC=gcc
DEBUG=-g -DDEBUG
CFLAGS=-Wall -Werror -Wextra -pedantic

SRCS=s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_strcat.c s21_strlen.c s21_strcmp.c
OBJS=$(SRCS:.c=.o)

EXIT_PATH=./

all: $(NAME)

$(NAME): $(OBJS)
    $(CC) $(OBJS) -o $(EXIT_PATH)$@

%.o: %.c s21_string.h
    $(CC) $(CFLAGS) -c $< -o $@

s21_string.a: $(OBJS)
    ar rcs $@ $(OBJS)
    ranlib $@

static_lib: s21_string.a $(OBJS)
    $(CC) -L. s21_string.a -o $(EXIT_PATH)$(NAME)

clean:
    rm -f $(OBJS)

fclean:
    make clean
    rm -rf $(NAME) $(NAME).dSYM

re:
    make fclean
    make

.PHONY: $(NAME) all clean fclean re
