/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:32:09 by witong            #+#    #+#             */
/*   Updated: 2024/10/21 17:12:46 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstd_new(int value)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->value = value;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

int	ft_lstd_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

static t_stack	*ft_lstd_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstd_add_back(t_stack **lst, t_stack *back)
{
	t_stack	*last;

	if (!lst || !back)
		return ;
	if (!*lst)
	{
		*lst = back;
		return ;
	}
	last = ft_lstd_last(*lst);
	last->next = back;
	back->prev = last;
}
