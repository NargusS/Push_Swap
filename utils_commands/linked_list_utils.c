/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:43:49 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/27 19:11:24 by achane-l         ###   ########.fr       */
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

int	add_my_element_to_my_stack(t_data *stacks, int num)
{
	t_stack	*my_element;
	t_stack	*first_element;
	t_stack	*last_element;

	if (stacks->stack_a == NULL)
	{
		if (new_element(num, &my_element, NULL, NULL) == -1)
			return (-1);
		modify_element(&my_element, my_element, my_element);
		stacks->stack_a = my_element;
	}
	else
	{
		first_element = stacks->stack_a;
		last_element = (stacks->stack_a)->prev;
		if (new_element(num, &my_element, last_element, first_element) == -1)
			return (-1);
		first_element->prev = my_element;
		last_element->next = my_element;
	}
	stacks->size_stack_a += 1;
	return (1);
}

void	free_my_stack(t_stack **my_stack)
{
	t_stack	*current;
	t_stack	*prev_element;

	if (*my_stack)
	{
		current = (*my_stack)->prev;
		prev_element = current->prev;
		while (prev_element != NULL && current != *my_stack)
		{
			printf("elem : %d\n", current->value);
			free(current);
			current = prev_element;
			prev_element = current->prev;
		}
		printf("elem : %d\n", current->value);
		free(current);
	}
}
