/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:08:17 by witong            #+#    #+#             */
/*   Updated: 2024/10/19 11:56:29 by witong           ###   ########.fr       */
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

void sort_middle(t_stack **a, t_stack **b)
{
    int middle_value;
    int stack_size;
    int i;

	i = 0;
	stack_size = ft_lstd_size(*a);
	middle_value = find_middle(*a);
	while (*a && stack_size / 2 > i)
	{
		if ((*a)->value <= middle_value)
			pb(a, b);
		else
			ra(a);
		i++;
		stack_size = ft_lstd_size(*a);
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
    int stack_size;
    int i;

    i = 0;
    stack_size = ft_lstd_size(*a);
    while (stack_size - i > 3)
    {
        pb(a, b);
        i++;
		stack_size = ft_lstd_size(*a);
    }
    small_sort(a);
}

void algo_sort(t_stack **a, t_stack **b)
{
    int target_index_a;
    int target_index_b;

    target_index_a = 0;
    target_index_b = 0;
    sort_middle(a, b);
    assign_index(a, b);
    optimize_rotation(a, b, target_index_a, target_index_b);
    push_to_b(a, b);
    while (*b)
    {
        target_index_a = find_insert_position(*a, (*b)->value);
        target_index_b = (*b)->index;
        optimize_rotation(a, b, target_index_a, target_index_b);
        pa(a, b);
    }

    if (!is_sorted(*a))
        align_stack(a);
}
