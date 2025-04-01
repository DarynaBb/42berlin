#include "../fractol.h"

void	render_fractal(t_fractal *fr)
{
	int			i;
	int			x;
	int			y;
	t_complex	c;
	int			color;
	int			offset;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = fr->x_min + (x / (double)WIDTH * (fr->x_max - fr->x_min));
			c.imag = fr->y_min + (y / (double)HEIGHT * (fr->y_max - fr->y_min));
			if (fr->type == MANDELBROT)
				i = mandelbrot(c, fr->zoom_level);
			else if (fr->type == JULIA)
				i = julia(c, fr->julia_c, fr->zoom_level);
			color = get_color_fast(i);
			offset = (y * fr->img->line_length) + ((fr->img->bpp / 8) * x);
			*(unsigned int *)(fr->img->addr + offset) = color;
			x++;
		}
		y++;
	}
}

int render_loop(t_fractal *fr)
{
	process_shift(fr); 
	process_zoom(fr);  // **Handle zoom before rendering**
	render_fractal(fr);  // **Redraw the fractal**
	mlx_put_image_to_window(fr->mlx, fr->window, fr->img->img_ptr, 0, 0);
	return (0);
}