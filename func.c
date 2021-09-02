/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:01:09 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/02 18:12:30 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_element(int number)
{
	t_stack *new_element;

	new_element = malloc(sizeof(t_stack));
	new_element->prev = new_element;
	new_element->value = number;
	new_element->aft = new_element;

	return (new_element);
}

void	append_number_to_stacks(t_stack *stacks, int number)
{
	t_stack *element;
	t_stack	*first;
	t_stack	*last;

	element = create_element(number);
	if (stacks)
	{
		first = stacks;
		last = stacks->prev;
		last->aft = element;
		element->prev = last;
		element->aft = first;
		first->prev = element;
	}
	else
		stacks = element;
}

int main()
{
	t_stack *elements=NULL;

	append_number_to_stacks(elements, 10);
	append_number_to_stacks(elements, 25);
	printf("%p", elements);
}