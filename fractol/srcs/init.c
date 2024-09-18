/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:37:48 by witong            #+#    #+#             */
/*   Updated: 2024/09/14 14:41:00 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void close_window(t_fractal *fract)
{
	if (fract->img)
		mlx_destroy_image(fract->mlx, fract->img);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->mlx)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
	}
	free(fract);
	exit(EXIT_FAILURE);
}
void ft_fract_init(t_fractal *fract)
{
	fract->zoom = 1.0;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->cx = 0.37;
	fract->cy = 0.37;
	fract->max_iterations = 100;
	fract->color = 0x00AABB; // Example color
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, SIZE, SIZE, "Fractal");
	fract->img = mlx_new_image(fract->mlx, SIZE, SIZE);
	fract->pxl_img = mlx_get_data_addr(fract->img,
					&fract->bpp,
					&fract->size_line,
					&fract->endian);
}

void	ft_mlx_init(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		close_window(fract);
	fract->win = mlx_new_window(fract->mlx, SIZE, SIZE, fract->name);
	if (!fract->win)
		close_window(fract);
	fract->img = mlx_new_image(fract->mlx, SIZE, SIZE);
	if (!fract->img)
		close_window(fract);
	fract->pxl_img = mlx_get_data_addr(fract->img,
					&fract->bpp,
					&fract->size_line,
					&fract->endian);
	if (!fract->pxl_img)
		close_window(fract);
}
