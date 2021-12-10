#include "../libft.h"

int	ft_if_char(char c, va_list ap)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	if (c == 's')
		return (ft_putstr_size(va_arg(ap, char *), 1));
	return (0);
}
