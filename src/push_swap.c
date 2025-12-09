/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:33:44 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/09 15:54:14 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_data *data)
{
	if (ft_double_lstsize(data->stack_a) == 2)
		sort_two(data);
	else if (ft_double_lstsize(data->stack_a) == 3)
		sort_three(data);
	else if (ft_double_lstsize(data->stack_a) == 4)
		sort_four(data);
	else if (ft_double_lstsize(data->stack_a) == 5)
		sort_five(data);
	else
	{
		sort_stack(data);
	}
}
