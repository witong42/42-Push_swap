/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:32:09 by witong            #+#    #+#             */
/*   Updated: 2024/10/15 20:16:44 by witong           ###   ########.fr       */
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

int	ft_lstdsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
		lst = lst->prev;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);

}
t_stack	*ft_lstd_first(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_stack	*ft_lstd_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstd_add_front(t_stack **lst, t_stack *front)
{
	if (!lst || !front)
		return ;
	front->next = *lst;
	if (*lst)
		(*lst)->prev = front;
	*lst = front;
}

void	ft_lstd_add_back(t_stack **lst, t_stack *back)
{
	t_stack *last;

	if (!lst || !back)
		return;
	if (!*lst)
	{
		*lst = back;
		return;
	}
	last = ft_lstd_last(*lst);
	last->next = back;
	back->prev = last;
}



/*
int main (void)
{
	t_stack *node00;
	t_stack node01;
	t_stack node02;

	node00 = ft_lstdnew(42);

	printf ("Node 0 , value %d", node00->value);

}
*/
