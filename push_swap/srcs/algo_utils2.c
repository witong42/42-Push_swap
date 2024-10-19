/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:24:33 by witong            #+#    #+#             */
/*   Updated: 2024/10/19 17:01:05 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push_to_b(t_stack **a, t_stack **b)
{
	int stack_size;
    int i;

    i = 0;
    stack_size = ft_lstd_size(*a);
    while (stack_size - i > 3)
    {
        if ((*a)->value < find_nearest(a))
			pb(a, b);
		else
			ra(a);
		stack_size = ft_lstd_size(*a);
    }
}
void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack *best_move;

	while (*b)
	{
		best_move = find_best_move(*a, *b);
		perform_best_move(a, b, best_move);
		pa(b, a);
	}
}
int	target(t_stack *a, t_stack *b)
{
	while (a)
	{
		
	}
}
