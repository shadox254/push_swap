#include "../include/push_swap.h"

int	cost_to_top(int index, int size)
{
	int	median;
	int res;

	median = size / 2;
	if (index <= median)
		return (index);
	else
	{
		res = size - index;
		return (res);
	}
}

void get_cost_a(t_data *data)
{
	t_stack	*current;
	int		size;

	size = ft_double_lstsize(data->stack_a);
	current = data->stack_a;
	while (current != NULL)
	{
		current->push_cost = cost_to_top(current->index, size);
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
		current->push_cost = cost_to_top(current->index, size);
		current = current->next;
	}
}

void push_cost(t_data *data, t_stack *cheappest)
{
	if (cheappest->above_median && cheappest->target->above_median)
	{
		while (cheappest->index != 0 && cheappest->target->index != 0)
			rr(data);
	}
	else if (!cheappest->above_median && !cheappest->target->above_median)
	{
		while (cheappest->index != 0 && cheappest->target->index != 0)
			rrr(data);
	}
	while (cheappest->index != 0)
	{
		if (cheappest->above_median)
			ra(data);
		else
			rra(data);
	}
	while (cheappest->target->index != 0)
	{
		if (cheappest->target->above_median)
			rb(data);
		else
			rrb(data);
	}
}
