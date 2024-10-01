/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:37:04 by witong            #+#    #+#             */
/*   Updated: 2024/10/01 06:20:09 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL || *dst == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src ;
	*src = tmp;
}

void pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr("pa\n");
}
void pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
