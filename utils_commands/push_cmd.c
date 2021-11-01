/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:05:31 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/29 19:20:43 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	modify_size_stack(int *size_stack_source, int *size_stack_dest)
{
	*size_stack_dest += 1;
	*size_stack_source -= 1;
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_data *stacks)
{
	t_stack	*new_elem;

	if (*stack_b)
	{
		new_elem = *stack_b;
		if ((*stack_b)->next != *stack_b)
		{		
			modify_element(&((*stack_b)->next), (*stack_b)->prev, NULL);
			modify_element(&((*stack_b)->prev), NULL, (*stack_b)->next);
			*stack_b = (*stack_b)->next;
		}
		else
			*stack_b = NULL;
		if (!(*stack_a))
			modify_element(&new_elem, new_elem, new_elem);
		else
		{
			modify_element(&new_elem, (*stack_a)->prev,*stack_a);
			modify_element(&((*stack_a)->prev), NULL, new_elem);
			modify_element(stack_a, new_elem, NULL);
		}
		*stack_a = new_elem;
		modify_size_stack(&stacks->size_stack_b, &stacks->size_stack_a);
		write(1, "pa\n", 3);
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_data *stacks)
{
	t_stack	*new_elem;

	if (*stack_a)
	{
		new_elem = *stack_a;
		if ((*stack_a)->next != *stack_a)
		{		
			modify_element(&((*stack_a)->next), (*stack_a)->prev, NULL);
			modify_element(&((*stack_a)->prev), NULL, (*stack_a)->next);
			*stack_a = (*stack_a)->next;
		}
		else
			*stack_a = NULL;
		if (!(*stack_b))
			modify_element(&new_elem, new_elem, new_elem);
		else
		{
			modify_element(&new_elem, (*stack_b)->prev,*stack_b);
			modify_element(&((*stack_b)->prev), NULL, new_elem);
			modify_element(stack_b, new_elem, NULL);
		}
		*stack_b = new_elem;
		modify_size_stack(&stacks->size_stack_a, &stacks->size_stack_b);
		write(1, "pb\n", 3);
	}
}
