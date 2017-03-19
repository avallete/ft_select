#include "libft.h"

char			*ft_strdupif(const char *s, int (*f)(int c))
{
	size_t		i;
	size_t		e;
	size_t		len;
	char		*scop;

	i = 0;
	e = 0;
	len = (ft_strcount(s, f) + 1);
	if ((scop = (char*)malloc(sizeof(char) * len)))
	{
		while (s[i] && i <= len)
		{
			if (f(s[i]))
				scop[e++] = s[i];
			++i;
		}
		scop[e] = '\0';
		return (scop);
	}
	return (NULL);
}
