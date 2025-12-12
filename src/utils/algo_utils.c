/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:11:17 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 15:33:48 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_max(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	max = -2147483649;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*get_min(t_stack *stack)
{
	long	max;
	t_stack	*min_node;

	max = LONG_MAX;
	while (stack)
	{
		if (stack->value < max)
		{
			max = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	set_current_position(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = ft_double_lstsize(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}
