/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:48:38 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/27 20:27:55 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

void	initialize_all(t_data *stacks)
{
	stacks->size_stack_a = 0;
	stacks->size_stack_b = 0;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}

int main(int argc, char **argv)
{
	t_data stacks;

	initialize_all(&stacks);
	get_arg_add_to_stack_a(&stacks, argc, argv);
	/*if (stack_is_sort(stacks.stack_a, stacks.size_stack_a) == 1)
		free_my_stack(&stacks.stack_a);
		exit(EXIT_SUCCESS);*/
	sort_hundreds_num(&stacks);
	//sort_small_stacks(&stacks);
	//print_stack(stacks.stack_a, stacks.stack_b);
	//printf("MEDIAN :%d\n", get_median(stacks.stack_a, stacks.size_stack_a)->value);
}