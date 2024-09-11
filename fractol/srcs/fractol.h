/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:10:05 by witong            #+#    #+#             */
/*   Updated: 2024/09/10 18:52:44 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

#define ERROR_MSG "Incorrect inputs, Please enter\n\t./fractol mandelbrot\n\tor\n\t./fractol julia <value1> <value2>\n"
#define SIZE 800
/* For practical purpose we want the window to be squared,
so we use SIZE instead of HEIGHT and WIDTH. */

// hooks codes
# define ESC			53
# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define R				15
# define C				8
# define H				4
# define J				38
# define P				35
# define M				46
# define SCROLL_UP		4
# define SCROLL_DOWN	5

// colors
#define BLACK			0x000000
#define WHITE			0xFFFFFF
#define RED				0xFF0000
#define GREEN			0x00FF00
#define BLUE			0x0000FF
#define MAGENTA_BURST	0xFF00FF  // A vibrant magenta
#define LIME_SHOCK		0xCCFF00  // A blinding lime
#define NEON_ORANGE		0xFF6600  // A blazing neon orange
#define PSYCH_PURPLE	0x660066  // A deep purple
#define AQUA_DREAM		0x33CCCC  // A bright turquoise
#define HOT_PINK		0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE	0x0066FF  // A radiant blue
#define LAVA_RED		0xFF3300  // A bright, molten red

// structs
typedef struct	s_fractal
{
	char	*name;
	void	*mlx; //mlx_init();
	void	*win; //mlx_new_window();
	void	*img; //mlx_new_image();
	char	*pxl_img; //mlx_get_data_addr();
	int			bpp; //bits per pixels
	int			size_line; //where the line is written
	int			endian; // where the endian is written
	int		color;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		max_iterations;
}		t_fractal;

// utils.c
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);

// init.c
void	fract_init(t_fractal *fract);

#endif
