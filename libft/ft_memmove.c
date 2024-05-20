/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:47:22 by witong            #+#    #+#             */
/*   Updated: 2024/05/20 21:23:59 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp_dst;
	unsigned char *tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;

	if (tmp_dst > tmp_src)
	{
		while (len > 0)
		{
			len--;
			tmp_dst[len] = tmp_src[len];
		}
	}
	else
		while (len > 0)
		{
			*tmp_dst++ = *tmp_src++;
			len--;
		}
	return (dst);
}
