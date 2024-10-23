/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 03:50:57 by witong            #+#    #+#             */
/*   Updated: 2024/10/23 09:16:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps the values of the first two nodes in the stack.
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

// Swaps the first two nodes of stack 'a' and prints "sa".
void	sa(t_stack **a)
{
	swap(*a);
	ft_putstr_fd("sa\n", 1);
}

// Swaps the first two nodes of stack 'b' and prints "sb".
void	sb(t_stack **b)
{
	swap(*b);
	ft_putstr_fd("sb\n", 1);
}

// Swaps the first two nodes of both stacks 'a' and 'b' and prints "ss".
void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_putstr_fd("ss\n", 1);
}
