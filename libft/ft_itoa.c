/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:20:32 by witong            #+#    #+#             */
/*   Updated: 2024/05/29 23:22:52 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	array[len] = '\0';
	if (n < 0)
	{
		array[0] = '-';
		n = -n;
	}
	while (--len >= 0)
	{
		array[len] = n % 10 + 48;
		n = n / 10;
	}
	return (array);
}
