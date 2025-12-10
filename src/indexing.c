/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:33:18 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/10 11:08:44 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	indexing(t_stack *stack)
{
	t_stack	*current;
	t_stack	*cmp;

	index_zero(stack);
	current = stack;
	while (current != NULL)
	{
		cmp = stack;
		while (cmp != NULL)
		{
			if (current->value > cmp->value)
				current->index += 1;
			cmp = cmp->next;
		}
		current = current->next;
	}
}

void	index_zero(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		current->index = 0;
		current = current->next;
	}
}
