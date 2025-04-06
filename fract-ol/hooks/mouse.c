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
	if (button == 4) // Scroll Up (Zoom in)
		update_fractal_bounds(fr, 0.85, x, y); // Zoom in (factor < 1)
	else if (button == 5) // Scroll Down (Zoom out)
		update_fractal_bounds(fr, 1.15, x, y); // Zoom out (factor > 1)
	return (0);
}

// void process_zoom(t_fractal *fr)
// {
// 	double	zoom_factor;

// 	if (fr->pending_zoom == 0) 
// 		return;
// 	if (fr->pending_zoom == -1)
// 		zoom_factor = 0.85;
// 	else
// 		zoom_factor = 1.15;
// 	fr->pending_zoom = 0;  // Reset request after processing
// 	update_fractal_bounds(fr, zoom_factor, fr->mouse_x, fr->mouse_y);
// }

