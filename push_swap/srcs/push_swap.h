/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:52:12 by witong            #+#    #+#             */
/*   Updated: 2024/10/20 07:59:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	bool			above_mid;
	bool			best_move;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

// swap.c
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// push.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// rotate.c
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse.c
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// lstd.c
t_stack	*ft_lstd_new(int value);
t_stack	*ft_lstd_first(t_stack *lst);
t_stack	*ft_lstd_last(t_stack *lst);
int		ft_lstd_size(t_stack *lst);
void	ft_lstd_add_front(t_stack **lst, t_stack *front);
void	ft_lstd_add_back(t_stack **lst, t_stack *back);

// parsing.c
t_stack	*init_stack(int ac, char **av);

// utils.c
void	print_stack(t_stack *lst);
void	free_stack(t_stack **stack);
void	free_args(char **args);
void	handle_error(char **args, t_stack **a, t_stack **b);
long	ft_atol(const char *str);

// main.c
int		is_sorted(t_stack *stack);

// algo.c
void	sort_three(t_stack **a);
void	set_target(t_stack *a, t_stack *b);
void	push_to_b(t_stack **a, t_stack **b);
void	algo_sort(t_stack **a, t_stack **b);

// algo_utils.c
t_stack	*find_smallest_node(t_stack *stack);
t_stack	*find_largest_node(t_stack *stack);
int		find_nearest(int value, t_stack *stack);
t_stack	*find_best_move(t_stack *stack);

//algo_utils2.c
void	set_current_index(t_stack *stack);
void	set_cost(t_stack *a, t_stack *b);
void	set_best_move(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);

// algo_utils3.c
void	rotate_both(t_stack **a, t_stack **b, t_stack *best_move);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *best_move);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	smallest_to_top(t_stack **a);

#endif
