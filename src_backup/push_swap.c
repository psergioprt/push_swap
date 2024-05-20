#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*left_stack;
	//t_stack_node	*right_stack;

	left_stack = NULL;
//	right_stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	/*else if	(argc == 2)
		argv = split(argv[1], ' ');*/
	init_left_stack(&left_stack, argv + 1);
	print_stack(left_stack);
	free_stack(&left_stack);
	return (0);
}
