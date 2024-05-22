/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:42:34 by witong            #+#    #+#             */
/*   Updated: 2024/05/22 22:13:52 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(size * count);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while(i < size * count)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
