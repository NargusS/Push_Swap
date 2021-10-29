/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:23:16 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/29 19:58:16 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	get_arg_add(t_data *stacks, int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	while (i < argc)
		check_error(stacks, argv[i++]);
}

int	atoi_and_add(t_data *stacks, char *arg)
{
	long long int	num;
	long long int	sign;

	num = 0;
	sign = 1;
	if (*arg == 0)
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
	if (*arg != '\0' || num < INT_MIN || num > INT_MAX || \
	add_my_element_to_my_stack(stacks, num * sign) == -1)
		return (-1);
	return (1);
}
