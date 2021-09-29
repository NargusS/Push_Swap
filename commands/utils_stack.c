/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:20:15 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/29 18:20:04 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	new_element(int num, t_stack **element, t_stack *prev, t_stack *next)
{
	*element = malloc(sizeof(t_stack));
	if (*element == NULL)
		return (-1);
	(*element)->value = num;
	(*element)->prev = prev;
	(*element)->next = next;
	return (1);
}

void	modify_element(t_stack **element, t_stack *prev, t_stack *next)
{
	if (prev)
		(*element)->prev = prev;
	if (next)
		(*element)->next = next;
}

int	add_my_element_to_my_stack(t_stack **my_stack, int num)
{
	t_stack	*first_element;
	t_stack	*last_element;
	t_stack	*my_element;

	if (*my_stack == NULL)
	{
		if (new_element(num, &my_element, NULL, NULL) == -1)
			return (-1);
		modify_element(&my_element, my_element, my_element);
		*my_stack = my_element;
	}
	else
	{
		first_element = get_element_at_position(1, *my_stack);
		last_element = get_last_of_my_stack(*my_stack);
		if (new_element(num, &my_element, last_element, first_element) == -1)
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
