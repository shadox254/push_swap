#include "../include/push_swap.h"

static int	cost_to_top(t_stack *stack, int size_stack)
{
	int	median;
	int	nb;

	median = size_stack/2;
	nb = 0;
	if (stack->index > median)
	{
		while (stack->index + nb < size_stack)
			nb++;
		if (stack->index + nb == size_stack)
			nb++;
	}
	else
	{
		while (stack->index - nb != 0)
			nb++;
	}
	return (nb);
}

void get_cost_a(t_data *data)
{
	t_stack	*current;
	int		size;

	size = ft_double_lstsize(data->stack_a);
	current = data->stack_a;
	while (current != NULL)
	{
		current->push_cost = cost_to_top(current, size);
		current = current->next;
	}
}

void get_cost_b(t_data *data)
{
	t_stack	*current;
	int		size;

	size = ft_double_lstsize(data->stack_b);
	current = data->stack_b;
	while (current != NULL)
	{
		current->push_cost = cost_to_top(current, size);
		current = current->next;
	}
}

void push_cost(t_data *data)
{
	if (data->stack_a->above_median == 1 && data->stack_b->above_median == 1)
	{
		while (data->stack_a->push_cost != 0 || data->stack_b->push_cost != 0)
			rrr(data);
		if (data->stack_a->push_cost != 0)
			rra(data);
		if (data->stack_b->push_cost != 0)
			rrb(data);
	}
	else if (data->stack_a->above_median == 0 && data->stack_b->above_median == 0)
	{
		while (data->stack_a->push_cost != 0 || data->stack_b->push_cost != 0)
			rr(data);
		if (data->stack_a->push_cost != 0)
			ra(data);
		if (data->stack_b->push_cost != 0)
			rb(data);
	}
}
