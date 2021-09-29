/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:51:27 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/29 16:50:03 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate_my_stack(t_stack **my_stack)
{
	t_stack	*new_first;

	new_first = get_last_of_my_stack(*my_stack);
	*my_stack = new_first;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next != (*stack_a))
	{
		reverse_rotate_my_stack(stack_a);
		write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next != (*stack_b))
	{
		reverse_rotate_my_stack(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_first_a;
	t_stack	*new_first_b;

	if ((*stack_a && (*stack_a)->next != (*stack_a)) && \
	(*stack_b && (*stack_b)->next != (*stack_b)))
	{
		reverse_rotate_my_stack(stack_a);
		reverse_rotate_my_stack(stack_b);
		write(1, "rrr\n", 4);
	}
}
