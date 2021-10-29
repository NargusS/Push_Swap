/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:42:38 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/27 20:02:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	already_exist(t_stack *my_stack)
{
	t_stack	*last;

	if (my_stack)
	{
		last = my_stack->prev;
		while (my_stack && my_stack != last)
		{
			if (my_stack->value == last->value)
				return (-1);
			my_stack = my_stack->next;
		}
		return (1);
	}
	return (0);
}

void	check_error_with_and_without_message(t_data *stacks, char *arg)
{
	int	check_param;

	check_param = atoi_and_add(stacks, arg);
	if (check_param == -1 || already_exist(stacks->stack_a) == -1)
	{
		write(1, "Error\n", 6);
		if (stacks->stack_a)
			free_my_stack(&stacks->stack_a);
		exit(EXIT_FAILURE);
	}
	else if (check_param == 0)
		exit(EXIT_FAILURE);
}
