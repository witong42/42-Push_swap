/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:42:39 by witong            #+#    #+#             */
/*   Updated: 2024/05/21 21:22:23 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;
	unsigned char *ucs;

	ucs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ucs[i] == (unsigned char)c)
			return ((void *)&ucs[i]);
		i++;
	}
	return (NULL);
}
