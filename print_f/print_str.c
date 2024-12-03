#include "ft_printf.h"

int	print_str(const char *str)
{
	int	i;
	int	write_count;

	write_count = 0;
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		write_count += write(1, &str[i], 1);
		i++;
	}
	return (write_count);
}
