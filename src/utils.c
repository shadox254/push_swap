/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:35:23 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/09 17:44:56 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_pos(t_stack *stack, int value)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

long get_lowest(t_data *data)
{
	long	res;
	t_stack	*tmp;

	tmp = data->stack_a;
	res = tmp->value;
	while (tmp != NULL)
	{
		if (res > tmp->value)
			res = tmp->value;
		tmp = tmp->next;
	}
	return (res);
}

long get_highest(t_data *data)
{
	long	res;
	t_stack	*tmp;

	tmp = data->stack_a;
	res = tmp->value;
	while (tmp != NULL)
	{
		if (res < tmp->value)
			res = tmp->value;
		tmp = tmp->next;
	}
	return (res);
}

static t_stack	*get_max(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	get_target_b(t_data *data)
{
	t_stack	*curr_a;
	t_stack	*curr_b;
	t_stack	*target_node;
	long	best_match_val;

	curr_a = data->stack_a;
	while (curr_a != NULL)
	{
		best_match_val = -2147483649;
		target_node = NULL;
		curr_b = data->stack_b;
		while (curr_b != NULL)
		{
			if (curr_b->value < curr_a->value && curr_b->value > best_match_val)
			{
				best_match_val = curr_b->value;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (!target_node)
			curr_a->target = get_max(data->stack_b);
		else
			curr_a->target = target_node;
		curr_a = curr_a->next;
	}
}
