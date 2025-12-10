/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:36:43 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/10 17:55:18 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	if (ac < 2)
		return (error(data));
	data.stack_a = NULL;
	if (create_data(&(data.stack_a), ac, av) == 0)
		return (error(data));
	if (check_num(data.stack_a) == 0)
		return (error(data));
	if (check_order(data.stack_a) == 1)
	{
		clear_data(&data);
		return (0);
	}
	indexing(&data);
	push_swap(&data);
	// print_stack_a(data.stack_a);
	// print_stack_b(data.stack_b);
	clear_data(&data);
	return (0);
}
