#include "../fractol.h"

void update_fractal_bounds(t_fractal *fr, double zoom_factor, int x, int y)
{
    // Convert pixel coordinates to complex plane coordinates
	double mouse_real = fr->x_min + (x / (double)WIDTH) * (fr->x_max - fr->x_min);
	double mouse_imag = fr->y_min + (y / (double)HEIGHT) * (fr->y_max - fr->y_min);

	// Adjust bounds while keeping the zoom centered on the mouse position
	fr->x_min = mouse_real + (fr->x_min - mouse_real) * zoom_factor;
	fr->x_max = mouse_real + (fr->x_max - mouse_real) * zoom_factor;
	fr->y_min = mouse_imag + (fr->y_min - mouse_imag) * zoom_factor;
	fr->y_max = mouse_imag + (fr->y_max - mouse_imag) * zoom_factor;

	// Adjust zoom level
	fr->zoom *= zoom_factor;
}

int handle_mouse(int button, int x, int y, t_fractal *fr)
{
	if (button == 4)      // Scroll Up (Zoom in)
	{
		fr->pending_zoom = -1;
		fr->zoom_level++;
	}
	else if (button == 5) // Scroll Down (Zoom out)
	{
		fr->pending_zoom = 1;
		if (fr->zoom_level > 1)             
			fr->zoom_level--;
	}
	return (0);
}
void process_zoom(t_fractal *fr)
{
	if (fr->pending_zoom == 0) 
		return;
	double zoom_factor = (fr->pending_zoom == -1) ? 0.7 : 1.1;
	fr->pending_zoom = 0;  // Reset request after processing

	update_fractal_bounds(fr, zoom_factor, WIDTH / 2, HEIGHT / 2);
	// render_fractal(fr);
	// mlx_put_image_to_window(fr->mlx, fr->window, fr->img->img_ptr, 0, 0);
}
