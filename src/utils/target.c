/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:39:46 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 15:39:47 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*find_low_target(t_stack *stack, long val_a)
{
	t_stack	*target;
	long	best_match_val;

	target = NULL;
	best_match_val = LONG_MIN;
	while (stack)
	{
		if (stack->value < val_a && stack->value > best_match_val)
		{
			best_match_val = stack->value;
			target = stack;
		}
		stack = stack->next;
	}
	return (target);
}

static t_stack	*find_high_target(t_stack *stack, long val_a)
{
	t_stack	*target;
	long	best_match_val;

	target = NULL;
	best_match_val = LONG_MAX;
	while (stack)
	{
		if (stack->value > val_a && stack->value < best_match_val)
		{
			best_match_val = stack->value;
			target = stack;
		}
		stack = stack->next;
	}
	return (target);
}

void	get_target_a(t_data *data)
{
	t_stack	*current;
	t_stack	*target_node;

	current = data->stack_a;
	while (current)
	{
		target_node = find_low_target(data->stack_b, current->value);
		if (target_node != NULL)
			current->target = target_node;
		else
			current->target = get_max(data->stack_b);
		current = current->next;
	}
}

void	get_target_b(t_data *data)
{
	t_stack	*current;
	t_stack	*target_node;

	current = data->stack_b;
	while (current)
	{
		target_node = find_high_target(data->stack_a, current->value);
		if (target_node != NULL)
			current->target = target_node;
		else
			current->target = get_min(data->stack_a);
		current = current->next;
	}
}
