/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:41:38 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/01 18:42:52 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define PRINT_CMD 1
# define NO_PRINT_CMD 0
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

int			new_element(int num, t_stack **elem, t_stack *prev, t_stack *next);
void		modify_element(t_stack **elem, t_stack *prev, t_stack *next);
int			add_my_element_to_my_stack(t_data *stacks, int num);
void		free_my_stack(t_stack **my_stack);

void		get_arg_add_to_stack_a(t_data *stacks, int argc, char **argv);
int			atoi_and_add(t_data *stacks, char *arg);
void		check_error_with_and_without_message(t_data *stacks, char *arg);

int			get_pos_of_elem(t_stack *my_stack, t_stack *elem, int size_st);
int			get_pos_to_place(t_stack *my_stack, t_stack *elem, int size_st);
t_stack		*get_min_of_my_stack(t_stack *my_stack, int size_st);
t_stack		*get_max_of_my_stack(t_stack *my_stack, int size_st);

void		insertion_sort(t_data *stacks, t_stack *best_elem);
void		sort_hundreds_num(t_data *stacks);

t_stack		*get_median(t_stack *my_stack, int size_of_stack);
void		push_b_optimize(t_data *stacks);

t_stack		*get_best_move(t_data stacks);
int			stack_is_sort(t_stack *my_stack, int size_st);

void		sort_small_stacks(t_data *stacks);

void		swap_a(t_stack *stack_a, int check_print);
void		swap_b(t_stack *stack_b, int check_print);
void		swap_s(t_data *stacks);
void		rotate_a(t_stack **stack_a, int check_print);
void		rotate_b(t_stack **stack_b, int check_print);
void		rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate_a(t_stack **stack_a, int check_print);
void		reverse_rotate_b(t_stack **stack_b, int check_print);
void		reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void		push_a(t_stack **stack_a, t_stack **stack_b, t_data *stacks);
void		push_b(t_stack **stack_a, t_stack **stack_b, t_data *stacks);
#endif