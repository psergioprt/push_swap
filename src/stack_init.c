#include "push_swap.h"

static void	append_node(t_stack_node **stack, int num)//Define a function that searches for the last node to append to the linked list
{
	t_stack_node	*node; //To store a pointer to the new node to be created with the value `n`
	t_stack_node	*last_node; //To store a pointer to the current last node of the stack

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL; //Set the next pointer of the new node to NULL because it will be the last node in the list
	node->nbr = num; //Set the `next` data of the new node to `n` value
	if (!(*stack)) // Check if the stack is empty or currently pointing to NULL, indicating a first node needs to be found
	{
		*stack = node; //If empty, update the pointer *stack to point to the node, effectively making it the new head of the linked list
		node->prev = NULL; //Set the head node's previous pointer to NULL as it's the first node
	}
	else //If the stack is not empty, it means there are existing nodes in the linked list
	{
		last_node = find_last(*stack); //In which case, find the last node
		last_node->next = node; //Append the new node to the last node
		node->prev = last_node; //Update the previous pointer of the new node and complete the appending
	}
}
void	init_left_stack(t_stack_node **left_stack, char *argv[]) //Define a function that initiates stack `a` by handling any errors and appending required nodes to complete a stack.
{
	long	num;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (error_search(argv[i]))
			free_errors(left_stack);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)//Check for overflow
			free_errors(left_stack);
		if (error_duplicate(*left_stack, (int)num))
			free_errors(left_stack);
		append_node(left_stack, (int)num); //If no errors, append the node to the linked list by taking a pointer `a`, create a new node and assign `n` to that new node.
		i++;
	}
}
