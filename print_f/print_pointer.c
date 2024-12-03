#include "ft_printf.h"

int	print_pointer(uintptr_t ptr)
{
	char	*str;
	int		count;
	int		str_count;

	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	str = dec_to_hex(ptr, 'x');
	if (!str)
		return (-1);
	str_count = print_str(str);
	if (str_count < 0)
	{
		free(str);
		return (-1);
	}
	count += str_count;
	free(str);
	return (count);
}
