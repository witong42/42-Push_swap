/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:08:17 by witong            #+#    #+#             */
/*   Updated: 2024/10/23 14:51:13 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to find the midpoint as an approximate median
static int	find_middle(t_stack *stack)
{
	int		min;
	int		max;
	t_stack	*current;

	current = stack;
	min = current->value;
	max = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return ((min + max) / 2);
}

// Push elements to Stack B using the midpoint as a partition
static void	push_to_b(t_stack **a, t_stack **b)
{
	int	middle;
	int	stack_size;
	int	i;

	i = 0;
	middle = find_middle(*a);
	stack_size = ft_lstd_size(*a);
	while (stack_size > i)
	{
		if ((*a)->value < middle)
		{
			pb(a, b);
			stack_size--;
		}
		else
		{
			ra(a);
			i++;
		}
	}
	while (stack_size-- > 3)
		pb(a, b);
	if (!is_sorted(*a))
		sort_three(a);
}

// Push nodes back to Stack A using a "greedy" algo.
static void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best_move;

	best_move = find_best_move(*b);
	if (best_move && best_move->target
			&& best_move->above_mid && best_move->target->above_mid)
		rotate_both(a, b, best_move);
	else if (best_move && !(best_move->above_mid)
			&& !(best_move->target->above_mid))
		reverse_rotate_both(a, b, best_move);
	optimize_rotation(b, best_move, 'b');
	optimize_rotation(a, best_move->target, 'a');
	pa(a, b);
}

// Initializes nodes in stacks 'a' and 'b'
// with index, target, cost, and best move.
static void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target(a, b);
	set_cost(a, b);
	set_best_move(b);
}

// Custom sort algorithm for stacks 'a' and 'b'
// using midpoint quicksort and "mechanical turk."
void	custom_sort(t_stack **a, t_stack **b)
{
	push_to_b(a, b);
	while (*b)
	{
		init_nodes(*a, *b);
		push_to_a(a, b);
	}
	smallest_to_top(a);
}
