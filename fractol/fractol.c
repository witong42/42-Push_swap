/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:01:34 by witong            #+#    #+#             */
/*   Updated: 2024/09/06 10:45:51 by witong           ###   ########.fr       */
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

int main(int ac, char **av)
{
	if (ac >= 2 && ac <= 4 && (ft_strcmp(av[1], "mandelbrot") == 0
		|| ft_strcmp(av[1], "julia") == 0))
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			ft_putstr_fd("1\0", 1);
//			fractolapp(av[1]);
		else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
			ft_putstr_fd("2\0", 1);
//			fractolapp(av[1], av[2], av[3]);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol <mandelbrot|julia> [<real> <imgry>]\n", 2);
		return (0);
	}
}
