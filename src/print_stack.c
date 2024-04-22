#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	printf("Left Stack: ");
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}
