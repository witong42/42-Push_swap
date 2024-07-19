/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:50:39 by witong            #+#    #+#             */
/*   Updated: 2024/07/19 02:54:47 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printhexbase(unsigned long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_printhexbase(nbr / 16, base);
	i += ft_printchar(base[nbr % 16]);
	return (i);
}

int	ft_printptr(unsigned long ptr)
{
	int	i;

	i = 0;
	i += ft_printstr("0x");
	if (ptr == 0)
		i += ft_printchar('0');
	else
		i += ft_printhexbase(ptr, "0123456789abcdef");
	return (i);
}

int	ft_printnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		i += ft_printchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		i += ft_printnbr(nbr / 10);
	else
		i += ft_printchar(nbr % 10 + '0');
	return (i);
}

int	ft_printuint(unsigned int unbr)
{
	int	i;

	i = 0;
	if (unbr >= 10)
		i += ft_printnbr(unbr / 10);
	else
		i += ft_printchar(unbr % 10 + '0');
	return (i);
}

int	ft_printhex(unsigned int hex, const char format)
{
	if (hex == 0)
		return (ft_printchar('0'));
	if (format == 'x')
		return (ft_printhexbase(hex, "0123456789abcdef"));
	else if (format == 'X')
		return (ft_printhexbase(hex, "0123456789ABCDEF"));
	else
		return (0);
}
