/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:29:02 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 15:12:40 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	error(t_data data)
{
	ft_printf_fd(2, "Error\n");
	clear_data(&data);
	return (0);
}

void	clear_data(t_data *data)
{
	if (data->stack_a != NULL)
		ft_clear_double_lst(&(data->stack_a));
	if (data->stack_b != NULL)
		ft_clear_double_lst(&(data->stack_b));
}
