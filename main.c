/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:26:03 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/24 18:22:33 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **my_stack)
{
	t_stack *elements;

	elements = *my_stack;
	if (elements)
	{
		printf("||%d||\n", elements->value);
		while (elements->next != NULL)
		{
			elements = elements->next;
			printf("||%d||\n", elements->value);
		}
	}
}
int main(int argc, char **argv)
{
	t_stack **stack_a;
	t_stack **stack_b;

	initialize_my_stack(&stack_a);
	add_my_element_to_my_stack(stack_a, 10);
	add_my_element_to_my_stack(stack_a, 20);
	add_my_element_to_my_stack(stack_a, 30);
	add_my_element_to_my_stack(stack_a, 40);
	add_my_element_to_my_stack(stack_a, 50);
	add_my_element_to_my_stack(stack_a, 60);
	add_my_element_to_my_stack(stack_a, 70);
	add_my_element_to_my_stack(stack_a, 80);
	print_stack(stack_a);
	swap_a(stack_a);
	puts("\n");
	print_stack(stack_a);
	free_my_stack(stack_a);
	return 0;
}