#include "../fractol.h"

double ft_atof(const char *str)
{
	double result = 0.0;
	double fraction = 0.0;
	double divisor = 1.0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction = fraction * 10.0 + (*str - '0');
			divisor *= 10.0;
			str++;
		}
	}
	return sign * (result + (fraction / divisor));
}
