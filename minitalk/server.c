/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:23:24 by witong            #+#    #+#             */
/*   Updated: 2024/08/20 12:40:44 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "srcs/ft_printf.h"
#include <stdlib.h>

int	main (int ac, char **av)
{
	int	pid;

	pid = getpid();
	while (1)
	{
		if (atoi(av[1]) == pid)
			ft_printf("YES");
		pause ();
	}
	return (0);
}
