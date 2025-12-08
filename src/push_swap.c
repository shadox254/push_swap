#include "../include/push_swap.h"

void push_swap(t_data *data)
{
	if (ft_double_lstsize(data->stack_a) == 2)
		sort_two(data);
	else if (ft_double_lstsize(data->stack_a) == 3)
		sort_three(data);
	else if (ft_double_lstsize(data->stack_a) == 4)
		sort_for(data);
	else if (ft_double_lstsize(data->stack_a) == 5)
		sort_five(data);
	// else
}