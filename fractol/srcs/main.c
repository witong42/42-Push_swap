/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:01:34 by witong            #+#    #+#             */
/*   Updated: 2024/09/14 14:46:13 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Main that manage the input and window */
int	main(int ac, char **av)
{
	t_fractal	*fract;

	fract = malloc(sizeof(t_fractal));
	if (!fract)
		exit(EXIT_FAILURE);
	if (ac >= 2 && ac <= 4 && (ft_strcmp(av[1], "mandelbrot") == 0
		|| ft_strcmp(av[1], "julia") == 0))
	{

		ft_fract_init(fract);
		fract->name = av[1];
		ft_mlx_init(fract);
		fract_render(fract);
		mlx_key_hook(fract->win, key_events, fract);
		mlx_mouse_hook(fract->win, mouse_events, fract);
		mlx_loop(fract->mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 2);
		free(fract);
		exit(EXIT_FAILURE);
	}
	return (0);
}
