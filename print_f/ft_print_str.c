#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	str_len;
	int	i;

	if (!str)
		str = ("null");
	str_len = 0;
	i = 0;
	while (str[i])
	{
		str_len++;
		write(1, &str[i], 1);
		i++;
	}
	return (str_len);
}
