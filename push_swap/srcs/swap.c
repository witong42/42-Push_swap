/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 03:50:57 by witong            #+#    #+#             */
/*   Updated: 2024/09/27 08:57:13 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack *stack)
{
	int	tmp;

	if(stack == NULL || stack_next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	sa(t_stack **a)
{
	swap(*a);
	ft_putstr("sa\n");
}
void	sb(t_stack **b)
{
	swap(*b);
	ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_putstr("ss\n");
}
