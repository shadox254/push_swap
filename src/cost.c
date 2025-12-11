#include "../include/push_swap.h"

static int	cost_to_top(int pos, int size)
{
	int	median;
	int res;

	median = size / 2;
	if (pos <= median)
		return (pos);
	else
	{
		res = size - pos;
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
		current->push_cost = cost_to_top(current->pos, size);
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

void	push_cost(t_data *data, t_stack *cheappest)
{
	if (cheappest->above_median && cheappest->target->above_median)
	{
		while (data->stack_a != cheappest && data->stack_b != cheappest->target)
			rr(data);
	}
	else if (!cheappest->above_median && !cheappest->target->above_median)
	{
		while (data->stack_a != cheappest && data->stack_b != cheappest->target)
			rrr(data);
	}
	while (data->stack_a != cheappest)
	{
		if (cheappest->above_median)
			ra(data);
		else
			rra(data);
	}
	while (data->stack_b != cheappest->target)
	{
		if (cheappest->target->above_median)
			rb(data);
		else
			rrb(data);
	}
}

void total_cost(t_stack *stack_a, t_stack *stack_b)
{
	int len_a = ft_double_lstsize(stack_a);
	int len_b = ft_double_lstsize(stack_b);

	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - stack_a->index;
		if (stack_a->target->above_median)
			stack_a->target->push_cost = stack_a->target->index;
		else
			stack_a->target->push_cost = len_b - stack_a->target->index;
		if (stack_a->above_median == stack_a->target->above_median)
		{
			if (stack_a->push_cost > stack_a->target->push_cost)
				stack_a->push_cost = stack_a->push_cost;
			else
				stack_a->push_cost = stack_a->target->push_cost;
		}
		else
			stack_a->push_cost = stack_a->push_cost + stack_a->target->push_cost;
			
		stack_a = stack_a->next;
	}
}
