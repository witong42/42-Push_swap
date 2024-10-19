#include "push_swap.h"

void assign_index(t_stack **a, t_stack **b)
{
    t_stack *current;
    int index;

    current = *a;
    index = 0;
    while (current)
    {
        current->index = index;
        current = current->next;
        index++;
    }
    current = *b;
    index = 0;
    while (current)
    {
        current->index = index;
        current = current->next;
        index++;
    }
}

int find_insert_position(t_stack *a, int value)
{
    int position;
    t_stack *current;

    position = 0;
    current = a;
    while (current && current->next)
    {
        if (current->value < value && current->next->value > value)
            break;
        position++;
        current = current->next;
    }
    return position;
}

void align_stack(t_stack **a)
{
    int min_index;
    int rotate;
    t_stack *current;

    min_index = INT_MAX;
    current = *a;
    while (current != NULL)
    {
        if (current->index < min_index)
            min_index = current->index;
        current = current->next;
    }
    rotate = calculate_optimal_rotation(*a, min_index);
    while (rotate > 0 && rotate--)
        ra(a);
    while (rotate < 0 && rotate++)
        rra(a);
}
