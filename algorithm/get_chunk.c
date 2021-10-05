/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:27:25 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/05 18:31:09 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_chunk	*create_chunk(t_stack *first_elem, t_stack *last_elem)
{
	t_chunk *new_chunk;

	new_chunk = malloc(sizeof(t_stack));
	if (new_chunk ==  NULL)
		return(NULL);
	new_chunk->first = first_elem;
	new_chunk->last = last_elem;
	new_chunk->next = NULL;
	return (new_chunk);
}

void	add_chunk_to_chunks(t_chunk **chunks, t_stack *first_elem, t_stack *last_elem)
{
	t_chunk *new_chunk;
	t_chunk *head;
	t_chunk	*tmp;

	new_chunk = create_chunk(first_elem, last_elem);
	if (*chunks)
	{
		head = *chunks;
		while ((*chunks)->next != NULL)
			*chunks = (*chunks)->next;
		(*chunks)->next = new_chunk;
		*chunks = head;
	}
	else
		*chunks = new_chunk;
}

void	chunks_func(t_stack *stack_a, t_chunk **chunks)
{
	t_chunk new_chunk;
	t_stack *head_stack;
	t_stack *first_elem_chunk;
	t_stack *last_elem_chunk;

	if (stack_a)
	{
		head_stack = stack_a;
		while (head_stack->next != stack_a)
		{
			if (head_stack->next != stack_a && ((head_stack->next)->value > head_stack->value))
			{
				first_elem_chunk = head_stack;
				last_elem_chunk = head_stack->next;
				while ((last_elem_chunk != stack_a->prev) && (last_elem_chunk->value < last_elem_chunk->next->value))
					last_elem_chunk = last_elem_chunk->next;
				add_chunk_to_chunks(chunks, first_elem_chunk, last_elem_chunk);
				head_stack = last_elem_chunk;
			}
			if (head_stack->next != stack_a)
				head_stack = head_stack->next;
		}
	}
}

int		is_in_chunk(t_stack *element, t_chunk *chunk)
{
	t_stack	*element_chunk;

	while (chunk != NULL)
	{
		element_chunk = chunk->first;
		if (element == element_chunk)
			return (1);
		while (element_chunk != chunk->last)
		{
			element_chunk = element_chunk->next;
			if (element == element_chunk)
				return (1);
		}
		chunk = chunk->next;
	}
	return (0);
}