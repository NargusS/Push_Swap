/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:51:27 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/28 18:42:19 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*new_first;
	if (*stack_a && (*stack_a)->next != (*stack_a))
	{
		new_first = get_last_of_my_stack(*stack_a);
		*stack_a = new_first;
	}
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*new_first;
	if (*stack_b && (*stack_b)->next != (*stack_b))
	{
		new_first = get_last_of_my_stack(*stack_b);
		*stack_b = new_first;
	}
}