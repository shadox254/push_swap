/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:27:57 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/10 16:35:46 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack_a(t_stack *a)
{
	t_stack	*tmp;

	ft_printf_fd(1, "--- STACK A ---\n");
	if (!a)
		ft_printf_fd(1, "(vide)\n");
	else
	{
		tmp = a;
		while (tmp)
		{
			ft_printf_fd(1, "Val: %d | Idx: %d | Adr: %p | Prev: %p | Nxt: %p",
				tmp->value, tmp->index, (void*)tmp, (void*)tmp->previous,
				(void*)tmp->next);
			ft_printf_fd(1, "| Trg: %p | Cst: %d | Mdn: %d", tmp->target,
				tmp->push_cost, tmp->above_median);
			ft_printf_fd(1, "\n");
			tmp = tmp->next;
		}
	}
	ft_printf_fd(1, "============================\n\n");
}

void	print_stack_b(t_stack *b)
{
	t_stack	*tmp;

	ft_printf_fd(1, "\n--- STACK B ---\n");
	if (!b)
		ft_printf_fd(1, "(vide)\n");
	else
	{
		tmp = b;
		while (tmp)
		{
			ft_printf_fd(1, "Val: %d | Idx: %d | Adr: %p | Prev: %p | Nxt: %p ",
				tmp->value, tmp->index, (void*)tmp, (void*)tmp->previous,
				(void*)tmp->next);
			ft_printf_fd(1, "| Trg: %p | Cst: %d | Mdn: %d", tmp->target,
				tmp->push_cost, tmp->above_median);
			ft_printf_fd(1, "\n");
			tmp = tmp->next;
		}
	}
	ft_printf_fd(1, "============================\n\n");
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
