/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:20:15 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/24 18:06:32 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_my_stack(t_stack ***stack_a)
{
	/// if malloc failed return -1 else 1;
	*stack_a = malloc(sizeof(t_stack *));
	if (*stack_a == NULL)
		return (-1);
	**stack_a = NULL;
	return (1);
}

int	create_element(int num, t_stack **my_element,t_stack *previous, t_stack *next)
{

	*my_element = malloc(sizeof(t_stack));
	//*my_element = malloc(-1);
	if (*my_element == NULL)
		return (-1);
	(*my_element)->value = num;
	(*my_element)->prev = previous;
	(*my_element)->next = next;
	return (1);
}

t_stack	*get_last_of_my_stack(t_stack **my_stack)
{
	t_stack *elements;

	elements = *my_stack;
	if (elements)
	{
		while (elements->next != NULL)
			elements = elements->next;
		return (elements);
	}
	return (NULL);
}

int	add_my_element_to_my_stack(t_stack **my_stack, int num)
{
	t_stack	*last_element;
	t_stack *my_element;

	if (*my_stack == NULL)
	{
		if (create_element(num, &my_element,NULL, NULL) == -1)
			return (-1);
		*my_stack = my_element;
	}
	else
	{
		last_element = get_last_of_my_stack(my_stack);
		if (create_element(num, &my_element,last_element, NULL) == -1)
			return (-1);
		last_element->next = my_element;
	}
	return (1);
}

void	free_my_stack(t_stack **my_stack)
{
	t_stack *current;
	t_stack *prev_element;

	if (*my_stack)
	{
		current = get_last_of_my_stack(my_stack);
		prev_element = current->prev;
		while (prev_element != NULL)
		{
			//printf(" %d ", current->value);
			free(current);
			current = prev_element;
			prev_element = current->prev;
		}
		//printf(" %d ", current->value);
		free(current);
	}
	free(my_stack);
}

int main(int argc, char **argv)
{
	t_stack **stack_a;
	t_stack **stack_b;
	t_stack *element;

	initialize_my_stack(&stack_a);
	add_my_element_to_my_stack(stack_a, 10);
	add_my_element_to_my_stack(stack_a, 20);
	add_my_element_to_my_stack(stack_a, 30);
	add_my_element_to_my_stack(stack_a, 40);
	add_my_element_to_my_stack(stack_a, 50);
	add_my_element_to_my_stack(stack_a, 60);
	add_my_element_to_my_stack(stack_a, 70);
	add_my_element_to_my_stack(stack_a, 80);
	element = get_element_at_position(10, stack_a);
	if (element != NULL)
		printf(" %d \n", element->value);
	swap_a(stack_a);
	printf ("%d\n", (*stack_a)->value);
	free_my_stack(stack_a);
	return 0;
}