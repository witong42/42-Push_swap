/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:37:43 by witong            #+#    #+#             */
/*   Updated: 2024/09/14 15:10:26 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int (*f)(int keycode, void *param)
int	key_events(int keycode, t_fractal *fract)
{
	if (keycode == ESC)
		close_window(fract);
	if (keycode == UP)
		fract->shift_y -= 0.1 / fract->zoom;
	if (keycode == DOWN)
		fract->shift_y += 0.1 / fract->zoom;
	if (keycode == LEFT)
		fract->shift_x -= 0.1 / fract->zoom;
	if (keycode == RIGHT)
		fract->shift_x += 0.1 / fract->zoom;
	if (keycode == R) // Reset fractal
		ft_fract_init(fract);
	fract_render(fract); //refresh img
	return (0);
}

// int (*f)(int button, int x, int y, void *param)
int	mouse_events(int button, int x, int y, t_fractal *fract)
{
    double mouse_re;
    double mouse_im;
    double zoom_factor;

    // Convert pixel coordinates to complex plane coordinates
    mouse_re = (double)x / (SIZE / (fract->zoom * 2)) - fract->zoom + fract->shift_x;
    mouse_im = (double)y / (SIZE / (fract->zoom * 2)) - fract->zoom + fract->shift_y;

    if (button == SCROLL_DOWN)
        zoom_factor = 1.05; // Increase zoom
    else if (button == SCROLL_UP)
        zoom_factor = 0.95; // Decrease zoom
    else
        return (0);

    // Adjust shift to keep the zoom centered around the mouse pointer
    fract->shift_x = mouse_re - ((double)x / (SIZE / (fract->zoom * 2 * zoom_factor)) - fract->zoom * zoom_factor);
    fract->shift_y = mouse_im - ((double)y / (SIZE / (fract->zoom * 2 * zoom_factor)) - fract->zoom * zoom_factor);

    fract->zoom *= zoom_factor;

    fract_render(fract); // Refresh image
    return (0);
}
