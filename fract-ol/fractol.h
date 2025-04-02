#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include <stdio.h>

# define WIDTH 900
# define HEIGHT 600
# define MAX_ITER 250
// # define ZOOM_FACTOR 1.2
# define X_MIN -2.0// Left bound of the complex plane
# define X_MAX 2.0// Right bound of the complex plane
# define Y_MIN -2.0// Bottom bound (imaginary part)
# define Y_MAX 2.0// Top bound (imaginary part)
# define COLOR_TABLE_SIZE 256
# define N_COLOR 1

//Complex number operations
typedef struct	s_complex
{
	double	real;
	double	imag;
}	t_complex;

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_multiply(t_complex a, t_complex b);
double		complex_modulus_squared(t_complex c);
t_complex	complex_square(t_complex c);


//Fractal structure
typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		color;
}	t_img;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	SIERPINSKI,
	BURNING_SHIP
}	t_fractal_type;

typedef struct	s_fractal
{
	void			*mlx;
	void			*window;
	t_img			*img;
	double			zoom;
	// double			center_x;
	// double			center_y;
	t_fractal_type	type;
	t_complex		julia_c;
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	int				pending_zoom;
	int				pending_shift;
	int				mouse_x;
	int				mouse_y;

}	t_fractal;

// Hooks:

//keyboard
int		handle_esc(int keycode, t_fractal *fr);
int		handle_close(t_fractal *fr);
int		handle_keys(int keycode, t_fractal *fr);
void	process_shift(t_fractal *fr);

//mouse
int		handle_mouse(int button, int x, int y, t_fractal *fr);
void	process_zoom(t_fractal *fr);

// Rendering:
void	render_fractal(t_fractal *fr);
int		render_loop(t_fractal *fr);

// Fractals
int		mandelbrot(t_complex c);
int		julia(t_complex z, t_complex c);
void 	sierpinski(t_img *img, int x, int y, int size, int depth);
int		burning_ship(t_complex c);


// Utils:

// Color
int		get_color_1 (int i);
int		get_color_2 (int i);
int		get_color_3 (int i);

// Parse_args
t_fractal_type	parse_args(int count, char **argv, t_complex *julia_c);

// Atof
double ft_atof(const char *str);


#endif