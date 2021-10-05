/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:23:03 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/05 15:16:43 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_my_stack(t_stack **my_stack)
{
	t_stack	*new_first;

	new_first = get_element_at_position(2, *my_stack);
	*my_stack = new_first;
}

void	rotate_a(t_stack **stack_a)
{
	if (*stack_a && (*stack_a)->next != (*stack_a))
	{
		rotate_my_stack(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next != (*stack_b))
	{
		rotate_my_stack(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && (*stack_a)->next != (*stack_a)) && \
	(*stack_b && (*stack_b)->next != (*stack_b)))
	{
		rotate_my_stack(stack_a);
		rotate_my_stack(stack_b);
		write(1, "rr\n", 3);
	}
}
