/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:08:31 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/11 16:13:45 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*bool	number_validator(char *argv)
{
	int	i;

	i = 0;
	while (argv[1])
	{
		if (argv[1] >= '0' && argv[1] <= '9')
			return (true);
		i++;
	}
	return (false);
}*/

bool	number_validator(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		while (av[i] == 32 || av[i] == '-' || av[i] == '+')
		{
			if (av[i] == '-' || av[i] == '+')
			{
				i++;
				if (av[i] < '0' || av[i] > '9')
					return (false);
			}
			i++;
		}
		if ((av[i] < '0') || (av[i] > '9'))
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
	if ((argc == 2 && argv[1][0] == '\0' )|| number_validator(argv[1]) == false)
	{
		ft_printf("Error\n");
		return (1);
	}
	/*if (argc == 1 || (argc == 2 && !argv[1][0]))
	 	return (1);*/
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		init_left_stack(&a, argv);
	}
	else
		init_left_stack(&a, argv + 1);
	ft_free_args(argv, 2 == argc);//<--
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	//if (2 == argc)
	// int i = 0;
	// while(argv[i])
	// {
	// 	free(argv[i]);
	// 	i++;
	// }
	// free(argv);
	free_stack(&a);
	return (0);
}
