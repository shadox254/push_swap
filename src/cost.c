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
	printf("size_stack: %d\nmedian: %d\nnb: %d\n", size_stack, median, nb);
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