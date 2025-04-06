#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>

// TODO add max_iter in a struct

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
	// Set initial bounds of the complex plane
	fr->x_min = X_MIN;
	fr->x_max = X_MAX;
	fr->y_min = Y_MIN;
	fr->y_max = Y_MAX;
	fr->mouse_x = -1;
	fr->mouse_y = -1;
	fr->img->color = 1;
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
	return (0);
}


int main(int count, char **argv)
{
	t_fractal		fr;
	// t_fractal_type	type;
	t_complex		julia;

	fr.type = parse_args(count, argv, &julia);
	fr.julia_c = julia;
	if (init_fractal(&fr))
		return (EXIT_FAILURE);
	init_fractal_params(&fr, fr.type);
	mlx_key_hook(fr.window, handle_keys, &fr);
	mlx_hook(fr.window, 17, 0, handle_close, &fr);
	mlx_mouse_hook(fr.window, handle_mouse, &fr);
	mlx_loop_hook(fr.mlx, render_fractal, &fr);
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
