/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:25:44 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/12 15:32:40 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	put_in_stack(t_stack **stack, char **args, int j)
{
	long	n;

	n = ft_atol(args[j]);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	ft_double_lst_add_back(stack, ft_double_lst_new(n));
	return (1);
}

int	create_data(t_stack **stack, int ac, char **av)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			return (0);
		j = -1;
		while (args[++j])
		{
			if (check_only_num(args[j]) == 0)
				return (ft_free_tab(args), 0);
			if (put_in_stack(stack, args, j) == 0)
				return (0);
		}
		ft_free_tab(args);
		i++;
	}
	return (1);
}
