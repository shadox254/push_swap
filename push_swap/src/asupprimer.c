#include "../include/push_swap.h"

void print_debug(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	printf("\n====== ETAT DES PILES ======\n");
	printf("--- STACK A ---\n");
	if (!a)
		printf("(vide)\n");
	else
	{
		tmp = a;
		while (tmp)
		{
			printf("Val: %d | Idx: %d | Adr: %p | Prev: %p | Next: %p", 
				tmp->value, tmp->index, (void*)tmp, (void*)tmp->previous, (void*)tmp->next);
			if (tmp->previous && tmp->previous->next != tmp)
				printf("  <-- BROKEN LINK (Prev->next != Curr)");
			if (tmp->next && tmp->next->previous != tmp)
				printf("  <-- BROKEN LINK (Next->prev != Curr)");
			printf("\n");
			tmp = tmp->next;
		}
	}
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