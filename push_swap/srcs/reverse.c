/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:36:52 by witong            #+#    #+#             */
/*   Updated: 2024/10/01 08:11:21 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	first;
	t_stack	last;
	t_stack current;

	if (*stack == NULL || (*stack)->next == NULL)
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
	ft_putstr("rra\n");
}

void	rrb(t_stack **b)
{
	reverse(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	ft_putstr("rrr\n");
}
