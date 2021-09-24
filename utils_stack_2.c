/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:32:57 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/24 17:51:20 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	modify_element(t_stack **my_element,t_stack *previous, t_stack *next)
{
	(*my_element)->prev = previous;
	(*my_element)->next = next;
}

t_stack	*get_element_at_position(int position, t_stack **my_stack)
{
	t_stack *elements;
	int		count;

	elements = *my_stack;
	count = 0;
	if (elements)
	{
		count++;
		while (elements->next != NULL && count < position)
		{
			elements = elements->next;
			count++;
		}
		if (position == count)
			return (elements);
	}
	return (NULL);
}