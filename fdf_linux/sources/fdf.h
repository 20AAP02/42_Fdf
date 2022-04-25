#ifndef FDF_H
# define FDF_H

# define ESC 53

#include <mlx.h>
#include <math.h>
#include <libft.h>
#include <ft_printf.h> // ft_printf
#include <stdio.h> // printf
#include <stdlib.h> // abs
#include <fcntl.h> // open, close, read ...

typedef struct t_image
{
	void 	*img_ptr;
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	char	*buffer;
	int	width;
	int	height;
}		t_img;

typedef struct t_info
{
	void	*win;
	void	*mlx;
	t_img	*img;
}			t_inf;

typedef struct t_point
{
	int	x;
	int	y;
}		t_pt;

typedef struct t_3dPoint
{
	int	altitude;
	int	color;
}		t_3dPt;

typedef struct t_line
{
	t_pt	a;
	t_pt	b;
	int		colors[2];
}			t_ln;

typedef struct t_2dMap
{
	t_3dPt	**map;
	int		width;
	int 	height;
	int		range[2];
	int		pt_dist;
	int		img_Ycenter;
	int		img_Xcenter;
}			t_map;

void	ft_color_img_pixel(t_img *img, int pixel, int color, void *mlx);
void	ft_fill_img(void *mlx_ptr, t_img *img, int color);
void	ft_draw_line(void *mlx_ptr, t_img *img, t_ln line);
void	ft_draw_diamond(void *mlx_ptr, t_img *img, int color);
int		ft_close(int keycode, t_inf info);
int		ft_key_press(int keycode, t_inf info);
void	ft_setup_hooks(t_img *img, void *mlx, void *win);
int		ft_mouse_move(int keycode, t_inf info);
int		ft_mouse_press(int keycode, t_inf info);
int		ft_mouse_release(int keycode, t_inf info);
t_ln	ft_init_line(int x0, int y0, int x1, int y1);
int		ft_y_direction(t_pt a, t_pt b);
int		ft_x_direction(t_pt a, t_pt b);
t_map	*ft_read_fdf_file(char *file_name);
int		ft_n_lines_file(char *file_name);
void	ft_cpy_ln_to_intArr(t_3dPt **map, char *str, int i);
void	ft_free_map(t_map *map_inf);
void	ft_draw_map(t_map *map_inf);
int		ft_color_mixer(int range[2], int altitude);
int		ft_map_color_check(t_map *map_inf);
void	ft_altitude_range(t_map *map_inf);
void    ft_draw_H_lines(void *mlx, t_img *img, t_map *map_inf);
void    ft_draw_V_lines(void *mlx, t_img *img, t_map *map_inf);
int		ft_calculate_pt_dist(int map_width, int img_width, int map_height, int img_height);
int		ft_linear_gradient(int colors[2], int percent);
int 	ft_calc_2Pt_dist(t_pt pt1, t_pt pt2);
int		ft_getRed(int i);
int		ft_getGreen(int	i);
int		ft_getBlue(int	i);

#endif