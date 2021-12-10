#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&(((unsigned char *)s)[i]));
		n--;
		i++;
	}
	return (0);
}
