/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:05:13 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/01 18:06:17 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static void	initialize_all(t_data *stacks)
{
	stacks->size_stack_a = 0;
	stacks->size_stack_b = 0;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}

static int	stack_is_sort(t_stack *my_stack, int size_st)
{
	int	i;

	if (size_st > 0)
	{
		i = 1;
		while (i++ < size_st)
		{
			if (my_stack->value > my_stack->next->value)
				return (-1);
			my_stack = my_stack->next;
		}
		return (1);
	}
	return (0);
}

void	exit_and_free(t_data *stacks, char **cmd)
{
	if (*cmd)
		free(*cmd);
	free_my_stack(&stacks->stack_a);
	free_my_stack(&stacks->stack_b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	stacks;

	initialize_all(&stacks);
	get_arg_add(&stacks, argc, argv);
	read_input(&stacks);
	if (stack_is_sort(stacks.stack_a, stacks.size_stack_a) == 1 && \
	stacks.stack_b == NULL)
	{
		write(1, "OK\n", 3);
		free_my_stack(&stacks.stack_a);
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(1, "KO\n", 3);
		free_my_stack(&stacks.stack_a);
		free_my_stack(&stacks.stack_b);
		exit(EXIT_FAILURE);
	}
}
