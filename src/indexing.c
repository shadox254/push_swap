#include "../include/push_swap.h"

void indexing(t_data *data)
{
	t_stack *current;
	t_stack *cmp;

	current = data->stack_a;
	while(current != NULL)
	{
		cmp = data->stack_a;
		while(cmp != NULL)
		{
			if (current->value > cmp->value)
				current->index += 1;
			cmp = cmp->next;
		}
		current = current->next;
	}
}