/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:22:22 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/11 16:23:01 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				above_median;
	int				push_cost;
	int				index;
	int				cheappest;
	int				pos;
	long			value;
	struct s_stack	*next;
	struct s_stack	*previous;
	struct s_stack	*target;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

void	indexing(t_data *data);
void	push_swap(t_data *data);
void	sort_stack(t_data *data);

// SORT OPERATIONS
void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

// DEBUG
void	print_stack_a(t_stack *a);
void	print_stack_b(t_stack *b);
void	free_stack(t_stack **stack);

// CHECK
int		check_only_num(char *str);
int		check_order(t_stack *stack);
int		check_num(t_stack *stack);
int		create_data(t_stack **stack, int ac, char **av);

// ERROR HANDLING
int		error(t_data data);
void	clear_data(t_data *data);

// DOUBLE LIST CMD
t_stack	*ft_double_lst_new(int value);
int		ft_double_lstsize(t_stack *stack);
void	ft_clear_double_lst(t_stack **lst);
void	ft_double_lst_add_back(t_stack **lst, t_stack *new);
void	ft_double_lstadd_front(t_stack **lst, t_stack *new);

// SORT
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);
void	bring_to_top(t_data *data, int target);

// OTHER
void	set_pos(t_data *data);
t_stack	*get_cheappest(t_stack *stack);

// UTILS
long	get_lowest(t_data *data);
long	get_highest(t_data *data);
void	init_median(t_data *data);
int		get_pos(t_stack *stack, int value);
void	init_cheappest(t_stack *stack);

// TARGET
void	get_target_a(t_data *data);
void	get_target_b(t_data *data);

// COST
void get_cost_a(t_data *data);
void get_cost_b(t_data *data);
void push_cost(t_data *data, t_stack *cheappest);
void total_cost(t_stack *stack_a, t_stack *stack_b);

#endif
