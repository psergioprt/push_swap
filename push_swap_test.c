#include <stdio.h>
#include <stdlib.h>

//Define the node structure
typedef struct Node
{
	int			data;
	struct Node		*next;
}				Node;

//Define the Stack structure
typedef struct Stack {
	Node			*top;
}				Stack;

//Implement Stack operations
void push (Stack *stack, int value) //Function to push onto the stack
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
		return;
	newNode->data = value;
	newNode->next = stack->top;
	stack->top = newNode;	
}

//Function to pop a value from the stack
int	pop(Stack *stack)
{
	if (stack->top == NULL)
		return (-1);
	int	value = stack->top->data;
	Node *temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	return (value);
}

//Function to peek at the top value of the stack
int	peek(Stack *stack)
{
	if (stack->top == NULL)
		return (-1);
	return (stack->top->data);
}

//Initialize Stacks
Stack	*initializeStack()
{
	Stack	*stack = (Stack *)malloc(sizeof(Stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

//Transfer Values
void transferValues(Stack *source, Stack *destination)
{
	while (source->top != NULL)
	{
		int	value = pop(source);
		push(destination, value);
	}
}



int	main(int argc, char *argv[])
{
	if (argc < 2)

	{
		printf("Usage: %s <value1> <value2> ... <valueN>\n", argv[0]);
		return (1);
	}
	//Initialize source and destination stacks
	Stack	*sourceStack = initializeStack();
	Stack	*destinationStack = initializeStack();
	int	i;
	int	value;

	i = 1;
	//Parse command-line arguments and push values onto the source stack
	while (i < argc)
	{
		value = atoi(argv[i]);
		push(sourceStack, value);
		i++;
	}
	//Transfer values from source stack to destination stack
	transferValues(sourceStack, destinationStack);

	//Print values in the destination stack (should be reversed)
	printf("Values in destination stack (reversed):\n");
	while (destinationStack->top != NULL)
		printf("Destiny %d ", pop(destinationStack));
	printf("\n");
	transferValues(destinationStack, sourceStack);
	while (sourceStack->top != NULL)
		printf("Source %d ", pop(sourceStack));
	printf("\n");
	free(sourceStack);
	free(destinationStack);
	return (0);
}
