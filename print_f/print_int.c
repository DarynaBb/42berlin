#include "ft_printf.h"

static int	str_size(int num)
{
	int	char_count;

	char_count = 0;
	if (num == 0)
		return (1);
	if (num <= 0)
		char_count++;
	while (num != 0)
	{
		num = num / 10;
		char_count++;
	}
	return (char_count);
}

static int	is_negative(int num, char *str)
{
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	return (num);
}

int	print_int(int num)
{
	char	str[12];
	int		str_len;
	int		i;

	if (num == 0)
		return (write(1, "0", 1));
	if (num == INT_MIN)
		return (write(1, "-2147483648", 11));
	str_len = str_size(num);
	if (num < 0)
		num = is_negative(num, str);
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
