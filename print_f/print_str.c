#include "ft_printf.h"

int	print_str(const char *str)
{
	int	i;
	int	write_count;
	int	k;

	write_count = 0;
	k = 0;
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		k = write(1, &str[i], 1);
		if (k < 0)
			return (-1);
		else
			write_count += k;
		i++;
	}
	return (write_count);
}
