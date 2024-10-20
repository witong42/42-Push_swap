/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:08:17 by witong            #+#    #+#             */
/*   Updated: 2024/10/20 08:47:51 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		|| (*a)->next->value < (*a)->next->next->value)
		ra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
	if ((*a)->next->value > (*a)->next->next->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
static void	init_b(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	if (is_sorted(*b))
		rb(b);
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target(a, b);
	set_cost(a, b);
	set_best_move(b);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int stack_size;

    stack_size = ft_lstd_size(*a);
    while (stack_size > 3)
    {
        if (find_nearest((*a)->value, *a))
			pb(a, b);
		else
			ra(a);
		stack_size = ft_lstd_size(*a);
    }
}
void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best_move;

	best_move = find_best_move(*b);
	if (best_move->above_mid
		&& best_move->target->above_mid)
		rotate_both(a, b, best_move);
	else if (!(best_move->above_mid)
		&& !(best_move->target->above_mid))
		reverse_rotate_both(a, b, best_move);
	finish_rotation(b, best_move, 'b');
	finish_rotation(a, best_move->target, 'a');
	pa(a, b);
}

void algo_sort(t_stack **a, t_stack **b)
{
	init_b(a, b);
	push_to_b(a, b);
	if (!is_sorted(*a))
		sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		push_to_a(a, b);
	}
	smallest_to_top(a);
}
