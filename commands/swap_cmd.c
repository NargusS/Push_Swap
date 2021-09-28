/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:29:28 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/28 19:53:16 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack *new_first;
	t_stack	*new_second;
	t_stack	*third;

	if ((*stack_a) && (*stack_a)->next != (*stack_a))
	{
		new_first = (*stack_a)->next;
		new_second = (*stack_a);
		third = (*stack_a)->next->next;
		modify_element(&new_first, new_second->prev, new_second);
		modify_element(&third, new_second, third->next);
		modify_element(&(new_second->prev), new_second->prev->prev, new_first);
		modify_element(&new_second, new_first, third);
		*stack_a = new_first;
		//write(1,"sa\n",3);
	}
}

void	swap_b(t_stack **stack_b)
{
	t_stack *new_first;
	t_stack	*new_second;
	t_stack	*third;

	if ((*stack_b) && (*stack_b)->next != (*stack_b))
	{
		new_first = (*stack_b)->next;
		new_second = (*stack_b);
		third = (*stack_b)->next->next;
		modify_element(&new_first, new_second->prev, new_second);
		modify_element(&third, new_second, third->next);
		modify_element(&(new_second->prev), new_second->prev->prev, new_first);
		modify_element(&new_second, new_first, third);
		*stack_b = new_first;
		//write(1,"sa\n",3);
	}
}