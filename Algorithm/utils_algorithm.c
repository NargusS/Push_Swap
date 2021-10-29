/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:34:47 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/27 17:35:18 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_moves_for_elem(t_data stacks, t_stack *element)
{
	int	pos;
	int	count_moves;

	pos = get_pos_of_elem(stacks.stack_b, element, stacks.size_stack_b);
	count_moves = 1;
	if (pos > 1 && pos > stacks.size_stack_b / 2)
		count_moves += (stacks.size_stack_b - pos) + 1;
	else if (pos > 1 && pos <= stacks.size_stack_b / 2)
		count_moves += pos - 1;
	pos = get_pos_to_place(stacks.stack_a, element, stacks.size_stack_a);
	if (pos > 1 && pos <= stacks.size_stack_a / 2)
		count_moves += (pos - 1);
	else if (pos > 1 && pos > stacks.size_stack_a / 2)
		count_moves += (stacks.size_stack_a - pos + 1);
	return (count_moves);
}

t_stack	*get_best_move(t_data stacks)
{
	t_stack	*best_move_elem;
	t_stack	*new_elem;
	int		best_move_count;
	int		move_count;
	int		i;

	i = 0;
	new_elem = stacks.stack_b;
	best_move_elem = new_elem;
	best_move_count = count_moves_for_elem(stacks, new_elem);
	while (i++ < stacks.size_stack_b)
	{
		move_count = count_moves_for_elem(stacks, new_elem);
		if (move_count < best_move_count)
		{
			best_move_elem = new_elem;
			best_move_count = move_count;
		}
		new_elem = new_elem->next;
	}
	return (best_move_elem);
}

int	stack_is_sort(t_stack *my_stack, int size_st)
{
	int	i;

	if (size_st > 0)
	{
		i = 1;
		while (i++ < size_st)
		{
			if (my_stack->value > my_stack->next->value)
				return (-1);
			my_stack = my_stack->next;
		}
		return (1);
	}
	return (0);
}
