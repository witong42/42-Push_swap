/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:08:12 by witong            #+#    #+#             */
/*   Updated: 2024/10/19 16:20:07 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *(*stack))
{
	int		min;
	t_stack	*current;

	current = stack;
	min = current->value;
	while (current)
	{
		if (min > current->value)
			min = current->value;
		current = current->next;
	}
	return (min);
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

int	*find_biggest_ptr(t_stack **stack)
{
	int		max;
	t_stack	*current;

	current = (*stack);
	max = current->value;
	while (current)
	{
		if (max < current->value)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	*find_nearest_ptr(int value, t_stack **stack)
{
	int	*nearest;
	int	*diff;

	nearest = (*stack)->value;
	diff = abs(value - (*stack)->value);
	(*stack) = (*stack)->next;

	while (*stack)
	{
		if (abs(value - (*stack)->value) < diff)
		{
			diff = abs(value - (*stack)->value);
			nearest = (*stack)->value;
		}
		(*stack) = (*stack)->next;
	}
	return (nearest);
}
