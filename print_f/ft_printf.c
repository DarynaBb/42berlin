#include "ft_printf.h"

static int	handle_spec(char spec, va_list *args)
{
	if (spec == 'c')
		return (print_char(va_arg(*args, int)));
	if (spec == 's')
		return (print_str(va_arg(*args, const char *)));
	if (spec == 'p')
		return (print_pointer(va_arg(*args, uintptr_t)));
	if (spec == 'd' || spec == 'i')
		return (print_int(va_arg(*args, int)));
	if (spec == 'u')
		return (print_unsigned_int(va_arg(*args, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (print_hex(va_arg(*args, unsigned int), spec));
	if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		total;

	va_start(args, str);
	count = 0;
	total = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			count = handle_spec(*str, &args);
		}
		else
			count = write (1, str, 1);
		if (count < 0)
		{
			va_end(args);
			return (-1);
		}
		total += count;
		str++;
	}
	va_end(args);
	return (total);
}
