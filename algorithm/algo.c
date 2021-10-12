/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:25:54 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/12 20:19:18 by achane-l         ###   ########.fr       */
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

int	get_good_position_2(t_stack *stack_to_place, t_stack *elements)
{
	int i;
	t_stack	*last;

	i = 0;
	last = stack_to_place->prev;
	while (stack_to_place != last && (elements->value > stack_to_place->value))
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
		push_b(stack_a, stack_b);
	}
	else if (*stack_b && (get_last_of_my_stack(*stack_b)->value > (*stack_a)->value))
	{
		i = 1;
		push_b(stack_a, stack_b);
		while ((*stack_a) && ((*stack_b)->value < (*stack_a)->value && get_last_of_my_stack(*stack_b)->value > (*stack_a)->value))
		{
			push_b(stack_a, stack_b);
			i++;
		}
		while (i--)
			rotate_b(stack_b);
	}
	else if ((*stack_a)->value > get_last_of_my_stack(*stack_b)->value)
	{
		pos = get_good_position(*stack_b, *stack_a);
		size  = (get_size_of_my_stack(*stack_b))/2;
		if (pos <= size)
		{
			i = 0;
			while (i++ < pos-1)
				rotate_b(stack_b);
			push_b(stack_a, stack_b);
			swap_b(stack_b);
			i = 0;
			while (i < pos-1)
			{
				if ((*stack_a) && ((*stack_a)->value < get_last_of_my_stack(*stack_b)->value && (*stack_a)->value > (*stack_b)->value))
					push_b(stack_a, stack_b);
				else
				{
					reverse_rotate_b(stack_b);
					i++;
				}
			}
		}
		else
		{
			pos = get_size_of_my_stack(*stack_b) - pos;
			i = 0;
			while (i++ < pos)
				reverse_rotate_b(stack_b);
			push_b(stack_a, stack_b);
			i = 0;
			while (i < pos+1)
			{
				if ((*stack_a) && ((*stack_a)->value < get_last_of_my_stack(*stack_b)->value && (*stack_a)->value > (*stack_b)->value))
				{
					push_b(stack_a, stack_b);
					i--;
				}
				else
				{
					rotate_b(stack_b);
					i++;
				}
			}
		}
	}
}

void	push_in_good_place_chunk(t_stack **stack_a, t_stack **stack_b)
{
	int pos;
	int size;
	int i;

	if (!(*stack_b) || ((*stack_a)->value > (*stack_b)->value))
	{
		push_b(stack_a, stack_b);
	}
	else if (*stack_b && (get_last_of_my_stack(*stack_b)->value > (*stack_a)->value))
	{
		push_b(stack_a, stack_b);
		rotate_b(stack_b);
	}
	else if ((*stack_a)->value > get_last_of_my_stack(*stack_b)->value)
	{
		pos = get_good_position(*stack_b, *stack_a);
		size  = (get_size_of_my_stack(*stack_b))/2;
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
	/*if (chunks)
	{
		//puts("first");
		while ((*stack_a) != last)
		{
			if (is_in_chunk(*stack_a, chunks) == 0)
				push_in_good_place_chunk(stack_a, stack_b);
			else
				rotate_a(stack_a);
		}
		if (is_in_chunk(*stack_a, chunks) == 0)
			push_in_good_place_chunk(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}*/
	while (1)
	{
		if (stack_b_is_sorted(*stack_b) == 1 && !(*stack_a))
		{
			while ((*stack_b))
				push_a(stack_a, stack_b);
			return;
		}
		push_in_good_place(stack_a, stack_b);
	}
}

static int search_next_less_number(t_stack *my_stack)
{
	t_stack	*first;
	int		i;

	first = my_stack;
	my_stack = my_stack->next;
	i = 0;
	while (my_stack->next != first)
	{
		if (first > my_stack)
			return(i);
		i++;
		my_stack = my_stack->next;
	}
	return (0);
}

void	sort_in_my_stack(t_stack **my_stack)
{
	t_stack	*my_self;
	int pos;

	pos = 0;
	while (1)
	{
		if (stack_a_is_sorted(*my_stack) == 1)
			return;
		if ((*my_stack)->value > (*my_stack)->next->value && (*my_stack)->next->value > get_last_of_my_stack(*my_stack)->value)
			swap_a(my_stack);
		else if (is_min_of_my_stack(*my_stack) != 1 && ((*my_stack)->value < get_last_of_my_stack(*my_stack)->value))
		{
			while (get_last_of_my_stack(*my_stack)->value > (*my_stack)->value)
			{
				reverse_rotate_a(my_stack);
				swap_a(my_stack);
			}
		}
		else
			rotate_a(my_stack);
	}
}

void	push_in_good_place_a(t_stack **stack_a, t_stack **stack_b)
{
	int pos;
	int size;
	int i;

	if (!(*stack_a) || ((*stack_b)->value < (*stack_a)->value))
	{
		push_a(stack_a, stack_b);
	}
	else if (*stack_a && (get_last_of_my_stack(*stack_a)->value < (*stack_b)->value))
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
	else
	{
		size = (get_size_of_my_stack(*stack_a)+1)/2;
		pos = get_good_position_2(*stack_a, *stack_b);
		if (pos <= size)
		{
			i = 0;
			while (i++ < pos-1)
				rotate_a(stack_a);
			push_a(stack_a, stack_b);
			swap_a(stack_a);
			i = 0;
			while (i < pos-1)
			{
				if ((*stack_b) && ((*stack_b)->value < get_last_of_my_stack(*stack_a)->value && (*stack_b)->value > (*stack_a)->value))
					push_a(stack_a, stack_b);
				else
				{
					reverse_rotate_a(stack_a);
					i++;
				}
			}
		}
		else
		{
			pos = get_size_of_my_stack(*stack_a) - pos;
			i = 0;
			while (i++ < pos)
				reverse_rotate_a(stack_a);
			push_a(stack_a, stack_b);
			i = 0;
			while (i <= pos)
			{
				if ((*stack_b) && ((*stack_b)->value > get_last_of_my_stack(*stack_a)->value && (*stack_b)->value < (*stack_a)->value))
				{
					push_a(stack_a, stack_b);
					i--;
				}
				else
				{
					rotate_a(stack_a);
					i++;
				}
			}
		}
		/*size = (get_size_of_my_stack(*stack_a)+1)/2;
		pos = get_good_position_2(*stack_a, *stack_b);
		i = 0;
		while (i++ < pos)
			rotate_a(stack_a);
		push_a(stack_a, stack_b);
		i = 0;
		while (i++ < pos)
			reverse_rotate_a(stack_a);*/
	}
}

void	sort_test_2(t_stack **stack_a, t_stack **stack_b)
{
	int i = 5;
	while ((*stack_a))
		push_b(stack_a, stack_b);
	while (i--)
	{
		printf("%d\n", check_best_moves(*stack_a, *stack_b)->value);
		if (stack_a_is_sorted(*stack_a) == 1 && !(*stack_b))
			return;
		push_in_good_place_a(stack_a,stack_b);
		print_stack(*stack_a, *stack_b);
		puts("");
	}
}

int	count_move_to_place_in_a(t_stack *stack_a, t_stack	*stack_b, t_stack *element)
{
	int number_of_moves;
	int place;

	number_of_moves = 0;
	place = 0;
	while (stack_b != element)
	{
		stack_b = stack_b->next;
		place++;
	}
	if (place < get_size_of_my_stack(stack_b)/2)
		number_of_moves += place;
	else
		number_of_moves += (get_size_of_my_stack(stack_b) - place);
	if (!stack_a || stack_a->value > element->value)
		number_of_moves += 1;
	else if (element->value > get_last_of_my_stack(stack_a)->value)
		number_of_moves += 2;
	else
	{
		place = get_good_position_2(stack_a, element);
		if (place < get_size_of_my_stack(stack_b)/2)
			number_of_moves += (place * 2);
		else
			number_of_moves += (get_size_of_my_stack(stack_b) - place);
	}
	return (number_of_moves);
}

t_stack	*check_best_moves(t_stack *stack_a, t_stack	*stack_b)
{
	int	less_number_of_move = 1000000000;
	t_stack	*best_elem;
	t_stack	*element;
	t_stack	*last;

	element = stack_b;
	last = stack_b->prev;
	while (element != last)
	{
		if (!best_elem)
		{
			best_elem = element;
			less_number_of_move = count_move_to_place_in_a(stack_a, stack_b, element);
		}
		else if (less_number_of_move > count_move_to_place_in_a(stack_a, stack_b, element))
		{
			less_number_of_move = count_move_to_place_in_a(stack_a, stack_b, element);
			best_elem = element;
		}
		element = element->next;
	}
	printf("NB MOVES:%d\n", less_number_of_move);
	printf("BEST MOVES: %d\n", best_elem->value);
	return (best_elem);
}