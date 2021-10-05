/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:25:54 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/05 18:27:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_good_position(t_stack *stack_to_place, t_stack *elements)
{
	int i;
	t_stack	*last;

	i = 0;
	last = stack_to_place->prev;
	while (stack_to_place != last && (elements->value < stack_to_place->value))
	{
		stack_to_place = stack_to_place->next;
		i++;
	}
	return (i);
}

void	push_in_good_place(t_stack **stack_a, t_stack **stack_b)
{
	int pos;
	int size;
	int i;

	if (!(*stack_b) || ((*stack_a)->value > (*stack_b)->value))
	{
		//puts("push_to_top");
		push_b(stack_a, stack_b);
	}
	else if (*stack_b && (get_last_of_my_stack(*stack_b)->value > (*stack_a)->value))
	{
		//puts("push_to_bottom");
		push_b(stack_a, stack_b);
		rotate_b(stack_b);
	}
	else if ((*stack_a)->value > get_last_of_my_stack(*stack_b)->value)
	{
		pos = get_good_position(*stack_b, *stack_a);
		size  = (get_size_of_my_stack(*stack_b))/2;
		//puts("push_in_the_middle");
		//printf("first good pos: %d size:%d\n", pos, size);
		if (pos <= size)
		{
			i = 0;
			while (i++ < pos-1)
				rotate_b(stack_b);
			push_b(stack_a, stack_b);
			swap_b(stack_b);
			i = 0;
			while (i++ < pos-1)
				reverse_rotate_b(stack_b);
		}
		else
		{
			pos = get_size_of_my_stack(*stack_b) - pos;
			//printf("second good pos: %d size:%d\n", pos, get_size_of_my_stack(*stack_b));
			i = 0;
			while (i++ < pos)
				reverse_rotate_b(stack_b);
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			i = 0;
			while (i++ < pos)
				rotate_b(stack_b);
		}
	}
}

void	sort_test(t_stack **stack_a, t_stack **stack_b,t_chunk *chunks)
{
	t_stack *last;
	int pos;
	int size;
	int i;
	
	last = get_last_of_my_stack(*stack_a);
	if (chunks)
	{
		//puts("first");
		while ((*stack_a) != last)
		{
			if (is_in_chunk(*stack_a, chunks) == 0)
				push_in_good_place(stack_a, stack_b);
			else
				rotate_a(stack_a);
		}
		if (is_in_chunk(*stack_a, chunks) == 0)
			push_in_good_place(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	//print_stack(*stack_a, *stack_b);
	while (1)
	{
		//printf("stack_b : %d\n", stack_b_is_sorted(*stack_b));
		if (stack_b_is_sorted(*stack_b) == 1 && !(*stack_a))
		{
			while ((*stack_b))
				push_a(stack_a, stack_b);
			return;
		}
		push_in_good_place(stack_a, stack_b);
	}
}