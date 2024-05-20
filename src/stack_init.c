#include "../include/push_swap.h"

static void	append_node(t_stack_node **stack, int num)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = num;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_left_stack(t_stack_node **left_stack, char *argv[])
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		//if (error_search(argv[i]))
		//	free_errors(left_stack);
		num = ft_atol(argv[i]);
		//if (num > INT_MAX || num < INT_MIN)
		//	free_errors(left_stack);
		//if (error_duplicate(*left_stack, (int)num))
		//	free_errors(left_stack);
		append_node(left_stack, (int)num);
		i++;
	}
}
