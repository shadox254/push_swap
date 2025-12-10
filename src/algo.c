/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:27:26 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/10 11:35:03 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stack(t_data *data)
{
	int	size;

	// print_stack_a(data->stack_a);
	pb(data);
	pb(data);
	indexing(data->stack_a);
	size = 0;
	size = ft_double_lstsize(data->stack_a);
	get_target_b(data);
	get_cost_a(data);
	// print_stack_a(data->stack_a);
	(void) size;
	// while (size > 3)
	// {
	// 	get_target_b(data);
	// 	pb(data);
	// 	size--;
	// }
	// sort_three(data);
}
