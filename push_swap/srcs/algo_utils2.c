/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:24:33 by witong            #+#    #+#             */
/*   Updated: 2024/10/23 08:46:21 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sets the current index and above_mid flag for each node in the stack.
void	set_current_index(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = ft_lstd_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->above_mid = (i <= middle);
		stack = stack->next;
		++i;
	}
}

// Sets the target node in stack 'a' for each node in stack 'b'.
void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		target = NULL;
		current = a;
		while (current)
		{
			if (current->value > b->value && current->value < best_index)
			{
				best_index = current->value;
				target = current;
			}
			current = current->next;
		}
		if (LONG_MAX == best_index)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

// Calculate the cost of nodes in stack 'b' based on index and target.
void	set_cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstd_size(a);
	size_b = ft_lstd_size(b);
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_mid))
			b->cost = size_b - (b->index);
		if (b->target->above_mid)
			b->cost += b->target->index;
		else
			b->cost += size_a - (b->target->index);
		b = b->next;
	}
}

// Sets the best move in stack 'b' based on the lowest cost.
void	set_best_move(t_stack *b)
{
	long	best_value;
	t_stack	*best_node;

	if (NULL == b)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->cost < best_value)
		{
			best_value = b->cost;
			best_node = b;
		}
		b = b->next;
	}
	best_node->best_move = true;
}

// Moves the smallest node in stack 'a' to the top.
void	smallest_to_top(t_stack **a)
{
	t_stack	*best_move;

	set_current_index(*a);
	best_move = find_smallest(*a);
	if (best_move->above_mid)
		while (*a != best_move)
			ra(a);
	else
		while (*a != best_move)
			rra(a);
}
