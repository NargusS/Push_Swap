NAME = push_swap
SRCS = utils_commands/linked_list_utils.c\
	utils_commands/swap_cmd.c\
	utils_commands/rotate_cmd.c\
	utils_commands/reverse_rotate_cmd.c\
	utils_commands/push_cmd.c\
	utils_commands/get_list.c\
	Algorithm/algorithm.c\
	Algorithm/optimize_push_b.c\
	Algorithm/small_stacks_sort.c\
	Algorithm/utils_algorithm.c\
	src/get_arg.c\
	src/push_swap.c\
	src/errors.c
INCLUDES = includes/push_swap.h

OBJS	= ${SRCS:.c=.o}

all : ${NAME}
	@printf "That's compile\n"
$(NAME): ${OBJS}
	@gcc -Wall -Werror -Wextra -I includes ${OBJS} -o $(NAME)
clean:
	@rm -rf ${OBJS}
	@printf "Soft Cleaning\n"
fclean:
	@rm -rf ${NAME}
	@rm -rf ${OBJS}
	@printf "Spring Cleaning\n"
re:	fclean all
