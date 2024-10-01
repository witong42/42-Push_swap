/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:52:12 by witong            #+#    #+#             */
/*   Updated: 2024/09/27 08:56:33 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int	value;
	int index;
	struct s_stack *next
}		t_stack;

// swap.c
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);

// push.c
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);

// rotate.c
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);

// reverse.c
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
