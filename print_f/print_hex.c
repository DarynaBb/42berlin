#include "ft_printf.h"

static char	*handle_zero_case(void)
{
	char	*hex_string;

	hex_string = (char *)malloc(2 * sizeof(char));
	if (!hex_string)
		return (NULL);
	hex_string[0] = '0';
	hex_string[1] = '\0';
	return (hex_string);
}

static char	*hex_string(char *str, int length)
{
	char	*hex_string;
	int		i;

	i = 0;
	hex_string = (char *)malloc((length + 1) * sizeof(char));
	if (!hex_string)
		return (NULL);
	while (i < length)
	{
		hex_string[i] = str[length - i - 1];
		i++;
	}
	hex_string[length] = '\0';
	return (hex_string);
}

static char	*dec_to_hex(unsigned int num, char spec)
{
	char	buffer[100];
	int		i;
	int		remainder;

	if (num == 0)
		return (handle_zero_case());
	i = 0;
	while (num > 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			buffer[i] = remainder + '0';
		else
		{
			if (spec == 'X')
				buffer[i] = remainder + 'A' - 10;
			else
				buffer[i] = remainder + 'a' - 10;
		}
		num /= 16;
		i++;
	}
	buffer[i] = '\0';
	return (hex_string(buffer, i));
}

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
