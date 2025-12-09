/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:26:24 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/09 12:32:18 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_order(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_num(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current != NULL)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (0);
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}

int	check_only_num(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
