/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:27:26 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 12:11:26 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static t_stack	*low(t_stack *stack)
// {
// 	t_stack	*current;
// 	t_stack	*low;

// 	current = stack;
// 	low = stack;
// 	while (current != NULL)
// 	{
// 		if (low->value > current->value)
// 			low = current;
// 		current = current->next;
// 	}
// 	return (low);
// }

static void	init_all(t_data *data)
{
	indexing(data);
	set_current_position(data->stack_a);
    set_current_position(data->stack_b);
	get_target_a(data);
	get_target_b(data);
	total_cost_a(data);
	total_cost_b(data);
	init_cheappest(data->stack_a);
	init_cheappest(data->stack_b);
}

void	sort_stack(t_data *data)
{
	t_stack	*current_cheapest;
	int		size;

	pb(data);
	pb(data);
	size = ft_double_lstsize(data->stack_a);
	while (size > 3)
	{
		init_all(data);
		current_cheapest = get_cheappest(data->stack_a);
		push_cost_a(data, current_cheapest);
		pb(data);
		size--;
	}
	sort_three(data);
	size = ft_double_lstsize(data->stack_b);
	while (size > 0)
	{
		init_all(data);
		current_cheapest = get_cheappest(data->stack_b);
		push_cost_b(data, current_cheapest);
		pa(data);
		size--;
	}
}
