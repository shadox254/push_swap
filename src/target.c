#include "../include/push_swap.h"

static t_stack	*get_max(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

static t_stack	*find_target(t_stack *stack, long val_a)
{
	t_stack	*target_node;
	t_stack	*current;
	long	best_target;

	target_node = NULL;
	current = stack;
	best_target = LONG_MIN;
	while (current)
	{
		if (current->value < val_a && current->value > best_target)
		{
			best_target = current->value;
			target_node = current;
		}
		current = current->next;
	}
	if (!target_node)
		return (get_max(stack));
	return (target_node);
}

void	get_target_a(t_data *data)
{
	t_stack	*curr_a;

	curr_a = data->stack_a;
	while (curr_a)
	{
		curr_a->target = find_target(data->stack_b, curr_a->value);
		curr_a = curr_a->next;
	}
}

void	get_target_b(t_data *data)
{
	t_stack	*curr_a;

	curr_a = data->stack_b;
	while (curr_a)
	{
		curr_a->target = find_target(data->stack_a, curr_a->value);
		curr_a = curr_a->next;
	}
}
