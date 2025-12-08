#include "include/push_swap.h"

int main(int ac, char **av)
{
	t_data data;

	data.stack_a = NULL;
    data.stack_b = NULL;
	if (ac < 2)
		return(error(data));
	data.stack_a = NULL;
	if (create_data(&(data.stack_a), ac, av) == 0)
		return(error(data));
	if (check_dup_num(&(data.stack_a)) == 0)
		return(error(data));
	if (check_order(&(data.stack_a)) == 1)
	{
		clear_data(&data);
		return(0);
	}
	indexing(&data);
	push_swap(&data);
	print_stack_a(data.stack_a);
	print_stack_b(data.stack_b);
	// clear_data(&data);
	return (0);
}
