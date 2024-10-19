/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:08:12 by witong            #+#    #+#             */
/*   Updated: 2024/10/19 10:24:18 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *a)
{
	int		min;
	t_stack	*current;

	current = a;
	min = current->value;
	while (current != NULL)
	{
		if (min > current->value)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_largest(t_stack *a)
{
	int		max;
	t_stack	*current;

	current = a;
	max = current->value;
	while (current != NULL)
	{
		if (max < current->value)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_middle(t_stack *a)
{
	int		min;
	int		max;

	min = find_smallest(a);
	max = find_largest(a);

	return ((min + max) / 2);
}

int	calculate_optimal_rotation(t_stack *stack, int target_index)
{
	int	stack_size;
	int	mid_point;

	stack_size = ft_lstd_size(stack);
	mid_point = stack_size / 2;

	if (target_index <= mid_point)
		return (target_index);
	return (target_index - stack_size);
}

void optimize_rotation(t_stack **a, t_stack **b, int target_index_a, int target_index_b)
{
	int rotate_a = calculate_optimal_rotation(*a, target_index_a);
	int rotate_b = calculate_optimal_rotation(*b, target_index_b);

	while (rotate_a > 0 && rotate_b > 0 && rotate_a-- && rotate_b--)
		rr(a, b);
	while (rotate_a < 0 && rotate_b < 0 && rotate_a++ && rotate_b++)
		rrr(a, b);
	while (rotate_a > 0 && rotate_a--)
		ra(a);
	while (rotate_a < 0 && rotate_a++)
		rra(a);
	while (rotate_b > 0 && rotate_b--)
		rb(b);
	while (rotate_b < 0 && rotate_b++)
		rrb(b);
}
