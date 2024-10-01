/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:36:56 by witong            #+#    #+#             */
/*   Updated: 2024/09/30 09:17:07 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}
void ra(t_list **a)
{
	rotate(a);
	ft_putstr("ra\n");
}
void rb(t_list **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
