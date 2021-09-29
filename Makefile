NAME = push_swap

SRCS =  main.c\
	commands/utils_stack.c\
	commands/swap_cmd.c\
	commands/get_element_utils.c\
	commands/rotate_cmd.c\
	commands/rev_rotate_cmd.c\
	commands/push_cmd.c
INCLUDES = includes/push_swap.h

OBJS	= ${SRCS:.c=.o}

all : ${NAME}
	@printf "That's compile"
$(NAME): ${OBJS}
	gcc -Wall -Werror -Wextra -I includes ${OBJS} -o $(NAME)
clean:
	rm -rf ${OBJS}
fclean: clean
	rm -rf ${NAME}
	rm -rf ${OBJS}
re:	fclean all
