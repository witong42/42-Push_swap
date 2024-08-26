/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:23:32 by witong            #+#    #+#             */
/*   Updated: 2024/08/26 12:59:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

static int	ft_atoi(char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (sign * res);
}

static void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t		pid;
	int			i;
	const char	*msg;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			return (ft_printf("Error: Provided PID is \
incorrect or negative.\n") && 1);
		msg = av[2];
		while (msg[i])
			ft_send_bits(pid, msg[i++]);
		ft_send_bits(pid, '\n');
		ft_send_bits(pid, '\0');
	}
	else
		return (ft_printf("Error: wrong format.\nCorrect\
Format: ./client <PID> <MESSAGE>\n") && 1);
	return (0);
}
