/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:00:42 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/29 19:56:04 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	reverse_rotate_a(t_stack **stack_a, int check_print)
{
	t_stack	*new_first;

	if (*stack_a && (*stack_a)->prev != (*stack_a))
	{
		*stack_a = (*stack_a)->prev;
		if (check_print == PRINT_CMD)
			write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_stack **stack_b, int check_print)
{
	if (*stack_b && (*stack_b)->prev != (*stack_b))
	{
		*stack_b = (*stack_b)->prev;
		if (check_print == PRINT_CMD)
			write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && (*stack_a)->prev != (*stack_a)) && \
	(*stack_b && (*stack_b)->prev != (*stack_b)))
	{
		reverse_rotate_a(stack_a, NO_PRINT_CMD);
		reverse_rotate_b(stack_b, NO_PRINT_CMD);
		write(1, "rrr\n", 4);
	}
}
