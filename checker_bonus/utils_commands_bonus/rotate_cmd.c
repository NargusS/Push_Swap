/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:48:41 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/29 19:56:10 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate_a(t_stack **stack_a, int check_print)
{
	t_stack	*new_first;

	if (*stack_a && (*stack_a)->next != (*stack_a))
	{
		*stack_a = (*stack_a)->next;
		if (check_print == PRINT_CMD)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack **stack_b, int check_print)
{
	if (*stack_b && (*stack_b)->next != (*stack_b))
	{
		*stack_b = (*stack_b)->next;
		if (check_print == PRINT_CMD)
			write(1, "rb\n", 3);
	}
}

void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a && (*stack_a)->next != (*stack_a)) && \
	(*stack_b && (*stack_b)->next != (*stack_b)))
	{
		rotate_a(stack_a, NO_PRINT_CMD);
		rotate_b(stack_b, NO_PRINT_CMD);
		write(1, "rr\n", 3);
	}
}
