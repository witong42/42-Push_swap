/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:08:17 by witong            #+#    #+#             */
/*   Updated: 2024/10/19 15:17:47 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a)
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
void	init_b(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	if (is_sorted(*b))
		rb(b);
}


void algo_sort(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	init_b(a, b);
	push_to_b(a, b);
	if (!is_sorted(*a))
		small_sort(*a);
	push_to_a(a, b);
	cheapest_node = 
}
