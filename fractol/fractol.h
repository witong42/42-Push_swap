/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:10:05 by witong            #+#    #+#             */
/*   Updated: 2024/09/06 10:42:59 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MSG "Incorrect inputs, Please enter\n\t" ./fractol mandelbrot\" or \n\t".fractol julia <value1> <value2>\"\n"

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;

}		t_fractal;

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);

#endif
