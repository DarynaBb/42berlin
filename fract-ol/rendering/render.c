#include "../fractol.h"

void	render_fractal(t_fractal *fr)
{
	int			i;
	int			x;
	int			y;
	t_complex	c;
	int			color;
	int			offset;
	
	double real_factor = (fr->x_max - fr->x_min) / WIDTH;
	double imag_factor = (fr->y_max - fr->y_min) / HEIGHT;

	y = 0;
	while (y < HEIGHT)
	{
		c.imag = fr->y_min + y * imag_factor; 
		x = 0;
		while (x < WIDTH)
		{
			c.real = fr->x_min + x * real_factor;
			// c.imag = fr->y_min + (y / (double)HEIGHT * (fr->y_max - fr->y_min));
			if (fr->type == MANDELBROT)
				i = mandelbrot(c);
			else if (fr->type == BURNING_SHIP)
				i = burning_ship(c);
			else if (fr->type == JULIA)
				i = julia(c, fr->julia_c);
			if (fr->img->color == 1)
				color = get_color_1(i);
			else if (fr->img->color == 2)
				color = get_color_2(i);
			else if (fr->img->color == 3)
				color = get_color_3(i);
			offset = (y * fr->img->line_length) + ((fr->img->bpp / 8) * x);
			*(unsigned int *)(fr->img->addr + offset) = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->window, fr->img->img_ptr, 0, 0);
}

// int render_loop(t_fractal *fr)
// {
// 	//  if (fr->pending_zoom || fr->pending_shift)  // Avoid unnecessary recalculations
//     // {
// 	// 	process_shift(fr);
// 	// 	process_zoom(fr);
//     // }
// 		render_fractal(fr);  // **Redraw the fractal**
// 		mlx_put_image_to_window(fr->mlx, fr->window, fr->img->img_ptr, 0, 0);
	
// 	return (0);
// }