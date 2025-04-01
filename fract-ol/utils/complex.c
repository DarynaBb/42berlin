#include "../fractol.h"

t_complex	complex_multiply(t_complex a, t_complex b)
{
	t_complex	res;
	res.real = (a.real * b.real) - (a.imag * b.imag);
	res.imag = (a.real * b.imag) + (a.imag * b.real);
	return (res);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	res;
	res.real = a.real + b.real;
	res.imag = a.imag + b.imag;
	return (res);
}

double	complex_modulus_squared(t_complex c)
{
	return (c.real * c.real + c.imag * c.imag);
}

t_complex	complex_square(t_complex c)
{
	t_complex	res;
	res.real = (c.real * c.real) - (c.imag * c.imag);
	res.imag = 2 * c.real * c.imag;
	return (res);
}