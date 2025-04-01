#include "../fractol.h"

int	get_color (int i, int max_iter)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	if (i == max_iter)
		return (0x000000);
	t = (double)i / max_iter;
	red = (int)(9 * (1 -t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

// int get_color(int i, int max_iter)
// {
//     return (i == max_iter) ? 0x000000 : 0xFFFFFF;
// }

// int	get_color(int i, int max_iter)
// {
// 	int		red;
// 	int		green;
// 	int		blue;
// 	double	t;

// 	if (i == max_iter)
// 		return (0x000000); // Black for points inside the set

// 	t = (double)i / 50;

// 	// Sine wave color mapping for smooth gradients
// 	red = (int)(cos(0.16 * i + 4) * 127 + 128);
// 	green = (int)(cos(0.16 * i + 2) * 127 + 128);
// 	blue = (int)(cos(0.16 * i) * 127 + 128);

// 	return ((red << 16) | (green << 8) | blue);
// }

// int	get_color(int i, int max_iter)
// {
// 	if (i == max_iter)
// 		return (0x000000); // Black for points inside the set

// 	// Normalize `i` within `max_iter`
// 	double t = (double)i / max_iter;

// 	// Faster gradient without `cos()`
// 	int red = (int)(9 * (1 - t) * t * t * t * 255);
// 	int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
// 	int blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

// 	return ((red << 16) | (green << 8) | blue);
// }

int color_palette[MAX_ITER];

void init_palette()
{
    for (int i = 0; i < MAX_ITER; i++)
        color_palette[i] = get_color(i, MAX_ITER);
}

int get_color_fast(int i)
{
    return (i < MAX_ITER) ? color_palette[i] : 0x000000;
}