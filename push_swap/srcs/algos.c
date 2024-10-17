#include "push_swap.h"

/*
static int	find_smallest(t_stack **stack)
{
	int	min;

	if ((*stack)->value < (*stack)->next->value)
		min = (*stack)->value;
	else
		min = (*stack)->next->value;
	if (min > (*stack)->next->next->value)
		min = (*stack)->next->next->value;
	return (min);
}
*/
void	small_sort(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value
			|| (*stack)->next->value < (*stack)->next->next->value)
		ra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
	if ((*stack)->next->value > (*stack)->next->next->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	algo_sort(t_stack **a, t_stack **b)
{
	int	stack_size;

	stack_size = ft_lstd_size(*a);
	while (stack_size-- > a && !is_sorted(*a))
		pb(b, a);
	small_sort(a);
	while (*b)
		pa(a, b);
}

/*
    Find the smallest number in Stack A.-
    Move the smallest number found to the top of Stack A.
    Push that number to Stack B.
    Repeat steps 1–3 until Stack A is empty.
    Push everything back to stack A once Stack B has all the numbers from biggest to smallest.
*/
