/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:34:01 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 15:34:42 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_cost_a(t_data *data, t_stack *c_node)
{
	if (c_node->above_median && c_node->target->above_median)
	{
		while (data->stack_a != c_node && data->stack_b != c_node->target)
			rr(data);
	}
	else if (!c_node->above_median && !c_node->target->above_median)
	{
		while (data->stack_a != c_node && data->stack_b != c_node->target)
			rrr(data);
	}
	while (data->stack_a != c_node)
	{
		if (c_node->above_median)
			ra(data);
		else
			rra(data);
	}
	while (data->stack_b != c_node->target)
	{
		if (c_node->target->above_median)
			rb(data);
		else
			rrb(data);
	}
}

static void	exact_cost(t_stack *t, int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;

	if (t->above_median)
		cost_a = t->pos;
	else
		cost_a = len_a - t->pos;
	if (t->target->above_median)
		cost_b = t->target->pos;
	else
		cost_b = len_b - t->target->pos;
	if (cost_a > cost_b)
		t->push_cost = cost_a;
	else
		t->push_cost = cost_b;
}

void	total_cost_a(t_data *data)
{
	t_stack	*t;
	int		len_a;
	int		len_b;

	len_a = ft_double_lstsize(data->stack_a);
	len_b = ft_double_lstsize(data->stack_b);
	t = data->stack_a;
	while (t)
	{
		t->push_cost = t->pos;
		if (!t->above_median)
			t->push_cost = len_a - t->pos;
		if (t->target->above_median)
			t->push_cost += t->target->pos;
		else
			t->push_cost += len_b - t->target->pos;
		if (t->above_median == t->target->above_median)
			exact_cost(t, len_a, len_b);
		t = t->next;
	}
}
