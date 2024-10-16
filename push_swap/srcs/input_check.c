/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:00:01 by witong            #+#    #+#             */
/*   Updated: 2024/10/16 10:23:30 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//arg is num
static int	arg_is_num(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

//arg is unique

//arg is zero

//is_valid_input
int	is_valid_input(char **av)
{
	int	i;
	char	**args;

	i = 0;
	if (av == 2)
		args = ft_split(av, ' ');
	else
	{
		i = 1;
		args = av;
	}
	while(args[i])
	{
		if (!arg_is_num)
			Error
		if (!arg_is_unique)
			Error
		if (arg_is_zero)
			Error
	}
}


