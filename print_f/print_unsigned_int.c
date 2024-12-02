#include "ft_printf.h"

static int	str_size(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	print_unsigned_int(unsigned int num)
{
	char	str[11];
	int		i;
	int		str_len;

	str_len = str_size(num);
	if (num == 0)
		return (write(1, "0", 1));
	str[str_len] = '\0';
	i = str_len - 1;
	while (num > 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (print_str(str));
}
