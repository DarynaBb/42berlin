#include "../fractol.h"

int	get_color_1(int i)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	if (i == MAX_ITER)
		return (0x000000);
	t = (double)i / MAX_ITER;
	red = (int)(9 * (1 -t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

int	get_color_2(int i)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	if (i == MAX_ITER)
		return (0x000000); // Black for points inside the set

	t = (double)i / 50;

	// Sine wave color mapping for smooth gradients
	red = (int)(cos(0.16 * i + 4) * 127 + 128);
	green = (int)(cos(0.16 * i + 2) * 127 + 128);
	blue = (int)(cos(0.16 * i) * 127 + 128);

	return ((red << 16) | (green << 8) | blue);
}

int	get_color_3(int i)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	if (i == MAX_ITER)
		return (0x000000); // Black for points inside the set

	t = (double)i / 50;

	// Sine wave color mapping for smooth gradients
	red = (int)(sin(0.16 * i + 4) * 127 + 128);
	green = (int)(sin(0.16 * i + 2) * 127 + 128);
	blue = (int)(sin(0.16 * i) * 127 + 128);
	return ((blue << 16) | (green << 8) | red);
}
