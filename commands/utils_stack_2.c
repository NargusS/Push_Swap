/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:32:57 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/28 20:00:47 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	modify_element(t_stack **my_element,t_stack *previous, t_stack *next)
{
	(*my_element)->prev = previous;
	(*my_element)->next = next;
}

t_stack	*get_element_at_position(int position, t_stack *my_stack)
{
	t_stack *first_element;
	int		count;

	count = 0;
	if (my_stack)
	{
		count++;
		first_element = my_stack;
		while (my_stack->next != first_element && count < position)
		{
			my_stack = my_stack->next;
			count++;
		}
		if (position == count)
			return (my_stack);
	}
	return (NULL);
}