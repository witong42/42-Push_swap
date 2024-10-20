/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:08:12 by witong            #+#    #+#             */
/*   Updated: 2024/10/20 07:54:44 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_extreme_node(t_stack *stack, char type)
{
	t_stack		*extreme_node;

	if (!stack)
		return (NULL);
	extreme_node = stack;
	stack = stack->next;
	while (stack)
	{
		if ((type == 's' && stack->value < extreme_node->value) ||
			(type == 'l' && stack->value > extreme_node->value))
			extreme_node = stack;
		stack = stack->next;
	}
	return (extreme_node);
}

t_stack	*find_smallest_node(t_stack *stack)
{
	return (find_extreme_node(stack, 's'));
}

t_stack	*find_largest_node(t_stack *stack)
{
	return (find_extreme_node(stack, 'l'));
}

int	find_nearest(int value, t_stack *stack)
{
	int	nearest;
	int	diff;
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	nearest = current->value;
	diff = abs(value - current->value);
	current = current->next;
	while (current)
	{
		if (abs(value - current->value) < diff)
		{
			diff = abs(value - current->value);
			nearest = current->value;
		}
		current = current->next;
	}
	return (nearest);
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
