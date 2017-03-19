#include "libft.h"

size_t	ft_strcount(char const *s, int (*f)(int c))
{
	int	i;
	size_t	count;

	count = 0;
	i = 0;
	if (s && *s)
	{
		while (s[i])
		{
			if (f(s[i]))
				++count;
			++i;
		}
	}
	return (count);
}
