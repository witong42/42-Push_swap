/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:42:53 by witong            #+#    #+#             */
/*   Updated: 2024/05/21 21:12:39 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*lc;

	i = 0;
	lc = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			lc = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		lc = (char *)&s[i];
	return (lc);
}
