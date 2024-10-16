/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:13:16 by witong            #+#    #+#             */
/*   Updated: 2024/10/15 20:41:24 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*atolist(const char *str)
{
	t_stack	*head;
	t_stack	*new_node;
	const char	*start;
	const char	*end;
	int		value;

	head = NULL;
	start = str;
	while (*start)
	{
		while (*start == ' ')
			start++;
		if (*start == '\0')
			break ;
		end = start;
		while (*end && *end != ' ')
			end++;
		value = ft_atoi(start);
		new_node = ft_lstd_new(value);
		ft_lstd_add_back(&head, new_node);
		start = end;
	}
	return (head);
}


void	print_list(t_stack *head)
{
	t_stack *lst = head;
	while (lst != NULL)
	{
		ft_printf("%d\n", lst->value);
		lst = lst->next;
	}
}
