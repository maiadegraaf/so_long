#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	if (!s)
		return (0);
	ret = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// char f(unsigned int i, char c)
// {
// 	char str;
// 	str = c + i;
// 	return (str);
// }

// int main()
// {
// 	char str1[] = "override this !";
// 	char* str2;
// 	str2 = ft_strmapi(str1, *f);
// 	printf("%s\n", str2);
// }