#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_data
{
	t_stack *stack_a;
	t_stack *stack_b;
}	t_data;

// SORT OPERATIONS
void	pa(t_stack **src, t_stack **dest);
void	pb(t_stack **src, t_stack **dest);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

// A SUpPRIMER
void free_stack(t_stack **stack);
void print_debug(t_stack *a, t_stack *b);

// CHECK
int check_only_num(char *str);
int check_order(t_stack **stack);
int check_dup_num(t_stack **stack);
int create_data(t_stack **stack, int ac, char **av);

// ERROR HANDLING
int error(t_data *data);
void clear_data(t_data *data);

// DOUBLE LIST CMD
t_stack *ft_double_lst_new(int value);
int ft_double_lstsize(t_stack *stack);
void ft_clear_double_lst(t_stack **lst);
void ft_double_lst_add_back(t_stack **lst, t_stack *new);
void	ft_double_lstadd_front(t_stack **lst, t_stack *new);

#endif
