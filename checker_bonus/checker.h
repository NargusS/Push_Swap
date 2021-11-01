/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:43:00 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/01 18:22:52 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define PRINT_CMD 1
# define NO_PRINT_CMD 0

typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	struct s_stack	*next;
}				t_stack;
typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_stack_a;
	int		size_stack_b;
}				t_data;

void	check_error(t_data *stacks, char *arg);
void	get_arg_add(t_data *stacks, int argc, char **argv);
int		atoi_and_add(t_data *stacks, char *arg);

void	read_input(t_data *stacks);
void	exit_and_free(t_data *stacks, char **cmd);
int		ft_strlen(char *str);

int		new_element(int num, t_stack **elem, t_stack *prev, t_stack *next);
void	modify_element(t_stack **elem, t_stack *prev, t_stack *next);
int		add_my_element_to_my_stack(t_data *stacks, int num);
void	free_my_stack(t_stack **my_stack);

void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_s(t_data *stacks);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b, t_data *stacks);
void	push_b(t_stack **stack_a, t_stack **stack_b, t_data *stacks);
#endif