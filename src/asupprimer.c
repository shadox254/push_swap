#include "../include/push_swap.h"

void print_stack_a(t_stack *a)
{
	t_stack *tmp;

	printf("--- STACK A ---\n");
	if (!a)
		printf("(vide)\n");
	else
	{
		tmp = a;
		while (tmp)
		{
			printf("Val: %d | Idx: %d | Adr: %p | Prev: %p | Next: %p\n", 
			tmp->value, tmp->index, (void*)tmp, (void*)tmp->previous, (void*)tmp->next);
			tmp = tmp->next;
		}
	}
	printf("============================\n\n");
}

void print_stack_b(t_stack *b)
{
	t_stack *tmp;

	printf("\n--- STACK B ---\n");
	if (!b)
		printf("(vide)\n");
	else
	{
		tmp = b;
		while (tmp)
		{
			printf("Val: %d | Idx: %d | Adr: %p | Prev: %p | Next: %p\n", 
			tmp->value, tmp->index, (void*)tmp, (void*)tmp->previous, (void*)tmp->next);
			tmp = tmp->next;
		}
	}
	printf("============================\n\n");
}

void free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}