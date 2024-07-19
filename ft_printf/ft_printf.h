/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 03:01:56 by witong            #+#    #+#             */
/*   Updated: 2024/07/19 03:02:01 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printptr(unsigned long ptr);
int	ft_printnbr(int nbr);
int	ft_printuint(unsigned int unbr);
int	ft_printhex(unsigned int hex, char format);

#endif
