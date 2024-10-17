/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:52:12 by witong            #+#    #+#             */
/*   Updated: 2024/10/17 13:41:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				index;
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

// algo.c

// simplealgo.c

#endif
