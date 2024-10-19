/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:08:12 by witong            #+#    #+#             */
/*   Updated: 2024/10/19 20:48:45 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	long			smallest;
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

int	find_biggest(t_stack *stack)
{
	int		max;
	t_stack	*current;

	current = stack;
	max = current->value;
	while (current)
	{
		if (max < current->value)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_nearest(int value, t_stack *stack)
{
	int	nearest;
	int	diff;

	nearest = stack->value;
	diff = abs(value - stack->value);
	stack = stack->next;

	while (stack)
	{
		if (abs(value - stack->value) < diff)
		{
			diff = abs(value - stack->value);
			nearest = stack->value;
		}
		stack = stack->next;
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
