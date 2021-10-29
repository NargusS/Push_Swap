/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_push_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:01:22 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/27 17:48:41 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	result_greather_less(t_stack *element, int size_of_stack)
{
	int	i;
	int	my_element_value;
	int	result;

	i = 2;
	result = 0;
	my_element_value = element->value;
	element = element->next;
	while (i <= size_of_stack)
	{
		if (element->value < my_element_value)
			result -= 1;
		else if (element->value > my_element_value)
			result += 1;
		i++;
		element = element->next;
	}
	return (result);
}

t_stack	*get_median(t_stack *my_stack, int size_st)
{
	t_stack	*median;
	int		result_med;
	int		i;
	int		median_value;

	i = 2;
	median_value = result_greather_less(my_stack, size_st);
	median = my_stack;
	my_stack = my_stack->next;
	while (i <= size_st)
	{
		result_med = result_greather_less(my_stack, size_st);
		if (median_value == 0)
			return (median);
		else if (result_med == 0 || result_med == 1 || result_med == -1)
		{
			median = my_stack;
			median_value = result_med;
		}
		my_stack = my_stack->next;
		i++;
	}
	return (median);
}

void	push_b_optimize(t_data *stacks)
{
	int	i;
	int	median;

	i = 1;
	median = get_median(stacks->stack_a, stacks->size_stack_a)->value;
	while (stacks->size_stack_a > 3)
	{
		if (stacks->stack_a->value < median)
		{
			push_b(&stacks->stack_a, &stacks->stack_b, stacks);
			if (stacks->stack_b->next != stacks->stack_b && \
			stacks->stack_b->next->value >= median)
				rotate_b(&stacks->stack_b, PRINT_CMD);
		}
		else
			push_b(&stacks->stack_a, &stacks->stack_b, stacks);
	}
	if (stack_is_sort(stacks->stack_a, stacks->size_stack_a) == -1)
		sort_small_stacks(stacks);
}
