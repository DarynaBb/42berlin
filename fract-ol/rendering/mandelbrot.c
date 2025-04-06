#include "../fractol.h"

int	mandelbrot(t_complex c)
{
	int	i;
	t_complex	z;

	i = 0;
	z.real = 0;
	z.imag = 0;

	while(i < MAX_ITER && ((z.real * z.real) + (z.imag * z.imag)) < 4.0)
	{
		z = complex_add(complex_multiply(z, z), c);
		i++;
	}
	return i;
}