/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:20:15 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/29 16:54:23 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_element(int num, t_stack **my_element, t_stack *prev, t_stack *next)
{
	*my_element = malloc(sizeof(t_stack));
	if (*my_element == NULL)
		return (-1);
	(*my_element)->value = num;
	(*my_element)->prev = prev;
	(*my_element)->next = next;
	return (1);
}

void	modify_element(t_stack **my_element, t_stack *prev, t_stack *next)
{
	if (prev)
		(*my_element)->prev = prev;
	if (next)
		(*my_element)->next = next;
}

int	add_my_element_to_my_stack(t_stack **my_stack, int num)
{
	t_stack	*first_element;
	t_stack	*last_element;
	t_stack	*my_element;

	if (*my_stack == NULL)
	{
		if (create_element(num, &my_element, NULL, NULL) == -1)
			return (-1);
		modify_element(&my_element, my_element, my_element);
		*my_stack = my_element;
	}
	else
	{
		first_element = get_element_at_position(1, *my_stack);
		last_element = get_last_of_my_stack(*my_stack);
		if (create_element(num, &my_element, last_element, first_element) == -1)
			return (-1);
		first_element->prev = my_element;
		last_element->next = my_element;
	}
	return (1);
}

void	free_my_stack(t_stack **my_stack)
{
	t_stack	*current;
	t_stack	*prev_element;

	if (*my_stack)
	{
		current = get_last_of_my_stack(*my_stack);
		prev_element = current->prev;
		while (prev_element != NULL && current != *my_stack)
		{
			printf(" free:%d ", current->value);
			free(current);
			current = prev_element;
			prev_element = current->prev;
		}
		printf(" freee:%d ", current->value);
		free(current);
	}
}
