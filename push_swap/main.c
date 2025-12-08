#include "include/push_swap.h"

int main(int ac, char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->stack_a = NULL;
    data->stack_b = NULL;
	if (ac < 2)
		return(error(data));
	data->stack_a = NULL;
	if (create_data(&(data->stack_a), ac, av) == 0)
		return(error(data));
	if (check_dup_num(&(data->stack_a)) == 0)
		return(error(data));
	if (check_order(&(data->stack_a)) == 1)
	{
		clear_data(data);
		free(data);
		return(0);
	}
	push_swap(&data);
	clear_data(data);
	free(data);
	return (0);
}
