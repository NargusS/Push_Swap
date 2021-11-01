/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:48:41 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/01 17:10:34 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*new_first;

	if (*stack_a && (*stack_a)->next != (*stack_a))
		*stack_a = (*stack_a)->next;
}

void	rotate_b(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next != (*stack_b))
		*stack_b = (*stack_b)->next;
}

void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && (*stack_a)->next != (*stack_a)) && \
	(*stack_b && (*stack_b)->next != (*stack_b)))
	{
		rotate_a(stack_a);
		rotate_b(stack_b);
	}
}
