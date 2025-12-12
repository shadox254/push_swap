#include "../include/push_swap.h"

void	set_pos(t_data *data)
{
	t_stack	*current;
	int		i;

	current = data->stack_a;
	i = 0;
	while (current != NULL)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
	current = data->stack_b;
	i = 0;
	while (current != NULL)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

t_stack	*get_cheappest(t_stack *stack)
{
    while (stack)
    {
        if (stack->cheappest == 1)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void	set_current_position(t_stack *stack)
{
    int i;
    int median;

    i = 0;
    median = ft_double_lstsize(stack) / 2;
    while (stack)
    {
        stack->pos = i;
        if (i <= median)
            stack->above_median = 1;
        else
            stack->above_median = 0;
        stack = stack->next;
        i++;
    }
}
