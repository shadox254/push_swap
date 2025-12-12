/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:27:26 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 15:30:00 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		turk_algorithm_b_to_a(t_data *data);
static t_stack	*lowest_node(t_stack *stack);
static void		init_all(t_data *data);
static void		turk_algorithm_last(t_data *data);

void	sort_stack(t_data *data)
{
	t_stack	*current_cheapest;
	int		size;

	pb(data);
	pb(data);
	size = ft_double_lstsize(data->stack_a);
	while (size > 3)
	{
		init_all(data);
		current_cheapest = get_cheappest(data->stack_a);
		push_cost_a(data, current_cheapest);
		pb(data);
		size--;
	}
	sort_three(data);
	init_all(data);
	turk_algorithm_b_to_a(data);
	turk_algorithm_last(data);
}

static void	init_all(t_data *data)
{
	indexing(data);
	set_current_position(data->stack_a);
	set_current_position(data->stack_b);
	get_target_a(data);
	get_target_b(data);
	total_cost_a(data);
	init_cheappest(data->stack_a);
	init_cheappest(data->stack_b);
}

static void	turk_algorithm_b_to_a(t_data *data)
{
	t_stack	*target_in_a;

	while (data->stack_b != NULL)
	{
		set_current_position(data->stack_a);
		set_current_position(data->stack_b);
		get_target_b(data);
		target_in_a = data->stack_b->target;
		while (data->stack_a != target_in_a)
		{
			if (target_in_a->above_median == 1)
				ra(data);
			else
				rra(data);
		}
		pa(data);
	}
}

static	void	turk_algorithm_last(t_data *data)
{
	t_stack	*min;

	set_current_position(data->stack_a);
	min = lowest_node(data->stack_a);
	while (data->stack_a != min)
	{
		if (min->above_median == 1)
			ra(data);
		else
			rra(data);
	}
}

static t_stack	*lowest_node(t_stack *stack)
{
	t_stack	*current;
	t_stack	*low;

	current = stack;
	low = stack;
	while (current != NULL)
	{
		if (low->value > current->value)
			low = current;
		current = current->next;
	}
	return (low);
}
