/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:28:55 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/06 10:28:58 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tail = *stack;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->previous->next = NULL;
	tail->next = *stack;
	tail->previous = NULL;
	(*stack)->previous = tail;
	*stack = tail;
}

void	rra(t_data *data)
{
	reverse_rotate(&(data->stack_a));
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	reverse_rotate(&(data->stack_b));
	write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	reverse_rotate(&(data->stack_a));
	reverse_rotate(&(data->stack_b));
	write(1, "rrr\n", 4);
}
