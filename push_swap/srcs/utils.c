/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:13:16 by witong            #+#    #+#             */
/*   Updated: 2024/10/17 06:05:37 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *head)
{
	t_stack *lst = head;
	while (lst != NULL)
	{
		ft_printf("%d\n", lst->value);
		lst = lst->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	handle_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		free_stack(stack_a);
	if (b == NULL || *b != NULL)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 2)
	exit (1);
}
