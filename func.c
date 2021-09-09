/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:01:09 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/09 17:34:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_element(t_stack *new_element, int value,t_stack *prev, t_stack *next)
{
	new_element->prev = prev;
	new_element->value = value;
	new_element->next = next;
}

void	append_int_to_stack(t_stack *choosen_stack, int num)
{
	t_stack *first;
	t_stack new_element;

	if (choosen_stack->next == NULL)
		create_element(choosen_stack, num,choosen_stack, choosen_stack);
	/*else
	{
		first = choosen_stack;
		while (choosen_stack->next != first)
			choosen_stack = choosen_stack->next;
		int_elem.prev = choosen_stack;
		int_elem.next = first;
		first->prev = &int_elem;
		choosen_stack->next = &int_elem;
	}*/
}

int main()
{
	t_stack element;

	append_int_to_stack(&element, 10);
	printf("%p\n", &element);
	printf("%d\n", element.value);
	printf("%p\n", element.prev);
	printf("%p\n", element.next);
}
