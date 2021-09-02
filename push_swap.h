/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:53:29 by achane-l          #+#    #+#             */
/*   Updated: 2021/09/02 17:21:26 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <libc.h>
typedef struct	s_stack
{
    struct s_stack *prev;
	int	value;
	struct s_stack *aft;
}				t_stack;

#endif