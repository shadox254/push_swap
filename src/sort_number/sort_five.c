#include "../../include/push_swap.h"

static int	get_to_push(t_stack *a, int val_to_push)
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

void	bring_to_top(t_data *data, int target)
{
	int		pos;
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = data->stack_a;
	while (tmp && ++size)
		tmp = tmp->next;
	pos = get_pos(data->stack_a, target);
	if (pos <= size / 2)
	{
		while (data->stack_a->index != target)
			ra(data);
	}
	else
	{
		while (data->stack_a->index != target)
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
		bring_to_top(data, get_to_push(data->stack_a, data->stack_b->index));
		pa(data);
	}
	bring_to_top(data, 0);
}