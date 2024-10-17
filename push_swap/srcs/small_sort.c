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
