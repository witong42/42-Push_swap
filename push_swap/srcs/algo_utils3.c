/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:30:48 by witong            #+#    #+#             */
/*   Updated: 2024/10/19 20:02:22 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *best_move)
{
	while (*a != best_move->target
		&& *b != best_move)
		rr(a, b);
	set_current_index(*a);
	set_current_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *best_move)
{
	while (*a != best_move->target
		&& *b != best_move)
		rrr(a, b);
	set_current_index(*a);
	set_current_index(*b);
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_mid)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
