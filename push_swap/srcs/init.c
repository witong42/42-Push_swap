/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:54:06 by witong            #+#    #+#             */
/*   Updated: 2024/10/17 06:03:45 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*init_stack(int ac, char **av)
{
	t_stack		*a;
	long int	nb;
	int			i;

	a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			handle_error(&a, NULL);
		if (i == 1)
			a = ft_lstd_new((int)nb);
		else
			ft_lstd_add_back(&a, ft_lstd_new((int)nb));
		i++;
	}
	return (a);
}
