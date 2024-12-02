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

static int	is_negative(int num, char *str, int *str_size)
{
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	return (num);
}

int	ft_print_int(int num)
{
	char	*str;
	int		str_len;
	int		printed_chars;

	if (num == 0)
		return (write(1, "0", 1));
	if (num == INT_MIN)
		return (write(1, "-2147483648", 11));
	str_len = str_size(num);
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (-1);
	if (num < 0)
		num = is_negative(num, str, &str_len);
	while (num > 0)
	{
		str[--str_len] = (num % 10) + '0';
		num = num / 10;
	}
	printed_chars = ft_print_str(str);
	free(str);
	return (printed_chars);
}
