/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:51:34 by witong            #+#    #+#             */
/*   Updated: 2024/10/17 12:13:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return 1 if stack is already sorted.
static int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Sorting method based on numbers of value to be sorted
/*static void	sort_stack(t_stack *a, t_stack *b, int stack_size)
{
	if (stack_size == 2)
		sa(&a);
	else if (stack_size == 3)
		small_sort(&a);
	else
		turk(a, b, stack_size);
}
*/

// Check args, init a and b, call the sorting function, free and exit.
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;

	if (ac < 2)
		return (ft_putstr_fd("Error: ./push_swap [numbers...]\n", 2), 1);
	a = init_stack(ac, av);
	if (!a)
		return (ft_putstr_fd("Error: Invalid input\n", 2), 1);
	b = init_stack(ac, av);
	stack_size = ft_lstd_size(a);
	if (!is_sorted(a))
//		sort_stack(a, b, stack_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
// cc -Wall -Werror -Wextra main.c parsing.c utils.c lstd.c -L../libft -lft
