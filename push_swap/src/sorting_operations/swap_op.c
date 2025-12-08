/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:29:16 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/06 10:29:17 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	second->previous = NULL;
	first->previous = second;
	*stack = second;
}

void	sa(t_data *data)
{
	swap(&(data->stack_a));
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	swap(&(data->stack_b));
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	swap(&(data->stack_a));
	swap(&(data->stack_b));
	write(1, "ss\n", 3);
}
