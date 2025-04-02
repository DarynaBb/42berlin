#include "../fractol.h"

int	burning_ship(t_complex c)
{
	int	i;
	t_complex	z;

	i = 0;
	z.real = 0;
	z.imag = 0;

	while(i < MAX_ITER && complex_modulus_squared(z) < 4.0)
	{
		z.real = fabs(z.real);
		z.imag = fabs(z.imag);
		z = complex_multiply(z, z);
		z = complex_add(z, c);
		i++;
	}
	return i;
}