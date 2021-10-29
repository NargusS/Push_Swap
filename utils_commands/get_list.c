/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:33:42 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/27 17:34:54 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_pos_of_elem(t_stack *my_stack, t_stack *element, int size_of_stack)
{
	int	i;

	i = 1;
	while (i <= size_of_stack)
	{
		if (element == my_stack)
			return (i);
		my_stack = my_stack->next;
		i++;
	}
	return (0);
}

t_stack	*get_min_of_my_stack(t_stack *my_stack, int size_of_stack)
{
	t_stack	*min_elem;
	int		i;

	if (size_of_stack > 1)
	{
		min_elem = my_stack;
		i = 1;
		while (i++ <= size_of_stack)
		{
			if (min_elem->value > my_stack->value)
				min_elem = my_stack;
			my_stack = my_stack->next;
		}
		return (min_elem);
	}
	return (NULL);
}

t_stack	*get_max_of_my_stack(t_stack *my_stack, int size_of_stack)
{
	t_stack	*max_elem;
	int		i;

	if (size_of_stack > 1)
	{
		max_elem = my_stack;
		i = 1;
		while (i++ <= size_of_stack)
		{
			if (max_elem->value < my_stack->value)
				max_elem = my_stack;
			my_stack = my_stack->next;
		}
		return (max_elem);
	}
	return (NULL);
}

int	get_pos_to_place(t_stack *stack, t_stack *elem, int size_stack)
{
	t_stack	*min_value_of_a;
	int		i;

	if (size_stack > 1)
	{
		min_value_of_a = get_min_of_my_stack(stack, size_stack);
		if (elem->value > get_max_of_my_stack(stack, size_stack)->value || \
		elem->value < min_value_of_a->value)
		{
			i = get_pos_of_elem(stack, min_value_of_a, size_stack);
			return (i);
		}
		else
		{
			i = 0;
			while (i++ < size_stack)
			{
				if (stack->prev->value < elem->value && \
				stack->value > elem->value)
					return (i);
				stack = stack->next;
			}
		}
	}
	return (0);
}
