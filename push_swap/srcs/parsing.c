/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:00:01 by witong            #+#    #+#             */
/*   Updated: 2024/10/17 06:02:20 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to check if a string contains only digits and an optional leading sign
static int is_valid_number(const char *str)
{
    if (!*str)
        return (0);
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

// Function to check for duplicate numbers in the stack
static int has_duplicates(t_stack *stack)
{
    t_node *current;
    t_node *checker;

    current = stack->head;
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

// Function to handle parsing arguments and initializing the stack
// Returns the initialized stack or NULL if an error occurs
t_stack *parse_args(int argc, char **argv)
{
    t_stack *stack;
    int i;

    i = 1;
    while (i < argc)
    {
        if (!validate_args(stack, argv[i]))
        {
            free_stack(stack);
            return (NULL);
        }
        i++;
    }
    if (has_duplicates(stack))
    {
        free_stack(stack);
        return (NULL);
    }
    return (stack);
}


