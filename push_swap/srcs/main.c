/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:51:34 by witong            #+#    #+#             */
/*   Updated: 2024/10/16 09:56:44 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_args(int ac, char **av, t_stack **a)
{
	int	i;
	int	value;
	t_stack *new_node;

	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		new_node = ft_lstd_new(value);
		ft_lstd_add_back(a, new_node);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (ac < 2 || !av[1][0])
		return (1);
	else if (ac == 2)
		a = atolist(av[1]);
	else if (ac >= 3)
		multiple_args(ac, av, &a);
	print_list(a);
	return (0);
}
//cc main.c utils.c lstd.c -L../libft -lft
