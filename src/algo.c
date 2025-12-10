/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:27:26 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/10 18:00:37 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stack(t_data *data)
{
	int	size;

	pb(data);
	pb(data);
	indexing(data);
	init_median(data);
	size = 0;
	size = ft_double_lstsize(data->stack_a);
	get_target_b(data);
	get_cost_a(data);
	get_cost_b(data);
	get_cheappest(data->stack_a);
	print_stack_a(data->stack_a);
	print_stack_b(data->stack_b);
	ft_printf_fd(1, "\n===================================================================\n");
	push_cost(data, data->stack_a->cheappest);
	print_stack_a(data->stack_a);
	print_stack_b(data->stack_b);
	ft_printf_fd(1, "\n===================================================================\n");
	get_cost_a(data);
	get_cost_b(data);
	(void) size;
}
