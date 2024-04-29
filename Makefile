CC = gcc

CFLAGS = -Wall -Wextra -g -Werror -Iinclude

NAME = printf.a

SRCS = src/dprint.c \
       src/print_b.c \
       src/strcpy.c \
       src/print_base.c \
       src/print_base10.c \
       src/print_c.c \
       src/print_d.c \
       src/print_o.c \
       src/print_x.c \
       src/print_p.c \
       src/print_pour.c \
       src/print_s.c \
       src/stu_strlen.c \

TEST = test/test_printf.c \

OBJS = $(SRCS:.c=.o)
TOBJS = $(TEST:.c=.o)
ALLBJS = $(OBJS) $(TOBJS)

all: $(NAME) ut.out

$(NAME): $(OBJS) test/test.main.o
	ar rc $(NAME) $(OBJS)
	$(CC) test/test.main.o $(NAME) -o printf_test.out

ut.out: $(ALLBJS)
	$(CC) -lcriterion $(ALLBJS) -o ut.out

fclean: clean
	@rm -vf $(NAME)
	@rm -vf ut.out
	@rm -vf printf_test.out

clean:
	@rm -vf $(ALLBJS)

re: fclean all

.PHONY: all fclean clean
