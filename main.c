/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:26:03 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/24 16:28:41 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack **stack_a;
	t_stack **stack_b;

	initialize_my_stack(&stack_a);
	add_my_element_to_my_stack(stack_a, 10);
	add_my_element_to_my_stack(stack_a, 20);
	add_my_element_to_my_stack(stack_a, 30);
	add_my_element_to_my_stack(stack_a, 40);
	add_my_element_to_my_stack(stack_a, 50);
	add_my_element_to_my_stack(stack_a, 60);
	add_my_element_to_my_stack(stack_a, 70);
	add_my_element_to_my_stack(stack_a, 80);
	free_my_stack(stack_a);
	return 0;
}