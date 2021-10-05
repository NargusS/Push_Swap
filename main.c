/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:26:03 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/05 18:31:10 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*void	print_stack(t_stack **my_stack)
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
}*/

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

void	print_stack(t_stack *my_stack_1, t_stack *my_stack_2)
{
	t_stack *elements_1;
	t_stack *elements_2;

	elements_1 = my_stack_1;
	elements_2 = my_stack_2;
	if (my_stack_1 || my_stack_2)
	{
		if (my_stack_1 && my_stack_2)
		{
			printf("||%d|| ||%d||\n", elements_1->value,elements_2->value);
			while (elements_1 != my_stack_1->prev || elements_2 != my_stack_2->prev)
			{
				if (((!elements_1) || elements_1 == my_stack_1->prev) && elements_2)
				{
					elements_2 = elements_2->next;
					printf("||empty|| ||%d||\n", elements_2->value);
				}
				else if(elements_1 && ((!elements_2) || elements_2 == my_stack_2->prev))
				{
					elements_1 = elements_1->next;
					printf("||%d|| ||empty||\n", elements_1->value);
				}
				else if (elements_1 && elements_2)
				{
					elements_1 = elements_1->next;
					elements_2 = elements_2->next;
					printf("||%d|| ||%d||\n", elements_1->value,elements_2->value);
				}
			}
		}
		else if (!my_stack_1)
		{
			printf("||empty|| ||%d||\n", elements_2->value);
			while (elements_2 != my_stack_2->prev)
			{
				elements_2 = elements_2->next;
				printf("||empty|| ||%d||\n", elements_2->value);
			}
		}
		else
		{
			printf("||%d|| ||empty||\n", elements_1->value);
			while (elements_1 != my_stack_1->prev)
			{
				elements_1 = elements_1->next;
				printf("||%d|| ||empty||\n", elements_1->value);
			}
		}
	}
}

int		stack_b_is_sorted(t_stack *stack_b)
{
	t_stack *first;

	first = stack_b;

	if (stack_b && stack_b->next != stack_b)
	{
		while (stack_b->next != first)
		{
			if (stack_b->next->value > stack_b->value)
			{
				print_stack(NULL,stack_b);
				return (-1);
			}
			stack_b = stack_b->next;
		}
		return (1);
	}
	return (0);
}



int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_chunk	*chunks;
	
	get_arg_add_to_stack_a(&stack_a, argc, argv);
	//print_stack(stack_a, stack_b);
	chunks_func(stack_a, &chunks);
	sort_test(&stack_a, &stack_b, chunks);
	//print_stack(stack_a, stack_b);
	//free_my_stack(&stack_a);
	return 0;
}