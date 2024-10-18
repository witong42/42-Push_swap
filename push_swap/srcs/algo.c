#include "push_swap.h"

void	small_sort(t_stack **a)
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

static void	ft_sort_b(t_stack **a, t_stack **b)
{
	int	stack_size;
	int	i;

	i = 0;
	stack_size = ft_lstd_size(a);
	while (i < stack_size / 2)
	{
		if ((*a)->value <= (stack_size / 2))
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	while (stack_size - i > 3)
	{
		pb(a, b);
		i++;
	}
}

static void align_stack(t_stack **a)
{
	(void)a;
}

void	algo_sort(t_stack **a, t_stack **b)
{
	int cost_b;

	ft_sort_b(a, b);
	small_sort(a);
	while (*b)
    {
        cost_b = calculate_best_cost(*b, *a);
        rotate_and_push(a, b, cost_b);
    }
	if (!is_sorted(*a))
    	align_stack(a);
}
