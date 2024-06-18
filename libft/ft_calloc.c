/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:42:34 by witong            #+#    #+#             */
/*   Updated: 2024/06/18 11:30:49 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count && size && size > (count * size) / count)
		return (NULL);
	tmp = (void *)malloc(count * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
