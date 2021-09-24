/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:23:03 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/24 19:37:44 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*new_first;
	if (*stack_a && (*stack_a)->next != NULL)
	{
		new_first = get_element_at_position(2, stack_a);
		*stack_a = new_first;
	}
}