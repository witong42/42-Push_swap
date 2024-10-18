#include "push_swap.h"

static int	find_smallest(t_stack *a)
{
	int		min;
	t_stack	*current;

	current = a;
	min = current->value;
	while (current != NULL)
	{
		if (min > current->value)
			min = current->value;
		current = current->next;
	}
	return (min);
}

static int calculate_cost(t_stack *a, t_stack *b)
{
    int cost;
    t_stack *current;

	cost = 0;
	current = a;
    while (current && current->value < b->value)
    {
        cost++;
        current = current->next;
    }
    return (cost);
}

int calculate_best_cost(t_stack *a, t_stack *b)
{
	int min;
    int best;
	int cost;
	t_stack *current;

	min = INT_MAX;
	best = 0;
	current = b;
	while (current)
	{
		cost = calculate_cost(a, current);
		if (cost < min)
		{
			min = cost;
			best = current->value;
		}
		current = current->next;
	}
	return (best);
}

void rotate_and_push(t_stack **a, t_stack **b, int cost_b)
{

}
