/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:27:26 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/09 16:31:21 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stack(t_data *data)
{
	int	size;

	pb(data);
	pb(data);
	size = 0;
	size = ft_double_lstsize(data->stack_a);
	get_target_b(data);
	(void) size;
	// while (size > 3)
	// {
	// 	get_target_b(data);
	// 	pb(data);
	// 	size--;
	// }
	// sort_three(data);
}
