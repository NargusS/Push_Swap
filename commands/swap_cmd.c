/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:29:28 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/24 18:06:45 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swap_a(t_stack **stack_a)
{
	t_stack *new_first;
	t_stack *new_second;
	t_stack *third;

	if ((*stack_a) && (*stack_a)->next != NULL)
	{
		new_first = get_element_at_position(2, stack_a);
		*stack_a = new_first;
		new_second = new_first->prev;
		third = new_first->next;
		modify_element(&new_first, NULL, new_second);
		modify_element(&new_second, new_first, third);
		//write(1,"sa\n",3);
	}
}