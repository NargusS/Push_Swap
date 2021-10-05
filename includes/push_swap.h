/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:10:30 by achane-l          #+#    #+#             */
/*   Updated: 2021/10/05 19:26:52 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef	struct	s_chunk
{
	t_stack *first;
	t_stack	*last;
	struct	s_chunk	*next;
}				t_chunk;

int		new_element(int num, t_stack **element, t_stack *prev, t_stack *next);
int		add_my_element_to_my_stack(t_stack **my_stack, int num);
void	modify_element(t_stack **element, t_stack *prev, t_stack *next);
void	free_my_stack(t_stack **my_stack);

int		get_size_of_my_stack(t_stack *my_stack);
t_stack	*get_element_at_position(int position, t_stack *my_stack);
t_stack	*get_last_of_my_stack(t_stack *my_stack);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

void	get_arg_add_to_stack_a(t_stack **stack_a, int argc, char **argv);
void	check_error_with_and_without_message(t_stack **stack_a, char *arg);
int		atoi_and_add(t_stack **stack_a, char *arg);


//test

int	get_good_position(t_stack *stack_to_place, t_stack *elements);
void	push_in_good_place(t_stack **stack_a, t_stack **stack_b);
void	sort_test(t_stack **stack_a, t_stack **stack_b,t_chunk *chunks);
int		is_in_chunk(t_stack *element, t_chunk *chunk);
void	chunks_func(t_stack *stack_a, t_chunk **chunks);
void	add_chunk_to_chunks(t_chunk **chunks, t_stack *first_elem, t_stack *last_elem);
t_chunk	*create_chunk(t_stack *first_elem, t_stack *last_elem);
int		stack_b_is_sorted(t_stack *stack_b);
#endif