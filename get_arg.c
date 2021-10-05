/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:23:16 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/29 19:59:33 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	get_arg_add_to_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		check_error_with_and_without_message(stack_a, argv[i++]);
	}
}

int	atoi_and_add(t_stack **stack_a, char *arg)
{
	long long int	num;
	long long int	sign;

	num = 0;
	sign = 1;
	if (*arg != 0)
	{
		if (*arg == '0' && *(arg + 1) != '\0')
			return (-1);
		if (*arg == '-')
		{
			sign = -1;
			arg++;
		}
		while (*arg >= '0' && *arg <= '9')
		{
			num = (num * 10) + (*arg - 48);
			arg++;
		}
		if (*arg != '\0' || num < INT_MIN || num > INT_MAX)
			return (-1);
		add_my_element_to_my_stack(stack_a, num * sign);
		return (1);
	}
	return (0);
}