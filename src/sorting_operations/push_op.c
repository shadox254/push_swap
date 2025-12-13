/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:28:45 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/13 10:38:24 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	node_to_push->previous = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		(*dest)->previous = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_data *data)
{
	push(&data->stack_b, &data->stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	push(&data->stack_a, &data->stack_b);
	write(1, "pb\n", 3);
}
