/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:29:28 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/24 19:51:49 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack *new_first;
	t_stack *new_second;
	t_stack *third;
	t_stack	*last;

	if ((*stack_a) && (*stack_a)->next != NULL)
	{
		new_first = get_element_at_position(2, stack_a);
		third = get_element_at_position(3, stack_a);
		last = get_last_of_my_stack(stack_a);
		*stack_a = new_first;
		new_second = new_first->prev;
		modify_element(&new_first, NULL, new_second);
		modify_element(&new_second, new_first, third);
		modify_element(&last, last->prev, new_first);
		//write(1,"sa\n",3);
	}
}

void    swap_b(t_stack **stack_b)
{
	t_stack *new_first;
	t_stack *new_second;
	t_stack *third;
	t_stack	*last;

	if ((*stack_b) && (*stack_b)->next != NULL)
	{
		new_first = get_element_at_position(2, stack_b);
		third = get_element_at_position(3, stack_b);
		last = get_last_of_my_stack(stack_b);
		*stack_b = new_first;
		new_second = new_first->prev;
		modify_element(&new_first, NULL, new_second);
		modify_element(&new_second, new_first, third);
		modify_element(&last, last->prev, new_first);
		//write(1,"sb\n",3);
	}
}
