#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
#include <X11/keysym.h>

# define WIDTH 1000
# define HEIGHT 800

# define ISOMETRIC_ANGLE 35.264

typedef struct s_color
{
	uint32_t	pos_colors[5];
	uint32_t	neg_colors[5];
	double		thresholds[5];
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	SIDEWAYS
}	t_projection;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	steps;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;
}	t_line;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_projection	projection_type;
	t_point			**map;
	int				colored;
	int				map_width;
	int				map_height;
	int				map_max;
	int				zoom;
	int				offset_x;
	int				offset_y;
	int				altitude;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	double			angle;
}	t_fdf;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;




// uint32_t	interpolate_color(uint32_t color1, uint32_t color2, double f);
// uint32_t	get_terrain_color(int z, int z_min, int z_max);
// int			handle_key(int key, t_fdf *data);
// int			handle_mouse(int button, int x, int y, t_fdf *data);
// void		draw_wireframe(t_fdf *data);
// void		draw_line(t_fdf *data, t_point p1, t_point p2);
// void		parse_map(char *filename, t_fdf *data);
// void		parse_dimensions(char *filename, t_fdf *data);
// t_point		project_point(t_point point, t_fdf *data);
// void		render(t_fdf *data);
// void		exit_error(char *message, int fd);
// int			close_window(t_fdf *data);
// int			min(int a, int b);
// int			max(int a, int b);
// double		degrees_to_radians(double degrees);
// int			hex_to_int(char *str);
// void		set_defaults(t_fdf *data);

#endif