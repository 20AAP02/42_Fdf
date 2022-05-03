/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:02:42 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/03 16:18:17 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WHITE 0xffffff
# define BLACK 0x000000
# define GREEN 0x275e00
# define BROWN 0x7a500b

# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <ft_printf.h> // ft_printf
# include <stdlib.h> // abs
# include <fcntl.h> // open, close, read ...

typedef struct t_image
{
	void	*img_ptr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		width;
	int		height;
}		t_img;

typedef struct t_point
{
	int	x;
	int	y;
}		t_pt;

typedef struct t_3dPoint
{
	int	altitude;
	int	alt2;
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
	int		height;
	int		range[2];
	int		pt_dist;
	int		comp_y;
	int		comp_x;
	int		zoom;
	int		color_check;
	int		scale;
	int		move_x;
	int		move_y;
	int		colors[2];
}			t_map;

typedef struct t_winInfo
{
	t_map	*map_inf;
	void	*mlx;
	void	*win;
	t_img	img;
}			t_winInf;

typedef struct t_info
{
	void	*win;
	void	*mlx;
	t_img	*img;
	t_map	*map_inf;
}			t_inf;

void	ft_color_img_pixel(t_img *img, int pixel, int color, void *mlx);
void	ft_fill_img(void *mlx_ptr, t_img *img, int color);
void	ft_draw_line(void *mlx_ptr, t_img *img, t_ln line);
int		ft_close(t_inf *info);
int		ft_key_press(int keycode, t_inf *info);
void	ft_setup_hooks(t_img *img, void *mlx, void *win, t_map *map_inf);
t_ln	ft_init_line(int x0, int y0, int x1, int y1);
int		ft_y_direction(t_pt a, t_pt b);
int		ft_x_direction(t_pt a, t_pt b);
t_map	*ft_read_fdf_file(char *file_name);
int		ft_n_lines_file(char *file_name);
char	*ft_cpy_ln_to_intarr(t_3dPt **map, char *str, int i);
void	ft_free_map(t_map *map_inf);
void	ft_color_map(t_map *map_inf);
int		ft_color_mixer(int range[2], int altitude, t_map *map_inf);
int		ft_map_color_check(t_map *map_inf);
void	ft_altitude_range(t_map *map_inf);
void	ft_draw_h_lines(void *mlx, t_img *img, t_map *map_inf);
void	ft_draw_v_lines(void *mlx, t_img *img, t_map *map_inf);
int		ft_linear_gradient(int colors[2], int percent);
int		ft_calc_2pt_dist(t_pt pt1, t_pt pt2);
float	ft_get_red(int i);
float	ft_get_green(int i);
float	ft_get_blue(int i);
int		ft_map_width(char *str);
int		iso(int x, int y, int z, int check);
int		ft_lowest_y(t_map *map_inf, int comp);
int		ft_lowest_x(t_map *map_inf, int comp);
int		ft_pt_compensate_x(t_map *map_inf);
int		ft_pt_compensate_y(t_map *map_inf);
int		ft_check_pt_dist(t_img *img, t_map *map_inf, int pt_dist);
int		ft_calc_pt_dist(t_img *img, t_map *map_inf);
void	ft_draw_d_lines(void *mlx, t_img *img, t_map *map_inf);
void	ft_draw_d2_lines(void *mlx, t_img *img, t_map *map_inf);
void	ft_scale_altitude(t_map *map_inf);
void	ft_draw_map(t_map *map_inf, void *mlx, void *win, t_img *img);
void	ft_win_init(t_winInf *info);
void	ft_reset_altitude(t_map *map_inf);
void	ft_esc(t_inf *info);
int		ft_zoom(int keycode, t_inf *info);

#endif