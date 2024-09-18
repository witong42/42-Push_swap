/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:38:07 by witong            #+#    #+#             */
/*   Updated: 2024/09/14 14:46:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// put_pxl_img is more efficient for large images than mlx_pixel_put
static void put_pxl_img(t_fractal *fract, int x, int y, int color)
{
	char *pixel;

	pixel = fract->pxl_img + (y * fract->size_line + x * (fract->bpp / 8));
	*(unsigned int *)pixel = color;
}

static int calculate_color(t_fractal *fract, int x, int y)
{
    double zx, zy, cx, cy;
    int i;
    double tmp;

    zx = 1.5 * (x - SIZE / 2) / (0.5 * fract->zoom * SIZE) + fract->shift_x;
    zy = (y - SIZE / 2) / (0.5 * fract->zoom * SIZE) + fract->shift_y;
    cx = fract->cx;
    cy = fract->cy;
    i = fract->max_iterations;
    while (zx * zx + zy * zy < 4 && i > 0)
    {
        tmp = zx * zx - zy * zy + cx;
        zy = 2.0 * zx * zy + cy;
        zx = tmp;
        i--;
    }
    if (i == 0)
        return BLACK;
    return (fract->color * i);
}

void fract_render(t_fractal *fract)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			color = calculate_color(fract, x, y);
			put_pxl_img(fract, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
