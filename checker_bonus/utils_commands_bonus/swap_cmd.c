/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:49:07 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/01 16:53:46 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap_a(t_stack *stack_a)
{
	int	tmp;

	if (stack_a && stack_a->next)
	{
		tmp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = tmp;
	}
}

void	swap_b(t_stack *stack_b)
{
	int	tmp;

	if (stack_b && stack_b->next)
	{
		tmp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = tmp;
	}
}

void	swap_s(t_data *stacks)
{
	if (stacks->stack_a && stacks->stack_a->next && \
	stacks->stack_b && stacks->stack_b->next)
	{
		swap_a(stacks->stack_a);
		swap_b(stacks->stack_b);
	}
}
