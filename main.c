/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:26:03 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/28 20:02:51 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_stack(t_stack **my_stack)
{
	t_stack *elements;

	elements = *my_stack;
	if (elements)
	{
		printf("||%d||\n", elements->value);
		while (elements->next != NULL && elements->next != *my_stack)
		{
			elements = elements->next;
			printf("||%d||\n", elements->value);
		}
	}
}
void	print_invert_stack(t_stack *my_stack)
{
	t_stack *last;
	if (my_stack)
	{
		my_stack = my_stack->prev;
		last = my_stack;
		printf("||%d||\n", my_stack->value);
		while (my_stack->prev != last)
		{
			my_stack = my_stack->prev;
			printf("||%d||\n", my_stack->value);
		}

	}
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *elements;

	/*initialize_my_stack(&stack_a);
	initialize_my_stack(&stack_b);*/
	add_my_element_to_my_stack(&stack_a, 10);
	add_my_element_to_my_stack(&stack_a, 20);
	add_my_element_to_my_stack(&stack_a, 30);
	/*add_my_element_to_my_stack(&stack_a, 40);
	add_my_element_to_my_stack(&stack_a, 50);
	add_my_element_to_my_stack(&stack_a, 60);
	add_my_element_to_my_stack(&stack_a, 70);
	add_my_element_to_my_stack(&stack_a, 80);*/
	print_stack(&stack_a);
	free_my_stack(&stack_a);
	return 0;
}