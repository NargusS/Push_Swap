/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:13:39 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/28 19:36:33 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *new_elem;

	if (*stack_b)
	{
		new_elem = *stack_b;
		if ((*stack_b)->next != *stack_b)
		{		
			modify_element(&((*stack_b)->next), (*stack_b)->prev, (*stack_b)->next->next);
			modify_element(&((*stack_b)->prev), (*stack_b)->prev->prev, (*stack_b)->next);
			*stack_b = (*stack_b)->next;
		}
		else
			*stack_b = NULL;
		if (!(*stack_a))
			modify_element(&new_elem, new_elem, new_elem);
		else
		{
			modify_element(&new_elem, (*stack_a)->prev,*stack_a);
			modify_element(&((*stack_a)->prev), (*stack_a)->prev->prev,new_elem);
			modify_element(stack_a, new_elem, (*stack_a)->next);
		}
		*stack_a = new_elem;
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *new_elem;

	if (*stack_a)
	{
		new_elem = *stack_a;
		if ((*stack_a)->next != *stack_a)
		{		
			modify_element(&((*stack_a)->next), (*stack_a)->prev, (*stack_a)->next->next);
			modify_element(&((*stack_a)->prev), (*stack_a)->prev->prev, (*stack_a)->next);
			*stack_a = (*stack_a)->next;
		}
		else
			*stack_a = NULL;
		if (!(*stack_b))
			modify_element(&new_elem, new_elem, new_elem);
		else
		{
			modify_element(&new_elem, (*stack_b)->prev,*stack_b);
			modify_element(&((*stack_b)->prev), (*stack_b)->prev->prev,new_elem);
			modify_element(stack_b, new_elem, (*stack_b)->next);
		}
		*stack_b = new_elem;
	}
}