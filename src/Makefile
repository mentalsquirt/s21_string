NAME=s21_string

CC=gcc
CFLAGS=-Wall -pedantic -std=c11 $(shell pkg-config --cflags check)
TST_LIBS = $(shell pkg-config --libs check)

SRCS=s21_memchr.c \
			s21_memcmp.c \
			s21_memcpy.c \
			s21_memmove.c \
			s21_memset.c \
			s21_strcat.c \
			s21_strlen.c \
			s21_strcmp.c \
			s21_strcpy.c \
			s21_strchr.c \
			s21_strstr.c \
			s21_strtok.c \
			s21_strspn.c \
			s21_strpbrk.c
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

test: $(SRCS) s21_string.h
	$(CC) $(CFLAGS) $(TST_LIBS) $(SRCS) str_tests.c -o $(EXIT_PATH)$@
	$(EXIT_PATH)$@
	make fclean

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -rf $(NAME) $(NAME).dSYM test test.dSYM

re:
	make fclean
	make

.PHONY: $(NAME) all clean fclean re
