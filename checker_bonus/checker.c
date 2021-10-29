/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:05:13 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/29 21:06:03 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static void	initialize_all(t_data *stacks)
{
	stacks->size_stack_a = 0;
	stacks->size_stack_b = 0;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str2;
	size_t	i;
	size_t	j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str2 = malloc(len + 1);
	if (!str2)
		return (NULL);
	while (s1 && s1[i])
	{
		str2[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str2[i + j] = s2[j];
		j++;
	}
	str2[len] = '\0';
	return (str2);
}

void read_input(t_data *stacks)
{
	int res;
	char *line;
	char buffer[2];

	res = 1;
	line = NULL;
	while (res > 0)
	{
		res = read(1, buffer, 1);
		buffer[res] = 0;
		if (res == 0)
			return;
		else if (buffer[0] != '\n')
			line = ft_strjoin(line, buffer);
		else
		{
			//do_cmd(t_data *stacks, char **str)
			free(line);
			line = NULL;
		}
	}
}

int main(int argc, char **argv)
{
	t_data stacks;

	initialize_all(&stacks);
	get_arg_add(&stacks, argc, argv);
	do_cmd(&stacks);
}