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

void	fract_init(t_fractal *fract)
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
