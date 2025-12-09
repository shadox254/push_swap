#include "../include/push_swap.h"

void sort_two(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
}

void sort_three(t_data *data)
{
	if (data->stack_a->next->index == 2)
		sa(data);
	if (data->stack_a->index == 2)
		ra(data);
	if (data->stack_a->index > data->stack_a->next->index)
		sa(data);
}

static int	get_pos(t_stack *stack, int value)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static int	get_target(t_stack *a, int val_to_push)
{
	t_stack	*tmp;
	int		target;
	int		min;

	tmp = a;
	target = 2147483647;
	min = 2147483647;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		if (tmp->index > val_to_push && tmp->index < target)
			target = tmp->index;
		tmp = tmp->next;
	}
	if (target == 2147483647)
		return (min);
	return (target);
}

static void	bring_to_top(t_data *data, int target_val)
{
	int		pos;
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = data->stack_a;
	while (tmp && ++size)
		tmp = tmp->next;
	pos = get_pos(data->stack_a, target_val);
	if (pos <= size / 2)
	{
		while (data->stack_a->index != target_val)
			ra(data);
	}
	else
	{
		while (data->stack_a->index != target_val)
			rra(data);
	}
}

void	sort_five(t_data *data)
{
	pb(data);
	pb(data);
	sort_three(data);
	while (data->stack_b)
	{
		bring_to_top(data, get_target(data->stack_a, data->stack_b->index));
		pa(data);
	}
	bring_to_top(data, 0);
}
