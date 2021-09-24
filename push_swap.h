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

int	initialize_my_stack(t_stack ***stack_a);
int	create_element(int num, t_stack **my_element,t_stack *previous, t_stack *next);
void	modify_element(t_stack **my_element,t_stack *previous, t_stack *next);
t_stack	*get_element_at_position(int position, t_stack **my_stack);
t_stack	*get_last_of_my_stack(t_stack **my_stack);
int	add_my_element_to_my_stack(t_stack **my_stack, int num);
void	free_my_stack(t_stack **my_stack);

void	swap_a(t_stack **stack_a);
#endif