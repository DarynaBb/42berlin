#include "../fractol.h"

#include <stdlib.h>  // Для atof()

void	invalid_args_julia(void)
{
	ft_putstr_fd("Usage: ./fractol julia <real> <imag>\n", 2);
	ft_putstr_fd("Example: ./fractol julia -0.8 0.156\n", 2);
	exit(1);
}

int	is_valid_double(char *str)
{
	int i = 0;
	int dot_count = 0;

	if (str[i] == '-' || str[i] == '+') // Перевірка знаку
		i++;
	if (!str[i]) // Порожній рядок після знаку
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1) // Більше однієї десяткової крапки — помилка
				return (0);
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_fractal_type	parse_args(int count, char **argv, t_complex *julia_c)
{
	if (count < 2)
	{
		ft_putstr_fd("Usage: ./fractol <fractal_type>\n", 2);
		ft_putstr_fd("Available fractals: mandelbrot, julia, burning_ship\n", 2);
		exit(1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		return (MANDELBROT);
		else if (ft_strncmp(argv[1], "julia", 5) == 0)
		{
			if (count == 2)
			{
				julia_c->real = -0.7;
				julia_c->imag = 0.27015;
			}
			else if (count == 3 || count > 4) // Julia вимагає двох додаткових параметрів
				invalid_args_julia();
			else if (count == 4)
			{
				if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
				{
					ft_putstr_fd("Error: Julia parameters must be valid floating-point numbers\n", 2);
					exit(1);
				}
				else
				{
					julia_c->real = ft_atof(argv[2]);
					julia_c->imag = ft_atof(argv[3]);
				}
			}
			return (JULIA);
		}
	else if (ft_strncmp(argv[1], "sierpinski", 11) == 0)
		return (SIERPINSKI);
	else if (ft_strncmp(argv[1], "burning_ship", 12) == 0)
		return (BURNING_SHIP);
	else
	{
		ft_putstr_fd("Invalid fractal type\n", 2);
		ft_putstr_fd("Usage: ./fractol <fractal_type>\n", 2);
		ft_putstr_fd("Available fractals: mandelbrot, julia, burning_ship\n", 2);
		ft_putstr_fd("Additional parameters for Julia: ./fractol julia <real> <imag>\n", 2);
		exit(1);
	}
	return (0);
}
