/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:36:52 by witong            #+#    #+#             */
/*   Updated: 2024/10/23 09:11:04 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves the last node to the first position in the given stack.
static void	reverse(t_stack **stack)
{
	t_stack	*last;
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstd_last(*stack);
	current = *stack;
	while (current->next != last)
		current = current->next;
	current->next = NULL;
	last->next = *stack;
	*stack = last;
}

// Reverse rotates stack a and prints "rra".
void	rra(t_stack **a)
{
	reverse(a);
	ft_putstr_fd("rra\n", 1);
}

// Reverse rotates stack b and prints "rrb".
void	rrb(t_stack **b)
{
	reverse(b);
	ft_putstr_fd("rrb\n", 1);
}

// Reverse rotates both stacks a and b, then prints "rrr".
void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	ft_putstr_fd("rrr\n", 1);
}
