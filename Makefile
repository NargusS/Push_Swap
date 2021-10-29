NAME =	push_swap

NAME_B = checker

SRCS =	src/push_swap.c\
		utils_commands/linked_list_utils.c\
		utils_commands/swap_cmd.c\
		utils_commands/rotate_cmd.c\
		utils_commands/reverse_rotate_cmd.c\
		utils_commands/push_cmd.c\
		utils_commands/get_list.c\
		Algorithm/algorithm.c\
		Algorithm/optimize_push_b.c\
		Algorithm/small_stacks_sort.c\
		Algorithm/utils_algorithm.c\
		src/errors.c\
		src/get_arg.c

SRCS_B =	checker_bonus/checker.c\
			checker_bonus/src_bonus/errors_bonus.c\
			checker_bonus/src_bonus/get_arg_bonus.c\
			checker_bonus/utils_commands_bonus/linked_list_utils.c\
			checker_bonus/utils_commands_bonus/swap_cmd.c\
			checker_bonus/utils_commands_bonus/rotate_cmd.c\
			checker_bonus/utils_commands_bonus/reverse_rotate_cmd.c\
			checker_bonus/utils_commands_bonus/push_cmd.c

INCLUDES = includes/push_swap.h

OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}

all: ${NAME}
	@printf "That's compile\n"

bonus: ${NAME_B}
	@printf "That's compile\n"

$(NAME): ${OBJS}
	@gcc -Wall -Werror -Wextra -I ${INCLUDES} ${OBJS} -o $(NAME)

$(NAME_B): ${OBJS_B}
	@gcc -Wall -Werror -Wextra -I bonus/checker.h ${OBJS_B} -o $(NAME_B)
clean:
	@rm -rf ${OBJS}
	@rm -rf ${OBJS_B}
	@printf "Soft Cleaning\n"

fclean:
	@rm -rf ${NAME}
	@rm -rf ${NAME_B}
	@rm -rf ${OBJS}
	@rm -rf ${OBJS_B}
	@printf "Spring Cleaning\n"

re:	fclean all

PHONY: all bonus clean fclean re