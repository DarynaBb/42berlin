#include "../fractol.h"

int	handle_esc(int keycode, t_fractal *fr)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(fr->mlx, fr->window);
		mlx_destroy_display(fr->mlx);
		free(fr->mlx);
		exit(0);
	}
	return (0);
}

int	handle_close(t_fractal *fr)
{
	mlx_destroy_window(fr->mlx, fr->window);
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	exit(0);
	return(0);
}

int	handle_color(int keycode, t_fractal *fr)
{
	if (keycode == 97 || keycode == 65)
		fr->img->color = 1;
	else if (keycode == 98 || keycode == 66)
		fr->img->color = 2;
	else if (keycode == 99 || keycode == 67)
		fr->img->color = 3;
	render_loop(fr);
	return (0);
}

int	handle_keys(int keycode, t_fractal *fr)
{
    printf("Key pressed: %d\n", keycode);  // Debugging keypresses
	if (keycode == XK_Escape)
		handle_esc(keycode, fr);  // Handle Escape key
	else if ((keycode >= 65 && keycode <= 90) || (keycode >= 97 && keycode <= 122))
		handle_color(keycode, fr);
	else if (keycode == 65361) // Left arrow
		fr->pending_shift = -1;
	else if (keycode == 65363) // Right arrow
		fr->pending_shift = 1;
	else if (keycode == 65362) // Up arrow
		fr->pending_shift = -2;
	else if (keycode == 65364) // Down arrow
		fr->pending_shift = 2;
	else
		return (0);  // Ignore other keys
	return (0);
}

void process_shift(t_fractal *fr)
{
	// double	shift_amount;
	// shift_amount = (fr->x_max - fr->x_min) * 0.1;
	if (fr->pending_shift == 0) 
		return;
	if (fr->pending_shift == -1)
	{
		fr->x_max -= (fr->x_max - fr->x_min) * 0.1;
		fr->x_min -= (fr->x_max - fr->x_min) * 0.1;
	}
	else if (fr->pending_shift == 1)
	{
		fr->x_max += (fr->x_max - fr->x_min) * 0.1;
		fr->x_min += (fr->x_max - fr->x_min) * 0.1;
	}
	else if(fr->pending_shift == -2)
	{
		fr->y_max -= (fr->x_max - fr->x_min) * 0.1;
		fr->y_min -= (fr->x_max - fr->x_min) * 0.1;
	}
	else if (fr->pending_shift == 2)
	{
		fr->y_max += (fr->x_max - fr->x_min) * 0.1;
		fr->y_min += (fr->x_max - fr->x_min) * 0.1;
	}
	fr->pending_shift = 0;
}
