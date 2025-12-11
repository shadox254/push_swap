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
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheappest == 1) // On a trouvé l'élu
            return (stack);
        stack = stack->next;
    }
    return (NULL); // Sécurité si aucun n'est marqué (ne devrait pas arriver)
}
