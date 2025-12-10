/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:35:23 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/10 18:19:22 by rruiz            ###   ########.fr       */
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

void	init_median(t_data *data)
{
	int		size_a;
	int		size_b;
	t_stack	*current;

	size_a = ft_double_lstsize(data->stack_a);
	current = data->stack_a;
	while (current != NULL)
	{
		if (current->index < size_a/2)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
	}
	size_b = ft_double_lstsize(data->stack_b);
	current = data->stack_b;
	while (current != NULL)
	{
		if (current->index < size_b/2)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
	}
}

void	get_cheappest(t_stack *stack)
{
	(void) stack;
}
