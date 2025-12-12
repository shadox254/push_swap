#include "../include/push_swap.h"

static t_stack *get_max(t_stack *stack)
{
    long    max;
    t_stack *max_node;

    max = -2147483649;
    while (stack)
    {
        if (stack->value > max)
        {
            max = stack->value;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}

static t_stack	*find_target(t_stack *stack, long val_a)
{
	t_stack	*target;
	long	best_match_val;

	target = NULL;
	best_match_val = -2147483649;
	while (stack)
	{
		if (stack->value < val_a && stack->value > best_match_val)
		{
			best_match_val = stack->value;
			target = stack;
		}
		stack = stack->next;
	}
	return (target);
}

void	get_target_a(t_data *data)
{
	t_stack	*current;
	t_stack	*target_node;

	current = data->stack_a;
	while (current)
	{
		target_node = find_target(data->stack_b, current->value);
		if (target_node != NULL)
			current->target = target_node;
		else
			current->target = get_max(data->stack_b);
		current = current->next;
	}
}

void	get_target_b(t_data *data)
{
	t_stack	*current;
	t_stack	*target_node;

	current = data->stack_b;
	while (current)
	{
		target_node = find_target(data->stack_a, current->value);
		if (target_node != NULL)
			current->target = target_node;
		else
			current->target = get_max(data->stack_a);
		current = current->next;
	}
}
