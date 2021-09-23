/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:20:15 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/23 15:27:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_element(int num, t_stack *previous, t_stack *next)
{
	t_stack *new_element;

	new_element = malloc(sizeof(t_stack));
	new_element->value = num;
	new_element->prev = previous;
	new_element->next = next;
	return (new_element);
}

t_stack	*get_first_of_my_stack(t_stack *my_stack)
{
	if (my_stack)
	{
		while (my_stack->prev != NULL)
			my_stack = my_stack->prev;
		return (my_stack);
	}
	return (NULL);
}

t_stack	*get_last_of_my_stack(t_stack *my_stack)
{
	t_stack *elements;

	elements = my_stack;
	if (elements)
	{
		while (elements->next != NULL)
			elements = elements->next;
		return (elements);
	}
	return (NULL);
}

void	add_my_element_to_my_stack(t_stack **my_stack, int num)
{
	t_stack	*last_element;
	t_stack *my_element;

	if (*my_stack == NULL)
	{
		my_element = create_element(num, NULL, NULL);
		*my_stack = my_element;
	}
	else
	{
		last_element = get_last_of_my_stack(*my_stack);
		my_element = create_element(num, last_element, NULL);
		last_element->next = my_element;
	}
}
int main(int argc, char **argv)
{
	t_stack **stack_a;

	stack_a = malloc(sizeof(t_stack *));
	*stack_a = NULL;
	add_my_element_to_my_stack(stack_a, 10);
	add_my_element_to_my_stack(stack_a, 20);
	printf("%d %d\n", (*stack_a)->next->prev->next->prev->value, (*stack_a)->next->value);
	return 0;
}