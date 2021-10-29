/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:40:13 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/27 20:27:32 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	check_if_double_cmd(t_data *stacks, int pos_a, int pos_b)
{
	int	i;

	i = 1;
	if (pos_a <= stacks->size_stack_a / 2 && pos_b <= stacks->size_stack_b / 2)
	{
		while (i <= pos_a - 1 && i <= pos_b - 1)
		{
			rotate_a_and_b(&stacks->stack_a, &stacks->stack_b);
			i++;
		}
	}
	if (pos_a > stacks->size_stack_a / 2 && pos_b > stacks->size_stack_b / 2)
	{
		while (i < (stacks->size_stack_a - pos_a) + 1 && \
		i < (stacks->size_stack_b - pos_b) + 1)
		{
			reverse_rotate_a_and_b(&stacks->stack_a, &stacks->stack_b);
			i++;
		}
	}
	return (i);
}

static void	do_rr_rra(t_data *stacks, int good_pos, int nb_cmd_done)
{
	if (good_pos <= stacks->size_stack_a / 2)
	{
		while (nb_cmd_done <= good_pos - 1)
		{
			rotate_a(&stacks->stack_a, PRINT_CMD);
			nb_cmd_done++;
		}
	}
	else
	{
		while (nb_cmd_done <= (stacks->size_stack_a - good_pos + 1))
		{
			reverse_rotate_a(&stacks->stack_a, PRINT_CMD);
			nb_cmd_done++;
		}
	}
}

static void	replace_stack(t_data *stacks)
{
	t_stack	*min;
	int		i;

	min = get_min_of_my_stack(stacks->stack_a, stacks->size_stack_a);
	if (stacks->stack_a != min)
	{
		i = get_pos_of_elem(stacks->stack_a, min, stacks->size_stack_a);
		if (i <= stacks->size_stack_a / 2)
		{
			while (stacks->stack_a != min)
				rotate_a(&stacks->stack_a, PRINT_CMD);
		}
		else
		{
			while (stacks->stack_a != min)
				reverse_rotate_a(&stacks->stack_a, PRINT_CMD);
		}
	}
}

void	insertion_sort(t_data *stacks, t_stack *best_elem)
{
	int	i;
	int	pos_a;
	int	pos_b;

	pos_a = get_pos_to_place(stacks->stack_a, best_elem, stacks->size_stack_a);
	pos_b = get_pos_of_elem(stacks->stack_b, best_elem, stacks->size_stack_b);
	i = check_if_double_cmd(stacks, pos_a, pos_b);
	while (best_elem != stacks->stack_b)
	{
		if (pos_b <= stacks->size_stack_b / 2)
			rotate_b(&stacks->stack_b, PRINT_CMD);
		else
			reverse_rotate_b(&stacks->stack_b, PRINT_CMD);
	}
	do_rr_rra(stacks, pos_a, i);
	push_a(&stacks->stack_a, &stacks->stack_b, stacks);
}

void	sort_hundreds_num(t_data *stacks)
{
	int	i;

	push_b_optimize(stacks);
	while (1)
	{
		if (!(stacks->stack_b))
		{
			replace_stack(stacks);
			return ;
		}
		insertion_sort(stacks, get_best_move(*stacks));
	}
}
