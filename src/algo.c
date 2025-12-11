/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:27:26 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/11 16:31:17 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stack(t_data *data)
{
	t_stack	*current_cheapest;

	pb(data);
	pb(data);
	indexing(data);
	init_median(data);
	set_pos(data);
	get_target_a(data);
	get_cost_a(data);
	get_cost_b(data);
	init_cheappest(data->stack_a);
	current_cheapest = get_cheappest(data->stack_a);
	print_stack_a(data->stack_a);
	print_stack_b(data->stack_b);
	push_cost(data, current_cheapest);
	print_stack_a(data->stack_a);
	print_stack_b(data->stack_b);
	// total_cost(data->stack_a, data->stack_b);
	// get_cheappest(data->stack_a);
	// push_cost(data, data->stack_a->cheappest);
}
