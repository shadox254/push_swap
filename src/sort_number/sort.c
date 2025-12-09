/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:34:31 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/09 12:02:34 by rruiz            ###   ########.fr       */
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
	t_data *tmp;

	tmp = data;
	if (tmp->stack_a->next->index > tmp->stack_a->index && 
			tmp->stack_a->next->index > tmp->stack_a->next->next->index)
		sa(tmp);
	if (tmp->stack_a->index > tmp->stack_a->next->index && 
			tmp->stack_a->index > tmp->stack_a->next->next->index)
		ra(tmp);
	if (tmp->stack_a->index > tmp->stack_a->next->index)
		sa(tmp);
	data = tmp;
}

void	sort_four(t_data *data)
{
	int		lowest;

	lowest = get_lowest(data);
	while (data->stack_a->value != lowest)
		ra(data);
	pb(data);
	sort_three(data);
	pa(data);
}
