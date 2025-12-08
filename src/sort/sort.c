#include "../../include/push_swap.h"

void sort_two(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data->stack_a);
}