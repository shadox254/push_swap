/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:35:23 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/09 17:44:56 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

long get_lowest(t_data *data)
{
	long	res;
	t_stack	*tmp;

	tmp = data->stack_a;
	res = tmp->value;
	while (tmp != NULL)
	{
		if (res > tmp->value)
			res = tmp->value;
		tmp = tmp->next;
	}
	return (res);
}

long get_highest(t_data *data)
{
	long	res;
	t_stack	*tmp;

	tmp = data->stack_a;
	res = tmp->value;
	while (tmp != NULL)
	{
		if (res < tmp->value)
			res = tmp->value;
		tmp = tmp->next;
	}
	return (res);
}
