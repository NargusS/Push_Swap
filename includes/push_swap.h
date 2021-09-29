#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_stack
{
	struct s_stack *prev;
	int	value;
	struct s_stack *next;
}				t_stack;

int	create_element(int num, t_stack **my_element,t_stack *prev, t_stack *next);
void	modify_element(t_stack **my_element,t_stack *prev, t_stack *next);
t_stack	*get_element_at_position(int position, t_stack *my_stack);
t_stack	*get_last_of_my_stack(t_stack *my_stack);
int	add_my_element_to_my_stack(t_stack **my_stack, int num);
void	free_my_stack(t_stack **my_stack);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_a_and_b(t_stack **stack_a,t_stack **stack_b);

void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_a_and_b(t_stack **stack_a,t_stack **stack_b);

void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_and_b(t_stack **stack_a,t_stack **stack_b);

void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
#endif