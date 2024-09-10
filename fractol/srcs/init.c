#include "fractol.h"

void	fract_init(t_fractal *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, SIZE, SIZE, "Fractol");
	fract->img = mlx_new_image(fract->mlx, SIZE, SIZE);
	fract->ptr_img = mlx_get_data_addr(fract->img,
					&fract->bpp,
					&fract->size_line,
					&fract->endian);
}
