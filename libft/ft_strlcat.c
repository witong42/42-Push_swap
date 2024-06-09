/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:37:11 by witong            #+#    #+#             */
/*   Updated: 2024/06/09 20:19:47 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	if (size == 0)
		return (0);
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len] && (dest_len + src_len + 1) < size)
	{
		dest[dest_len + src_len] = src[src_len];
		src_len++;
	}
	if (dest_len + src_len < size)
		dest[dest_len + src_len] = '\0';
	while (src[src_len])
		src_len++;
	return (dest_len + src_len);
}
