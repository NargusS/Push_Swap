/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:49:07 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/19 23:49:14 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *stack_a, int check_print)
{
	int	tmp;

	if (stack_a && stack_a->next)
	{
		tmp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = tmp;
		if (check_print == PRINT_CMD)
			write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack *stack_b, int check_print)
{
	int	tmp;

	if (stack_b && stack_b->next)
	{
		tmp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = tmp;
		if (check_print == PRINT_CMD)
			write(1, "sb\n", 3);
	}
}

void	swap_s(t_data *stacks)
{
	if (stacks->stack_a && stacks->stack_a->next && \
	stacks->stack_b && stacks->stack_b->next)
	{
		swap_a(stacks->stack_a, NO_PRINT_CMD);
		swap_b(stacks->stack_b, NO_PRINT_CMD);
		write(1, "ss\n", 3);
	}
}
