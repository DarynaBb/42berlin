#include "../fractol.h"

int	mandelbrot(t_complex c, int zoom_level)
{
	int	i;
	t_complex	z;
	// int max_iter = 50 + (zoom_level * 10);

	// if (zoom_level > 20)  
	// 	max_iter = 50;   // Low iterations for deep zoom (faster)
	// else if (zoom_level > 10)  
	// 	max_iter = 100;  // Mid-range quality
	// else  
	// 	max_iter = 300;  

	i = 0;
	z.real = 0;
	z.imag = 0;

	while(i < MAX_ITER && complex_modulus_squared(z) < 4.0)
	{
		z = complex_add(complex_multiply(z, z), c);
		i++;
	}
	return i;
}