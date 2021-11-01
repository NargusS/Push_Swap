/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:00:42 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/01 16:53:30 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*new_first;

	if (*stack_a && (*stack_a)->prev != (*stack_a))
		*stack_a = (*stack_a)->prev;
}

void	reverse_rotate_b(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->prev != (*stack_b))
		*stack_b = (*stack_b)->prev;
}

void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && (*stack_a)->prev != (*stack_a)) && \
	(*stack_b && (*stack_b)->prev != (*stack_b)))
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_b(stack_b);
	}
}
