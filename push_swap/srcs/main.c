/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:51:34 by witong            #+#    #+#             */
/*   Updated: 2024/10/18 07:35:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return 1 if stack is already sorted.
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	assign_index(t_stack *a)
{
	t_stack	*current;
	int		index;

	current = a;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

// Sorting method based on numbers of value to be sorted
void	sort_stack(t_stack *a, t_stack *b)
{
	int stack_size;

	(void)b;
	stack_size = ft_lstd_size(a);
	if (stack_size == 2)
		sa(&a);
	else if (stack_size == 3)
		small_sort(&a);
	else
		algo_sort(&a, &b);
}

// Check args, init a and b, call the sorting function, free and exit.
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	b = NULL;
	a = init_stack(ac, av);
	if (!a)
		handle_error(NULL, &a, NULL);
	assign_index(a);
	if (!is_sorted(a))
		sort_stack(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
// cc -Wall -Werror -Wextra main.c parsing.c utils.c lstd.c push.c reverse.c rotate.c swap.c -L../libft -lft
