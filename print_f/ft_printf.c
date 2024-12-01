#include "ft_printf.h"

static int	var_format(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (spec == 's')
		return (ft_print_str(va_arg(*args, const char *)));
	if (spec == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_int(va_arg(*args, int)));
	if (spec == 'u')
		return (ft_print_unsigned_int(va_arg(*args, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int)));
	if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		sum;

	va_start(args, str);
	count = 0;
	sum = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			count += handle_spec(*str, &args);
		}
		else
		{
			write (1, str, 1);
			count++;
		}
		if (count < 0)
			return (-1);
		sum += count;
	}
	va_end(args);
	return (sum);
}
