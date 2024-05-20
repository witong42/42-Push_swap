/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:37:11 by witong            #+#    #+#             */
/*   Updated: 2024/04/16 19:58:38 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_len] && (dst_len + src_len + 1) < dstsize)
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	if (dst_len + src_len < dstsize)
		dst[dst_len + src_len] = '\0';
	while (src[src_len])
		src_len++;
	return (dst_len + src_len);
}
