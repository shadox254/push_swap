/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:33:18 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/09 09:33:32 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	indexing(t_data *data)
{
	t_stack	*current;
	t_stack	*cmp;

	current = data->stack_a;
	while (current != NULL)
	{
		cmp = data->stack_a;
		while (cmp != NULL)
		{
			if (current->value > cmp->value)
				current->index += 1;
			cmp = cmp->next;
		}
		current = current->next;
	}
}
