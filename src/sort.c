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

void sort_five(t_data *data)
{
	int	min_index;

	while (ft_double_lstsize(data->stack_a) > 3)
	{
		min_index = get_min_index(data->stack_a);
		to_top(data, min_index);
		pb(data);
	}
	sort_3(data);
	pa(data);
	pa(data);
}

void	to_top(t_data *data, int index)
{
	int	size;

	size = ft_double_lstsize(data->stack_a);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(data);
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			rra(data);
			index++;
		}
	}
}