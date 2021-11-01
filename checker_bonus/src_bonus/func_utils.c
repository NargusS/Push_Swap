/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:42:30 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/01 18:22:55 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
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
	free(s1);
	return (str2);
}

static int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (1);
	while (s1 && *s1 && s2 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (s1 && *s1 == 0 && s2 && *s2 == 0)
		return (1);
	return (0);
}

static void	do_cmd(t_data *stacks, char **cmd)
{
	if (ft_strcmp(*cmd, "pa") == 1)
		push_a(&stacks->stack_a, &stacks->stack_b, stacks);
	else if (ft_strcmp(*cmd, "pb") == 1)
		push_b(&stacks->stack_a, &stacks->stack_b, stacks);
	else if (ft_strcmp(*cmd, "sa") == 1)
		swap_a(stacks->stack_a);
	else if (ft_strcmp(*cmd, "sb") == 1)
		swap_b(stacks->stack_b);
	else if (ft_strcmp(*cmd, "ss") == 1)
		swap_s(stacks);
	else if (ft_strcmp(*cmd, "ra") == 1)
		rotate_a(&stacks->stack_a);
	else if (ft_strcmp(*cmd, "rb") == 1)
		rotate_b(&stacks->stack_b);
	else if (ft_strcmp(*cmd, "rr") == 1)
		rotate_a_and_b(&stacks->stack_a, &stacks->stack_b);
	else if (ft_strcmp(*cmd, "rra") == 1)
		reverse_rotate_a(&stacks->stack_a);
	else if (ft_strcmp(*cmd, "rrb") == 1)
		reverse_rotate_b(&stacks->stack_b);
	else if (ft_strcmp(*cmd, "rrr") == 1)
		reverse_rotate_a_and_b(&stacks->stack_a, &stacks->stack_b);
	else
		exit_and_free(stacks, cmd);
}

void	read_input(t_data *stacks)
{
	int		res;
	char	*line;
	char	buffer[2];

	res = 1;
	line = NULL;
	while (res > 0)
	{
		res = read(1, buffer, 1);
		buffer[res] = 0;
		if (res == 0)
			return ;
		else if (buffer[0] != '\n')
			line = ft_strjoin(line, buffer);
		else
		{
			do_cmd(stacks, &line);
			free(line);
			line = NULL;
		}
	}
}
