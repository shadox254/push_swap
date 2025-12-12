/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:34:31 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 15:31:30 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
}

void	sort_three(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	if (tmp->stack_a->next->index > tmp->stack_a->index
		&& tmp->stack_a->next->index > tmp->stack_a->next->next->index)
		sa(tmp);
	if (tmp->stack_a->index > tmp->stack_a->next->index
		&& tmp->stack_a->index > tmp->stack_a->next->next->index)
		ra(tmp);
	if (tmp->stack_a->index > tmp->stack_a->next->index)
		sa(tmp);
	data = tmp;
}

static	long	get_lowest(t_stack *stack)
{
	long	res;
	t_stack	*tmp;

	tmp = stack;
	res = tmp->value;
	while (tmp != NULL)
	{
		if (res > tmp->value)
			res = tmp->value;
		tmp = tmp->next;
	}
	return (res);
}

void	sort_four(t_data *data)
{
	int		lowest;

	lowest = get_lowest(data->stack_a);
	while (data->stack_a->value != lowest)
		ra(data);
	pb(data);
	sort_three(data);
	pa(data);
}
