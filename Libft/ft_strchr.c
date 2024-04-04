/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:37:53 by pauldos-          #+#    #+#             */
/*   Updated: 2023/10/31 13:00:08 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION: strchr()
The  strchr()  function  returns  a  pointer  to the first occurrence of the 
character c in the string s.
Here "character" means "byte"; these functions do not work with wide or 
multibyte characters.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
/*
int	main(void)
{
	char	str[] = "My name is Luka";
	char	a = 'n';
	char	*b = ft_strchr(str, a);

	printf("After '%c' we get '%s'", a, b);
	return (0);
}*/
