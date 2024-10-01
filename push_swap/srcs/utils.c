/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:13:16 by witong            #+#    #+#             */
/*   Updated: 2024/10/01 09:44:57 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// need split and atoi
t_stack	atolist(char *str)
{
	t_stack	*head;
	char	*start;
	char	*end;
	int		value;

	head = NULL;
	start = str;
	while (*start)
	{
		while (*start == ' ')
			start++;
		if (*start == '\0')
			break ;
		end = start;
		while (*end && *end != ' ')
			end++;
		value = atoi(start);
		add_node(&head, value);
		start = end;
	}
	return (head);
}
