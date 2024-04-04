/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:51:08 by pauldos-          #+#    #+#             */
/*   Updated: 2023/10/31 12:02:40 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION: strlen()
The strlen() function calculates the length of the string pointed to by s, 
excluding the terminating null byte ('\0').
*/

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <string.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("Myfunc: %d\n", ft_strlen(argv[1]));
		printf("Sysfunc: %lu\n", strlen(argv[1]));
	}
	return (0);
}*/
