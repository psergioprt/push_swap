#include "push_swap.h"

int	error_search(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= 48 && *str <= 57)))
		return (1);
	if (*str == '+' || *str == '-' && !(str[1] >= 48 && str[1] <= 57))
		return (1);
	while (*++str)
	{
		if (!(*str >= 48 && *str <= 57))
			return (1);
	}
	return (0);		
}

int	error_duplicate(t_stack_node *left_stack, int num)
{
	if (!left_stack)
		return (0);
	while (left_stack)
	{
		if (left_stack->nbr == num)
			return (1);
		left_stack = left_stack->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **stack)
{
	free_stack(stack);
	printf("Error\n");
	exit(1);
}
