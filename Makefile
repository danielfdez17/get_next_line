NAME = a.out

SRCS = get_next_line.c \
       get_next_line_utils.c

INCS = get_next_line.h

OBJS = $(SRCS:.c=.o)

CCW = cc -Wall -Wextra -Werror

SANITIZE = -fsanitize=address -g

FILE = ./test.txt

%.o: %.c
	$(CCW) -c $< -o $@ -I INCS

all: $(NAME)

$(NAME): $(OBJS)
	$(CCW) $(OBJS) -o $(NAME)  

clean:
	rm -f $(OBJS) $(NAME)  

run: clean all
	./$(NAME) $(FILE)

leaks: clean
	$(CCW) $(SANITIZE) $(SRCS) -o $(NAME)  
	./$(NAME) $(FILE)

.PHONY: all clean run leaks
