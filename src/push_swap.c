/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:08:31 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/13 15:52:46 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	number_validator(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		while (argv[i] == '-' || argv[i] == '+')
		{
			
			if (argv[i] == '-' || argv[i] == '+')
				i++;
			if (argv[i] < '0' || argv[i] > '9')
				return (false);
			i++;
		}
		i++;
	}
	return (true);
}

bool	validate_number(char *argv)
{
	int	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	/*if (argc == 2 && argv[1][0] == ' ')
	{
		printf("Error\n");
		return (1);
	}*/
	else if (argc == 2 && (argv[1][0] == '\0' || number_validator(argv[1]) == false))
	{
		printf("Error\n");
		return (1);
	}
	
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_left_stack(&a, argv, true);
	}
	else
		init_left_stack(&a, argv + 1, false);
	ft_free_args(argv, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
