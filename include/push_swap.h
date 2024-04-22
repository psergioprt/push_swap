#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <../Libft/libft.h>

typedef struct s_stack_node
{
	int		nbr;
	//int		index;
	//int		push_cost;
	//bool		above_median;
	//bool		cheapest;

	struct	s_stack_node *target_node;
	struct	s_stack_node *next;
	struct	s_stack_node *prev;
}	t_stack_node;

//Handle errors
int		error_search(char *str_n);
int		error_duplicate(t_stack_node *left_stack, int num);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **stack);

//Stack initiation
void	init_left_stack(t_stack_node **left_stack, char *argv[]);

//Nodes initiation

//Stack utils
t_stack_node	*find_last(t_stack_node *stack);

//Print Stack
void	print_stack(t_stack_node *stack);

//Commands

//Algorithms


#endif
