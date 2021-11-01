/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:48:38 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/29 19:30:08 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	initialize_all(t_data *stacks)
{
	stacks->size_stack_a = 0;
	stacks->size_stack_b = 0;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}

static void	load_algo(t_data *stacks)
{
	if (stacks->size_stack_a <= 5)
		sort_small_stacks(stacks);
	else
		sort_hundreds_num(stacks);
	free_my_stack(&stacks->stack_a);
	free_my_stack(&stacks->stack_b);
}

int	main(int argc, char **argv)
{
	t_data	stacks;

	initialize_all(&stacks);
	get_arg_add_to_stack_a(&stacks, argc, argv);
	load_algo(&stacks);
}
