/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:36:52 by witong            #+#    #+#             */
/*   Updated: 2024/10/17 11:53:34 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*current;

	if (!*stack || !*stack)
		return ;
	first = *stack;
	last = *stack;
	current = NULL;
	while (last->next != NULL)
	{
		current = last;
		last = last->next;
	}
	if (current != NULL)
		current->next = NULL;
	last->next = first;
	*stack = last;
}

void	rra(t_stack **a)
{
	reverse(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	reverse(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	ft_putstr_fd("rrr\n", 1);
}
