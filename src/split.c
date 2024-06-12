#include "../include/push_swap.h"

static int	words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	insert(char **split, char const *s, char c)
{
	char const	*temp;

	temp = s;
	while (*temp)
	{
		while (*s == c)
			s++;
		temp = s;
		while (*temp != c && *temp)
			temp++;
		if (*temp == c || temp > s)
		{
			*split = ft_substr(s, 0, temp - s);
			s = temp;
			split++;
		}
	}
	*split = NULL;
}

char	**split(char const *s, char c)
{
	char	**split;
	int		size;

	size = words(s, c);
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	insert(split, s, c);
	return (split);
}
