/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:10:05 by witong            #+#    #+#             */
/*   Updated: 2024/09/10 18:14:19 by witong           ###   ########.fr       */
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

#define ESC_KEY 65307

/* For practical purpose we want the window to be squared,
so we use SIZE instead of HEIGHT and WIDTH. */

// Structs
typedef struct	s_fractal
{
	void	*mlx; //mlx_init();
	void	*win; //mlx_new_window();
	void	*img; //mlx_new_image();
	char	*pxl_img; //mlx_get_data_addr();
	int		bpp; //bits per pixels
	int		size_line; //where the line is written
	int		endian; // where the endian is written
}		t_fractal;

// utils.c
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);

#endif
