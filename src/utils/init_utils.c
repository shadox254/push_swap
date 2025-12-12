/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:38:58 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 15:39:30 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get_cheappest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheappest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

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

void	init_cheappest(t_stack *stack)
{
	t_stack		*current;
	t_stack		*cheappest_node;
	long		cheap;

	current = stack;
	cheap = LONG_MAX;
	while (current != NULL)
	{
		if (current->push_cost < cheap)
		{
			cheap = current->push_cost;
			cheappest_node = current;
		}
		current = current->next;
	}
	if (cheappest_node)
		cheappest_node->cheappest = 1;
}
