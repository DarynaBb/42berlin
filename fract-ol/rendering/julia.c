#include "../fractol.h"

int	julia(t_complex z, t_complex c)
{
	int	i;

	i = 0;
	while(i < MAX_ITER && complex_modulus_squared(z) < 4.0)
	{
		z = complex_add(complex_square(z), c);
		i++;
	}
	return (i);
}