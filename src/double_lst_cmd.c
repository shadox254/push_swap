/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lst_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:32:01 by rruiz             #+#    #+#             */
/*   Updated: 2025/12/10 16:10:17 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_clear_double_lst(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

t_stack	*ft_double_lst_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->above_median = 0;
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->previous = NULL;
	node->target = NULL;
	node->push_cost = 0;
	return (node);
}

void	ft_double_lst_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
}

void	ft_double_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	if (*lst != NULL)
		(*lst)->previous = new;
	new->previous = NULL;
	*lst = new;
}

int	ft_double_lstsize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
