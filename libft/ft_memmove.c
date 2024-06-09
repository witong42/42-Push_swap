/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:47:22 by witong            #+#    #+#             */
/*   Updated: 2024/06/09 20:20:57 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (tmp_dest > tmp_src)
	{
		while (n > 0)
		{
			n--;
			tmp_dest[n] = tmp_src[n];
		}
	}
	else
	{
		while (n > 0)
		{
			*tmp_dest++ = *tmp_src++;
			n--;
		}
	}
	return (dest);
}
