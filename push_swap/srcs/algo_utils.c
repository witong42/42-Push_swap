/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:30:48 by witong            #+#    #+#             */
/*   Updated: 2024/10/20 12:06:26 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	t_stack *smallest;

	smallest = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*find_best_move(t_stack *stack)
{
	while (stack)
	{
		if (stack->best_move)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *best_move)
{
	while (*a != best_move->target && *b != best_move)
		rr(a, b);
	set_current_index(*a);
	set_current_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *best_move)
{
	while (*a != best_move->target && *b != best_move)
		rrr(a, b);
	set_current_index(*a);
	set_current_index(*b);
}

void	optimize_rotation(t_stack **stack, t_stack *to_push, char stack_name)
{
	while (*stack != to_push)
	{
		if (stack_name == 'a')
		{
			if (to_push->above_mid)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (to_push->above_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
