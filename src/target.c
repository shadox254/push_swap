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

static t_stack	*find_best_target(t_stack *stack_b, long val_a)
{
	t_stack	*target_node;
	long	best_match_val;

	target_node = NULL;
	best_match_val = LONG_MIN;
	while (stack_b)
	{
		if (stack_b->value < val_a && stack_b->value > best_match_val)
		{
			best_match_val = stack_b->value;
			target_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	if (!target_node)
		return (get_max(stack_b));
	return (target_node);
}

void	get_target_b(t_data *data)
{
	t_stack	*curr_a;

	curr_a = data->stack_a;
	while (curr_a)
	{
		curr_a->target = find_best_target(data->stack_b, curr_a->value);
		curr_a = curr_a->next;
	}
}