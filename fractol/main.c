/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:01:34 by witong            #+#    #+#             */
/*   Updated: 2024/09/07 17:06:08 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
We need fractal Julia and Mandelbroth and krystal or fibo
cmd line to discipline fractal
shape with x y coordinates
ESC and X close no leaks
./fractol mandelbrot
./fractol julia <real> <imgry>
TL,DR of the app
*/

#include "fractol.h"

int close_window(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC_KEY)
		exit(0);
	return (0);
}

int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;


	if (ac >= 2 && ac <= 4 && (ft_strcmp(av[1], "mandelbrot") == 0
		|| ft_strcmp(av[1], "julia") == 0))
	{
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "Fractol Window");
		mlx_key_hook(win_ptr, close_window, NULL);
		mlx_loop(mlx_ptr);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 2);
		return (0);
	}
	return (0);
}
