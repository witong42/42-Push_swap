/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:38:07 by witong            #+#    #+#             */
/*   Updated: 2024/09/22 16:27:41 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_switch(t_fractal *fract, double *cx, double *cy, double zx, double zy)
{
	if (ft_strcmp(fract->name, "julia") == 0)
	{
		*cx = fract->cx;
		*cy = fract->cy;
	}
	else
	{
		*cx = zx;
		*cy = zy;
    }
}
int calculate(t_fractal *fract, int x, int y)
{
    int i;
    double tmp;
    double zx;
    double zy;
    double cx;
    double cy;

    zx = ((4.0 * x / SIZE - 2.0) * fract->zoom) + fract->shift_x;
    zy = ((4.0 * y / SIZE - 2.0) * fract->zoom) + fract->shift_y;
    fract_switch(fract, &cx, &cy, zx, zy);
    i = 0;
    while (i < fract->max_iterations)
    {
        tmp = zx;
        zx = zx * zx - zy * zy + cx;
        zy = 2 * tmp * zy + cy;
        if (zx * zx + zy * zy > 4)
            break;
        i++;
    }
    if (i == fract->max_iterations)
        return 0x000000;
    else
        return (fract->color * (i % 255));
}

void fract_render(t_fractal *fract)
{
	int x;
	int y;
	int color;
	char *pixel;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			color = calculate(fract, x, y);
			pixel = fract->pxl_img + (y * fract->size_line + x * (fract->bpp / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
	y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
