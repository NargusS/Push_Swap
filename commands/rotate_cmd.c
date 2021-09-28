/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:23:03 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/28 19:52:29 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*new_first;
	if (*stack_a && (*stack_a)->next != (*stack_a))
	{
		new_first = get_element_at_position(2, *stack_a);
		*stack_a = new_first;
	}
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*new_first;
	if (*stack_b && (*stack_b)->next != (*stack_b))
	{
		new_first = get_element_at_position(2, *stack_b);
		*stack_b = new_first;
	}
}