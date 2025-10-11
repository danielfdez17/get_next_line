NAME = a.out

SRCS = get_next_line.c \
		get_next_line_utils.c

INCS = get_next_line.h

OBJS = $(SRCS:.c=.o)

CCW = cc -Wall -Wextra -Werror

SANITIZE = -fsanitize=address -g

AR = ar -rcs

%.o: %.c
	$(CCW) -c $< -o $@ -I INCS

all: $(NAME)

$(NAME): $(OBJS) $(INCS) -o $(NAME)

clean: rm $(OBJS) $(NAME)

run: all 
	./$(NAME) ./test.txt
# $(CCW) *.c -o a.out && ./a.out test.txt

leaks: $(CCW) $(SANITIZE) *.c -o a.out && ./a.out test.txt

.PHONY: $(NAME) all clean run leaks