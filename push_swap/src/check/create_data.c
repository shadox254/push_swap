#include "../../include/push_swap.h"

int create_data(t_stack **stack, int ac, char **av)
{
	int     i;
	int     j;
	char    **args;

	i = 1;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		if (!args)
			return (0);
		j = 0;
		while (args[j])
		{
			if (check_only_num(args[j]) == 0)
			{
				ft_free_tab(args);
				return (0);
			}
			ft_double_lst_add_back(stack, ft_double_lst_new(atol(args[j])));
			j++;
		}
		ft_free_tab(args);
		i++;
	}
	return (1);
}
