/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:08:31 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/18 17:32:12 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	validate_numbers_signs(char *argv)
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

static bool	validate_arguments(char argc, char ***argv)
{
	if (argc == 1)
		return (false);
	if (argc == 2 && (*argv)[1][0] == ' ')
	{
		write(2, "Error\n", 6);
		return (false);
	}
	if (argc == 2 && ((*argv)[1][0] == '\0'
		|| validate_numbers_signs((*argv)[1]) == false))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	return (true);
}

static bool	initiate_stack(char argc, char ***argv, t_stack_node **a)
{
	if (argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		init_left_stack(a, *argv, true);
	}
	else
		init_left_stack(a, *argv + 1, false);
	return (true);
}

void	ft_free_args(char **argv, bool flag)
{
	int	i;

	i = 0;
	if (flag == true)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (!validate_arguments(argc, &argv))
		return (1);
	if (!initiate_stack(argc, &argv, &a))
		return (1);
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
