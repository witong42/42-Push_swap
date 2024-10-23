/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:00:01 by witong            #+#    #+#             */
/*   Updated: 2024/10/23 08:59:29 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if a string contains digits with optional sign.
static int	is_valid_number(const char *str)
{
	if (!*str)
		return (0);
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

// Function to check for duplicate numbers in the stack.
static int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

// Parses and validates cmd arguments, then put them into a stack.
static int	process_args(t_stack **stack, const char *arg)
{
	char	**split_args;
	long	nb;
	int		i;
	t_stack	*new_node;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (0);
	i = 0;
	while (split_args[i])
	{
		if (!is_valid_number(split_args[i]))
			handle_error(split_args, stack, NULL);
		nb = ft_atol(split_args[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			handle_error(split_args, stack, NULL);
		new_node = ft_lstd_new((int)nb);
		if (!new_node)
			handle_error(split_args, stack, NULL);
		ft_lstd_add_back(stack, new_node);
		i++;
	}
	return (free_args(split_args), 1);
}

// Finish the parsing and validation process and check for duplicates.
t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		if (!process_args(&stack, av[i]))
			handle_error(NULL, &stack, NULL);
		i++;
	}
	if (has_duplicates(stack))
		handle_error(NULL, &stack, NULL);
	return (stack);
}
