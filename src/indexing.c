/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:33:18 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/10 17:25:38 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	index_zero(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		current->index = 0;
		current = current->next;
	}
}

static void	indexing_a(t_stack *stack)
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

static void	indexing_b(t_stack *stack)
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

void	indexing(t_data *data)
{
	if (data->stack_a != NULL)
		indexing_a(data->stack_a);
	if (data->stack_b != NULL)
		indexing_b(data->stack_b);
}
