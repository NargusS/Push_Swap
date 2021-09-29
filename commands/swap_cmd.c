/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:29:28 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/29 16:45:07 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_my_stack(t_stack **my_stack)
{
	t_stack	*new_first;
	t_stack	*new_second;
	t_stack	*third;

	new_first = (*my_stack)->next;
	new_second = (*my_stack);
	third = (*my_stack)->next->next;
	modify_element(&new_first, new_second->prev, new_second);
	modify_element(&third, new_second, third->next);
	modify_element(&(new_second->prev), new_second->prev->prev, new_first);
	modify_element(&new_second, new_first, third);
	*my_stack = new_first;
}

void	swap_a(t_stack **stack_a)
{
	if ((*stack_a) && (*stack_a)->next != (*stack_a))
	{
		swap_my_stack(stack_a);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack **stack_b)
{
	if ((*stack_b) && (*stack_b)->next != (*stack_b))
	{
		swap_my_stack(stack_b);
		write(1, "sb\n", 3);
	}
}

void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && (*stack_a)->next != (*stack_a)) && \
	(*stack_b && (*stack_b)->next != (*stack_b)))
	{
		swap_my_stack(stack_a);
		swap_my_stack(stack_b);
		write(1, "ss\n", 3);
	}
}
