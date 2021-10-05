/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:32:57 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/04 20:18:24 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_size_of_my_stack(t_stack *my_stack)
{
	t_stack	*first_element;
	int		i;

	i = 0;
	if (my_stack)
	{
		i = 1;
		first_element = my_stack;
		while (my_stack && my_stack->next != first_element)
		{
			my_stack = my_stack->next;
			i++;
		}
	}
	return (i);
}

t_stack	*get_element_at_position(int position, t_stack *my_stack)
{
	t_stack	*first_element;
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

t_stack	*get_last_of_my_stack(t_stack *my_stack)
{
	t_stack	*first_element;

	if (my_stack)
	{
		first_element = my_stack;
		while (my_stack->next != first_element)
			my_stack = my_stack->next;
		return (my_stack);
	}
	return (NULL);
}
