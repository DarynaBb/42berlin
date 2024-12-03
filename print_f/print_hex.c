#include "ft_printf.h"

int	print_hex(unsigned int num, char spec)
{
	char	*str;
	int		count;

	count = 0;
	str = dec_to_hex(num, spec);
	if (!str)
		return (-1);
	count = print_str(str);
	free(str);
	return (count);
}
