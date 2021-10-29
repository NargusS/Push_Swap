/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:48:14 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/27 19:05:59 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	less_than(t_stack *elem1, t_stack *elem2)
{
	if (elem1->value < elem2->value)
		return (1);
	return (0);
}

static int	tall_than(t_stack *elem1, t_stack *elem2)
{
	if (elem1->value > elem2->value)
		return (1);
	return (0);
}

static void	sort_three_element(t_data *stacks)
{
	t_stack	*fst;
	t_stack	*scd;
	t_stack	*trd;

	fst = stacks->stack_a;
	scd = stacks->stack_a->next;
	trd = stacks->stack_a->prev;
	if (less_than(fst, scd) && tall_than(scd, trd) && less_than(fst, trd))
	{
		reverse_rotate_a(&stacks->stack_a, PRINT_CMD);
		swap_a(stacks->stack_a, PRINT_CMD);
	}
	else if (less_than(fst, scd) && tall_than(scd, trd) && tall_than(fst, trd))
		reverse_rotate_a(&stacks->stack_a, PRINT_CMD);
	else if (tall_than(fst, scd) && less_than(scd, trd) && tall_than(fst, trd))
		rotate_a(&stacks->stack_a, PRINT_CMD);
	else if (tall_than(fst, scd) && tall_than(scd, trd))
	{
		swap_a(stacks->stack_a, PRINT_CMD);
		reverse_rotate_a(&stacks->stack_a, PRINT_CMD);
	}
	else
		swap_a(stacks->stack_a, PRINT_CMD);
}

void	sort_small_stacks(t_data *stacks)
{
	t_stack	*median;

	if (stacks->size_stack_a > 3)
	{
		median = get_median(stacks->stack_a, stacks->size_stack_a);
		while (stacks->size_stack_a > 3)
		{
			if (stacks->stack_a->value < median->value)
				push_b(&stacks->stack_a, &stacks->stack_b, stacks);
			else
				rotate_a(&stacks->stack_a, PRINT_CMD);
		}
		if (stack_is_sort(stacks->stack_a, stacks->size_stack_a) == -1)
			sort_three_element(stacks);
		if (stacks->stack_b->value < stacks->stack_b->next->value)
			swap_b(stacks->stack_b, PRINT_CMD);
		while (stacks->stack_b)
			push_a(&stacks->stack_a, &stacks->stack_b, stacks);
		if (stacks->stack_a->value > stacks->stack_a->next->value)
			swap_a(stacks->stack_a, PRINT_CMD);
	}
	else
		sort_three_element(stacks);
}
