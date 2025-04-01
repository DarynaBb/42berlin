#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>



int	handle_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
	return (1);
}

void	init_fractal_params(t_fractal *fr, t_fractal_type type)
{
	fr->type = type;
	// Default zoom and center position
	fr->zoom = 1.0;
	fr->center_x = 0.0;
	fr->center_y = 0.0;
	fr->zoom_level = 1;
	// Set initial bounds of the complex plane
	fr->x_min = X_MIN;
	fr->x_max = X_MAX;
	fr->y_min = Y_MIN;
	fr->y_max = Y_MAX;
	// If it's Julia, set a default constant (modifiable via user input)
	if (fr->type == JULIA)
	{
		fr->julia_c.real = -0.7;
		fr->julia_c.imag= 0.27015;
	}
}


int	init_fractal(t_fractal *fr)
{
	fr->mlx = mlx_init();
	if(!fr->mlx)
		return (handle_error("Error: MLX initialization failed\n"));
	fr->window = mlx_new_window(fr->mlx, WIDTH, HEIGHT, "Fractol");
	if(!fr->window)
	{
		free(fr->mlx);
		return(handle_error("Error: Window creation failed\n"));
	}
	fr->img = malloc(sizeof(t_img));
	if (!fr->img)
	{
		mlx_destroy_window(fr->mlx, fr->window);
		free(fr->mlx);
		return (handle_error("Error: Memory allocation failed\n"));
	}
	fr->img->img_ptr = mlx_new_image(fr->mlx, WIDTH, HEIGHT);
	if (!fr->img->img_ptr)
	{
		free(fr->img);
		mlx_destroy_window(fr->mlx, fr->window);
		free(fr->mlx);
		return (handle_error("Error: Image creation failed\n"));
	}
	fr->img->addr = mlx_get_data_addr(fr->img->img_ptr, &fr->img->bpp,
		&fr->img->line_length, &fr->img->endian);
	init_palette();
	return (0);
}

t_fractal_type	parse_args(int count, char **argv)
{
	if (count < 2)
	{
		ft_putstr_fd("Usage: ./fractol <fractal_type>\n", 2);
		ft_putstr_fd("Available fractals: mandelbrot, julia\n", 2);
		exit(1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		return (MANDELBROT);
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		return (JULIA);
	else
	{
		ft_putstr_fd("Invalid fractal type\n", 2);
		exit(1);
	}
	return (0);
}

int main(int count, char **argv)
{
	t_fractal		fr;
	t_fractal_type	type;

	type = parse_args(count, argv);
	if (init_fractal(&fr))
		return (EXIT_FAILURE);
	init_fractal_params(&fr, type);
	// render_fractal(&fr);
	// mlx_put_image_to_window(fr.mlx, fr.window, fr.img->img_ptr, 0, 0);
	// mlx_key_hook(fr.window, handle_esc, &fr);
	mlx_key_hook(fr.window, handle_shift, &fr);
	mlx_hook(fr.window, 17, 0, handle_close, &fr);
	mlx_mouse_hook(fr.window, handle_mouse, &fr);
	mlx_loop_hook(fr.mlx, render_loop, &fr);
	mlx_loop(fr.mlx);
	if (fr.img && fr.img->img_ptr)
		mlx_destroy_image(fr.mlx, fr.img->img_ptr);
	free(fr.img);
	if (fr.window)
		mlx_destroy_window(fr.mlx, fr.window);
	if (fr.mlx)
		free(fr.mlx);
	return (0);
}

