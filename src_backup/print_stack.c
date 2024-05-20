#include "../include/push_swap.h"

void	print_stack(t_stack_node *stack)
{
	ft_printf("Left Stack: ");
	while (stack)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}
