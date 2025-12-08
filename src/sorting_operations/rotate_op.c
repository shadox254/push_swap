/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:29:11 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/06 10:29:12 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = tmp;
	tmp->previous = tail;
	tmp->next = NULL;
}

void	ra(t_data *data)
{
	rotate(&(data->stack_a));
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	rotate(&(data->stack_b));
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	rotate(&(data->stack_a));
	rotate(&(data->stack_b));
	write(1, "rr\n", 3);
}
