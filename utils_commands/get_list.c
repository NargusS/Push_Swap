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

int	get_pos_of_elem(t_stack *my_stack, t_stack *elem, int size_st)
{
	int	i;

	i = 1;
	while (i <= size_st)
	{
		if (elem == my_stack)
			return (i);
		my_stack = my_stack->next;
		i++;
	}
	return (0);
}

t_stack	*get_min_of_my_stack(t_stack *my_stack, int size_st)
{
	t_stack	*min_elem;
	int		i;

	if (size_st > 1)
	{
		min_elem = my_stack;
		i = 1;
		while (i++ <= size_st)
		{
			if (min_elem->value > my_stack->value)
				min_elem = my_stack;
			my_stack = my_stack->next;
		}
		return (min_elem);
	}
	return (NULL);
}

t_stack	*get_max_of_my_stack(t_stack *my_stack, int size_st)
{
	t_stack	*max_elem;
	int		i;

	if (size_st > 1)
	{
		max_elem = my_stack;
		i = 1;
		while (i++ <= size_st)
		{
			if (max_elem->value < my_stack->value)
				max_elem = my_stack;
			my_stack = my_stack->next;
		}
		return (max_elem);
	}
	return (NULL);
}

int	get_pos_to_place(t_stack *stack, t_stack *elem, int size_st)
{
	t_stack	*min_value_of_a;
	int		i;

	if (size_st > 1)
	{
		min_value_of_a = get_min_of_my_stack(stack, size_st);
		if (elem->value > get_max_of_my_stack(stack, size_st)->value || \
		elem->value < min_value_of_a->value)
		{
			i = get_pos_of_elem(stack, min_value_of_a, size_st);
			return (i);
		}
		else
		{
			i = 0;
			while (i++ < size_st)
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
