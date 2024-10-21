/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:51:34 by witong            #+#    #+#             */
/*   Updated: 2024/10/21 16:54:14 by witong           ###   ########.fr       */
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

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		|| (*a)->next->value < (*a)->next->next->value)
		ra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
	if ((*a)->next->value > (*a)->next->next->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

// Sorting method based on numbers of value to be sorted
static void	push_swap(t_stack **a, t_stack **b)
{
	int	stack_size;

	(void)b;
	stack_size = ft_lstd_size(*a);
	if (stack_size == 2)
		sa(a);
	else if (stack_size == 3)
		sort_three(a);
	else
		custom_sort(a, b);
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
	if (!is_sorted(a))
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
